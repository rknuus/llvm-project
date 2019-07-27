//===--- CppUnitToGTestMVP.h - clang-tidy-------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_CPPUNITTOGTESTMVP_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_CPPUNITTOGTESTMVP_H

#include "../utils/TransformerClangTidyCheck.h"

namespace clang {
namespace tidy {
namespace experimental {

// copied from https://github.com/ymand/llvm-project/commits/transformer
class MultiTransformerTidy : public ClangTidyCheck  {
 public:
  MultiTransformerTidy(std::vector<tooling::RewriteRule> Rules, StringRef Name,
                       ClangTidyContext *Context);

  void registerMatchers(ast_matchers::MatchFinder *Finder) final;

  // `check` will never be called, since all of the matchers are registered to
  // child tidies.
  void check(const ast_matchers::MatchFinder::MatchResult &Result) final {}

 private:
  // Use a deque to ensure pointer stability of elements.
  std::deque<utils::TransformerClangTidyCheck> Tidies;
};

class CppUnitToGTestMVP : public MultiTransformerTidy {
 public:
  CppUnitToGTestMVP(StringRef Name, ClangTidyContext *Context)
      : MultiTransformerTidy(std::vector<tooling::RewriteRule>{replaceCppUnitClass()}, Name, Context) {}

 private:
  tooling::RewriteRule replaceCppUnitClass();
};

} // namespace experimental
} // namespace tidy
} // namespace clang

#endif  // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_CPPUNITTOGTESTMVP_H
