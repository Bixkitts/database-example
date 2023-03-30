CMAKE_MINIMUM_REQUIRED(VERSION 3.3)
project(database-example 
    DESCRIPTION "An example of a C backend accessing a postgresql database"
    VERSION 0.1
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME})
add_subdirectory(src)
find_package(PostgreSQL REQUIRED)
add_subdirectory(lib/bb-net-lib)
# Link to the PostgreSQL C library
target_link_libraries(${PROJECT_NAME} ${PostgreSQL_LIBRARIES} bbnetlib)

# Include the PostgreSQL C library headers
target_include_directories(${PROJECT_NAME} PUBLIC ${PostgreSQL_INCLUDE_DIRS})

target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>:-O0;>)

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<CONFIG:Debug>: DEBUG>)

