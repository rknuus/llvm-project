//===---------- DemoStrlenToSize.cpp - clang-tidy ----------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "DemoStrlenToSize.h"
#include "clang/ASTMatchers/ASTMatchers.h"

namespace clang {
namespace tidy {
namespace experimental {

DemoStrlenToSize::DemoStrlenToSize(StringRef Name, ClangTidyContext *Context)
    : TransformerTidy(strlenSizeAnyTypeRule(), Name, Context) {}

// (any s){ strlen($s.c_str()) } => { $s.size() }
tooling::RewriteRule DemoStrlenToSize::strlenSizeAnyTypeRule() {
  using namespace tooling;
  using namespace ::clang::ast_matchers;
  ExprId S;
  return makeRule(
      callExpr(callee(functionDecl(hasName("strlen"))),
               hasArgument(0, cxxMemberCallExpr(
                                  on(S.bind()),
                                  callee(cxxMethodDecl(hasName("c_str")))))),
      Stencil::cat(S, ".size()"),
      "use size() method directly on object");
}

} // namespace experimental
} // namespace tidy
} // namespace clang
