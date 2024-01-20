set(EXECUTABLE_NAME "sconf")

add_executable(${EXECUTABLE_NAME} main.cpp)

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
target_include_directories(${EXECUTABLE_NAME} 
    PUBLIC 
    ${SYNC_CONFIG_SOURCE_DIR}/include
)
