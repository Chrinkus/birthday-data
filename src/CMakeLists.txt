find_package(Boost 1.67 REQUIRED COMPONENTS date_time)

file(GLOB SOURCES "./*.cpp")

add_library(${CMAKE_PROJECT_NAME} STATIC "${SOURCES}")
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE sxy-database)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE Boost::date_time)
