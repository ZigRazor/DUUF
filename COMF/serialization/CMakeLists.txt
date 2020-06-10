add_subdirectory(examples)

#specify the C++ Standard
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11" ${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_library(serialization SHARED Serialization.cpp)
#target_include_directories(master_election PUBLIC /home/matteo.botticci/SCM/prove_varie)
