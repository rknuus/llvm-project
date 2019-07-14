//===---------- DemoInsertBefore.h - clang-tidy ----------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_DEMOINSERTBEFORE_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_DEMOINSERTBEFORE_H

#include "../ClangTidy.h"
#include "../utils/TransformerTidy.h"

namespace clang {
namespace tidy {
namespace experimental {

class DemoInsertBefore : public clang::tidy::utils::TransformerTidy {
 public:
  DemoInsertBefore(StringRef Name, ClangTidyContext *Context);

 private:
  tooling::RewriteRule strlenSizeAnyTypeRule();
};

} // namespace experimental
} // namespace tidy
} // namespace clang

#endif  // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_DEMOINSERTBEFORE_H
