# CMake snippet for OSAL unit tests
#
# This is a set of functional tests for certain OSAL subsystems,
# focused on API responses and implemented as black-box tests (i.e.
# linked to normal OSAL, only using public API).
#

enable_testing()

include_directories(inc)

add_subdirectory(osloader-test)

