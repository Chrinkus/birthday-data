find_package(Catch2 REQUIRED)

file(GLOB TEST_SOURCES "./*.cpp")

add_executable(tests-birthday-data EXCLUDE_FROM_ALL "${TEST_SOURCES}")
target_compile_features(tests-birthday-data PRIVATE cxx_std_14)
target_link_libraries(tests-birthday-data PUBLIC Catch2::Catch2)
target_link_libraries(tests-birthday-data PRIVATE ${CMAKE_PROJECT_NAME})

include(CTest)
include(Catch)
catch_discover_tests(tests-birthday-data)
