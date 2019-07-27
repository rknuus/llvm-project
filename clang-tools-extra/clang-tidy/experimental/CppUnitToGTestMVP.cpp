//===--- CppUnitToGTestMVP.cpp - clang-tidy-----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "CppUnitToGTestMVP.h"
#include "clang/Tooling/Refactoring/Stencil.h"

namespace clang {
namespace tidy {
namespace experimental {

using namespace clang;
using namespace tooling;
using namespace ast_matchers;

MultiTransformerTidy::MultiTransformerTidy(
    std::vector<tooling::RewriteRule> Rules, StringRef Name,
    ClangTidyContext *Context)
    : ClangTidyCheck(Name, Context) {
  for (auto &R : Rules) {
    Tidies.emplace_back(std::move(R), Name, Context);
  }
}

void MultiTransformerTidy::registerMatchers(ast_matchers::MatchFinder *Finder) {
  for (auto &T : Tidies) {
    T.registerMatchers(Finder);
  }
}

tooling::RewriteRule CppUnitToGTestMVP::replaceCppUnitClass() {
  StringRef Testclass = "testclass";
  // TODO(KNR): not only remove definitions, also remove declarations
  auto R = makeRule(cxxRecordDecl(isDerivedFrom(hasName("TestCase")), hasDefinition()).bind(Testclass),
                    remove(node(Testclass)),  // TODO(KNR): how to remove semicolon, as well?
                    text("No need for test classes in GTest world"));
  // TODO(KNR): apparently includes cannot be added stand-alone, so need to find a good place for it
  // addInclude(R, "gtest/gtest.h", IncludeFormat::Angled);  // TODO(KNR): another crash...
  return R;
}

tooling::RewriteRule CppUnitToGTestMVP::convertTestMethod() {
  StringRef Testclass = "testclass";
  StringRef Testmethod = "testmethod";
  auto R = makeRule(cxxMethodDecl(ofClass(cxxRecordDecl(isDerivedFrom(hasName("TestCase"))).bind(Testclass))).bind(Testmethod),
                    insertAfter(node(Testclass), stencil::cat("TEST(", name(Testclass), ", ", name(Testmethod), ") {}")),
                    text("Convert test method"));
  return R;
}

// tooling::RewriteRule CppUnitToGTestMVP::addGtestHeader() {
//   auto R = makeRule();
//   addInclude(R, "gtest/gtest.h", IncludeFormat::Angled);
//   return R;
// }

} // namespace experimental
} // namespace tidy
} // namespace clang
