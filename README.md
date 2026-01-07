# Prerequisites:
clang  
rust

``` bash
./build.sh
aarnav@plannine ~/a/asdf (master)> ./debug 
terminate called after throwing an instance of 'std::runtime_error'
  what():  C++ runtime_error from cpp_throw()
fish: Job 1, './debug' terminated by signal SIGABRT (Abort)
aarnav@plannine ~/a/asdf (master) [SIGABRT]> ./release 
hello, world
aarnav@plannine ~/a/asdf (master)> 
```
