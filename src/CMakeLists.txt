set(EXECUTABLE_NAME "syconf")

add_executable(${EXECUTABLE_NAME} 
    main.cpp
    read_config.cpp
    reload.cpp
)

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
target_include_directories(${EXECUTABLE_NAME} 
    PUBLIC 
    ${SYNC_CONFIG_SOURCE_DIR}/include
)
