unsafe extern "C" {
    fn cpp_throw();
}
#[unsafe(no_mangle)]
extern "C" fn call() {
    unsafe {
        std::panic::catch_unwind(core::panic::AssertUnwindSafe(|| {
            cpp_throw();
        }));
    }
}
