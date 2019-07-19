//===--- ReplaceHeader.h - clang-tidy-------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_REPLACEHEADER_H
#define LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_REPLACEHEADER_H

#include "../utils/TransformerClangTidyCheck.h"

namespace clang {
namespace tidy {
namespace experimental {

class ReplaceHeader : public utils::TransformerClangTidyCheck {
 public:
  ReplaceHeader(StringRef Name, ClangTidyContext *Context)
      : utils::TransformerClangTidyCheck(replaceHeader(), Name, Context) {}

 private:
  tooling::RewriteRule replaceHeader();
};

} // namespace experimental
} // namespace tidy
} // namespace clang

#endif  // LLVM_CLANG_TOOLS_EXTRA_CLANG_TIDY_REPLACEHEADER_H
