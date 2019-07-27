//===---- CppUnitToGTestMVPTest.cpp - clang-tidy -----------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "../clang-tidy/experimental/CppUnitToGTestMVP.h"
#include "../clang-tidy/utils/TransformerClangTidyCheck.h"
#include "ClangTidyTest.h"
#include "gtest/gtest.h"

namespace clang {
namespace tidy {
namespace experimental {
namespace {

TEST(CppUnitToGTestMVPTest, DropCppUnitTestClassDefinition) {
  EXPECT_EQ(
      "namespace CppUnit { class TestCase {}; }\n;",
    test::runCheckOnCode<CppUnitToGTestMVP>(
      "namespace CppUnit { class TestCase {}; }\n"
      "class ComplexNumberTest : public CppUnit::TestCase {};"));
}

TEST(CppUnitToGTestMVPTest, ConvertTestClassMethodByGoogleTest) {
  EXPECT_EQ(
      "namespace CppUnit { class TestCase {}; }\n"
      "TEST(ComplexNumberTest, runTest) {};\n",
    test::runCheckOnCode<CppUnitToGTestMVP>(
      "namespace CppUnit { class TestCase {}; }\n"
      "class ComplexNumberTest : public CppUnit::TestCase {\n"
      " public:\n"
      "  void runTest() {}\n"
      "};\n"));
}

TEST(CppUnitToGTestMVPTest, DISABLED_AddGtestHeaderInclude) {
  EXPECT_EQ(
      "#include <gtest/gtest.h>\n",
    test::runCheckOnCode<CppUnitToGTestMVP>(
      ""));
}

} // namespace
} // namespace utils
} // namespace tidy
} // namespace clang
