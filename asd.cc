#include <stdexcept>

extern "C" {
    // Simple function callable from Rust that throws.
    void cpp_throw() {
        throw std::runtime_error("C++ runtime_error from cpp_throw()");
    }
}
