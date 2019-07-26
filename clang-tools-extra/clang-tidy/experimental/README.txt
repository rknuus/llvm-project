== Set up ==
* `git clone git@github.com:rknuus/llvm-project.git transformer-llvm`
* `mkdir -p build-transformer`
* `cd transformer-llvm`
* `git checkout spike/try-simple-transformer-tidy-check`
* `cd ../build-transformer`
* `cmake -DCMAKE_BUILD_TYPE=Debug -DLLVM_USE_LINKER=gold -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra" -DLLVM_PARALLEL_LINK_JOBS=1 -G Ninja ../llvm-project/llvm`

== Building & testing ==
* `ninja`
* `./bin/clang-tidy -list-checks -checks="-*,experimental"`
* `./bin/clang-tidy ../transformer-llvm/clang-tools-extra/test/clang-tidy/experimental.cpp -checks="-*,experimental-*" --`
* to build and run tests: `ninja check-clang-tools`, see http://clang.llvm.org/extra/clang-tidy/Contributing.html#testing-checks
* to show all commands during the ninja run: `ninja check-clang-tools -v`
* to show how lit runs a test: `cd /home/knausr/workspace/experiments/build-llvm/tools/clang/tools/extra/test && /usr/bin/python3.5 /home/knausr/workspace/experiments/build-llvm/./bin/llvm-lit -a -s /home/knausr/workspace/experiments/build-llvm/tools/clang/tools/extra/test`
* to run a single test: `knausr@knausr-stretch-dev:~/workspace/experiments/build-llvm/tools/clang/tools/extra/test$ ../unittests/clang-tidy/ClangTidyTests --gtest_filter="CppUnitToGTestMVPTest.*"`

== CppUnit to GoogleTest conversion ==
* removing CppUnit includes is easy enough, either manually or with the include-fixer
* build an MVP converting a CppUnit test class with one test method containing one test assertion to corresponding GoogleTest based code
* combine multiple transformations into a set of transformations
* turn into a stand-alone tool

== References
* testing guide: https://llvm.org/docs/TestingGuide.html
* lit documentation: https://llvm.org/docs/CommandGuide/lit.html
* CppUnit Cookbook: http://cppunit.sourceforge.net/doc/cvs/cppunit_cookbook.html