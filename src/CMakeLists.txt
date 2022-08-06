cmake_minimum_required(VERSION 3.5)

# must be before project
set(CMAKE_TOOLCHAIN_FILE "~/vcpkg/scripts/buildsystems/vcpkg.cmake")

set (project "skyLox")

add_executable(${project}
    main.cxx
)