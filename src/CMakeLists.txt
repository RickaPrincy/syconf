set(EXECUTABLE_NAME "sync-config")

add_executable(${EXECUTABLE_NAME} main.cpp)

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
