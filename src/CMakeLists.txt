file(GLOB SOURCES "./*.cpp")

add_library(birthday_data "${SOURCES}")
target_compile_features(birthday_data PRIVATE cxx_std_17)
target_link_libraries(birthday_data PRIVATE sxy_database)
