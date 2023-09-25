add_library(ut_rtems_impl_stubs
    src/rtems-os-impl-binsem-stubs.c
)

target_link_libraries(ut_rtems_impl_stubs PUBLIC 
    ut_osapi_stub_headers
)
