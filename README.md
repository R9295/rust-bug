# Prerequisites:
clang  
rust

# Description
The call stack is the following:  
C++ -> Rust -> C++  

# Reproduction

## unwinding panic
``` bash
RUSTFLAGS="-C panic=unwind" ./build.sh

aarnav@plannine ~/a/asdf (master)> ./debug
fatal runtime error: Rust cannot catch foreign exceptions, aborting
fish: Job 1, './debug' terminated by signal SIGABRT (Abort)

aarnav@plannine ~/a/asdf (master) [SIGABRT]> ./release 
hello, world
```
## aborting panic
```
RUSTFLAGS="-C panic=abort" ./build.sh

aarnav@plannine ~/a/asdf (master)> ./debug 
terminate called after throwing an instance of 'std::runtime_error'
  what():  C++ runtime_error from cpp_throw()
fish: Job 1, './debug' terminated by signal SIGABRT (Abort)

aarnav@plannine ~/a/asdf (master) [SIGABRT]> ./release
hello, world
```
