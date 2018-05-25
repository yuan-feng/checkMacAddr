cmake_minimum_required (VERSION 3.1)
project (checkMacAddr)

# System Requirement
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
# find_package( Threads REQUIRED)


# Executable 1
set( exe1 addSalt.exe ) 
add_executable(${exe1} addSalt.cpp)
# target_link_libraries(${exe1} Threads::Threads)


# Executable 2
set( exe2 main.exe ) 
add_executable(${exe2} main.cpp)
# target_link_libraries(${exe2} Threads::Threads)


enable_testing()
add_test(exe1 ${exe1})
add_test(exe2 ${exe2})

