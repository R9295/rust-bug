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
``` bash
RUSTFLAGS="-C panic=abort" ./build.sh

aarnav@plannine ~/a/asdf (master)> ./debug 
terminate called after throwing an instance of 'std::runtime_error'
  what():  C++ runtime_error from cpp_throw()
fish: Job 1, './debug' terminated by signal SIGABRT (Abort)

aarnav@plannine ~/a/asdf (master) [SIGABRT]> ./release
hello, world
```

## GDB
left is release  
right is debug

<img width="2048" height="538" alt="image" src="https://github.com/user-attachments/assets/a07642ae-8cf3-4ccd-bf95-ad3f4cba1fea" />


Question:
Why is this being optimized
``` rust
        std::panic::catch_unwind(core::panic::AssertUnwindSafe(|| {
            cpp_throw();
        }));
```
to  
```
cpp_throw();
```
