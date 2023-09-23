
## At a glance ##

To build the pass, you will need a clang+llvm,
which can be built from source or downloaded.


### Building clang+llvm from source

See https://llvm.org/docs/GettingStarted.html for
a general introduction.

Here are the commands:

```
git clone https://github.com/llvm/llvm-project.git
cd llvm-project
mkdir build
cmake -S  ../llvm-project/llvm -B build \
-DLLVM_ENABLE_PROJECTS="bolt;clang;clang-tools-extra;flang;libc;libclc;lld;lldb;mlir;openmp;polly;pstl" -DLLVM_ENABLE_RUNTIMES="libcxx;libcxxabi;libunwind;compiler-rt"

ninja -j(nproc)

```

### Downloading a prebuilt llvm+clang

If you want to use the ubuntu supported version,
just run `apt get install`.

If you want to use a more recent version,
setup apt sources following instrctions from
https://apt.llvm.org/


## Building a trivial LLVM pass ##


After getting clang+llvm, set the LLVM_HOME env variable.

To build the skeleton LLVM pass found in `skeleton` folder:
```bash
$ export LLVM_HOME=/usr/lib/llvm-15
$ cd llvm-pass-tutorial
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Now the easiest way to run the skeleton pass is to use Clang:
```bash
$ clang-15 -Xclang -load -Xclang build/skeleton/libSkeletonPass.* something.cpp
```
Note that Clang is the compiler front-end of the LLVM project.
It can be installed separately in binary form.

### Further resources
This tutorial is based on the following resources

- Adrian Sampson's blog entry "LLVM for Grad Students" ([link](http://adriansampson.net/blog/llvm.html))
- LLVM documentation: Writing an LLVM pass ([link](http://llvm.org/docs/WritingAnLLVMPass.html))
- LLVM documentation: Building LLVM with CMake ([link](http://llvm.org/docs/CMake.html#cmake-out-of-source-pass))
