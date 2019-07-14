// RUN: clang-tidy %s -checks='-*,experimental' -- | FileCheck %s

#include <cstring>
#include <string>

int f() {
  std::string s{"Hello World"};
  return strlen(s.c_str());
}
// CHECK: warning: use size() method directly on object [experimental-strlen-to-size]
