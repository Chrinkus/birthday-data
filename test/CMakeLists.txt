find_package(Catch2 REQUIRED)

file(GLOB TEST_SOURCES "./*.cpp")

add_executable(tests-birthday_data "${TEST_SOURCES}")
target_compile_features(tests-birthday_data PRIVATE cxx_std_14)
target_link_libraries(tests-birthday_data PRIVATE Catch2::Catch2)
target_link_libraries(tests-birthday_data PRIVATE birthday_data)

include(CTest)
include(Catch)
catch_discover_tests(tests-birthday_data)
