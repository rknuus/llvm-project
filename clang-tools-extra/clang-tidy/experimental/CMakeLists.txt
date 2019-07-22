set(LLVM_LINK_COMPONENTS support)

add_clang_library(clangTidyExperimentalModule
  ExperimentalTidyModule.cpp
  CppUnitToGTestMVP.cpp

  LINK_LIBS
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangTidy
  clangTidyUtils
  clangTooling
  )
