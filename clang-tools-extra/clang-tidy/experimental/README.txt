== Set up ==
* `git clone git@github.com:rknuus/llvm-project.git transformer-llvm`
* `mkdir -p build-transformer`
* `cd transformer-llvm`
* `git checkout spike/try-simple-transformer-tidy-check`
* `cd ../build-transformer`
* `cmake -DCMAKE_BUILD_TYPE=Release -DLLVM_USE_LINKER=gold -DLLVM_ENABLE_PROJECTS="clang;clang-tools-extra" -DLLVM_PARALLEL_LINK_JOBS=1 -G Ninja ../transformer-llvm/llvm`
* `ninja`
* `./bin/clang-tidy -list-checks -checks="-*,experimental"`
* `./bin/clang-tidy ../transformer-llvm/clang-tools-extra/test/clang-tidy/experimental.cpp -checks="-*,experimental" --`