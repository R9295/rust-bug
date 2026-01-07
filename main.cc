#include <exception>
#include <stdio.h>

extern "C" void call();

int main (int argc, char *argv[]) {
    try {
        call();
    }
    catch (const std::exception&) {
    }
    printf("hello, world\n");
    return 0;
}
