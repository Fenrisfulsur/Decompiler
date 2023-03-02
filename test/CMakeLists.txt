cmake_minimum_required(VERSION 3.16)
project(DecompilerTest)

set(CMAKE_CXX_STANDARD 20)


add_executable(Decompileri8042Test
        source/main_i8042.cpp
)

add_executable(DecompilerARMTest
        source/main_arm.cpp
)

target_link_libraries(Decompileri8042Test PUBLIC DecompilerLib)
target_link_libraries(DecompilerARMTest PUBLIC DecompilerLib)

