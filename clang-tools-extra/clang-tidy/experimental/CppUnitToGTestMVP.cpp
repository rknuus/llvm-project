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

tooling::RewriteRule CppUnitToGTestMVP::replaceCppUnitClass() {
  return tooling::RewriteRule{};
}

} // namespace experimental
} // namespace tidy
} // namespace clang
