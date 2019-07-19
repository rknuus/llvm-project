//===--- ExperimentalTidyModule.cpp - clang-tidy---------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "../ClangTidy.h"
#include "../ClangTidyModule.h"
#include "../ClangTidyModuleRegistry.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace experimental {

/// This module is for Experimental-specific checks.
class ExperimentalModule : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
  }
};

// Register the ExperimentalTidyModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<ExperimentalModule>
    X("experimental-module", "Adds experimental checks.");
} // namespace experimental

// This anchor is used to force the linker to link in the generated object file
// and thus register the ExperimentalModule.
volatile int ExperimentalModuleAnchorSource = 0;

} // namespace tidy
} // namespace clang
