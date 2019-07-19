//===---- ReplaceHeaderTest.cpp - clang-tidy -----------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "../clang-tidy/experimental/ReplaceHeader.h"
#include "../clang-tidy/utils/TransformerClangTidyCheck.h"
#include "ClangTidyTest.h"
#include "gtest/gtest.h"

namespace clang {
namespace tidy {
namespace experimental {
namespace {

TEST(ReplaceHeaderTest, Foo) {
  EXPECT_EQ("", test::runCheckOnCode<ReplaceHeader>(""));
}

} // namespace
} // namespace utils
} // namespace tidy
} // namespace clang
