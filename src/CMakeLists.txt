cmake_minimum_required(VERSION 3.5)
project("skyLox")

set (project "skyLox")

add_executable(${project}
    main.cxx
)

find_package(fmt CONFIG REQUIRED)

target_link_libraries(${project} PRIVATE 
    fmt::fmt     
)

target_compile_options(${project} PRIVATE -Wall -Wpedantic)