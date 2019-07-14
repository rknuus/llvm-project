set(LLVM_LINK_COMPONENTS support)

add_clang_library(clangTidyExperimentalModule
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
