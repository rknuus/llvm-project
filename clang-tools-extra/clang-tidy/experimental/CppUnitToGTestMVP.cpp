//===--- CppUnitToGTestMVP.cpp - clang-tidy-----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "CppUnitToGTestMVP.h"

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
  StringRef Testcase = "testcase";
  auto R = makeRule(cxxRecordDecl(isDerivedFrom(hasName("TestCase")), hasDefinition()).bind(Testcase),
                    remove(node(Testcase)),  // TODO(KNR): how to remove semicolon, as well?
                    text("No need for test classes in GTest world"));
  return R;
}

} // namespace experimental
} // namespace tidy
} // namespace clang
