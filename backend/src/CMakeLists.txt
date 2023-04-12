target_sources(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/communication.c
    ${CMAKE_CURRENT_SOURCE_DIR}/communication.h
    ${CMAKE_CURRENT_SOURCE_DIR}/dbCommands.c
    ${CMAKE_CURRENT_SOURCE_DIR}/dbCommands.h
    ${CMAKE_CURRENT_SOURCE_DIR}/dbConnection.h
    ${CMAKE_CURRENT_SOURCE_DIR}/defines.h
)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
