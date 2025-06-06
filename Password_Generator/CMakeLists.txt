cmake_minimum_required(VERSION 3.31)
project(Password_Generator C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(Password_Generator main.c)

set(RUN_SCRIPT ${CMAKE_SOURCE_DIR}/run.sh)

if(NOT EXISTS ${RUN_SCRIPT})
    file(WRITE ${RUN_SCRIPT}
            "#!/bin/bash\n"
            "echo \"Запуск Password_Generator...\"\n"
            "./Password_Generator\n"
    )
endif()

file(CHMOD ${RUN_SCRIPT}
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
        GROUP_READ GROUP_EXECUTE
        WORLD_READ WORLD_EXECUTE)
