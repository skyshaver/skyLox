cmake_minimum_required(VERSION 3.5)

project("skyLox")

set (project_name "skyLox")
set(include_directories("../include"))

add_executable(${project_name}
    main.cxx
    SkyLox.cxx
    Scanner.cxx
    Token.cxx
)

find_package(fmt CONFIG REQUIRED)

target_include_directories(${project_name} PRIVATE ${include_directories})

target_link_libraries(${project_name} PRIVATE 
    fmt::fmt     
)
target_compile_features(${project_name} PUBLIC cxx_std_20)
target_compile_options(${project_name} PRIVATE -Wall -Wpedantic)