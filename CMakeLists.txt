cmake_minimum_required(VERSION 2.8)

#set the project name
#project(MasterElection VERSION 1.0)
project(DUUF)

#specify the C++ Standard
#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11" ${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES /usr/local/lib ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

set(PROJECT_DIR ${PROJECT_SOURCE_DIR})
set(COMF_DIR ${PROJECT_DIR}/COMF)

option(CODE_COVERAGE "Enable coverage reporting" OFF)
if(CODE_COVERAGE)
	add_compile_options(
		-O0  #no optimization
		-g   #generate debug info
		--coverage #set coverage flag
		-fprofile-arcs
		-ftest-coverage
	)
	link_libraries(
		"gcov"
		"-fprofile-arcs"
		"--coverage"
	)
	
endif(CODE_COVERAGE)	

add_subdirectory(COMF)
option(TEST_SET "Enable test compilation" OFF)
if(TEST_SET)
	add_subdirectory(TESTS)
endif(TEST_SET)

#add the executable
#add_executable(MasterElection main.cpp)

#target_link_libraries(MasterElection udp)


#add_library(udp SHARED udp_base.cpp udp_client.cpp udp_server.cpp)
#target_include_directories(MasterElection PUBLIC "${COMF_DIR}" "${COMF_DIR}/udp_client_server")
