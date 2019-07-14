set(LLVM_LINK_COMPONENTS support)

add_clang_library(clangTidyExperimentalModule
  DemoInsertBefore.cpp
  DemoStrlenToSize.cpp
  ExperimentalTidyModule.cpp

  LINK_LIBS
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangTidy
  clangTidyUtils
  clangTooling
  )
