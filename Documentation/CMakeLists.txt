cmake_minimum_required(VERSION 3.0)
project(MRT)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/_build)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Classes)

set(cpp ${CMAKE_CURRENT_SOURCE_DIR}/Classes)
set(MAIN cpp/Main.cpp)
set(SOURCE_LIB ${cpp}/Crash.cpp ${cpp}/FunctionForMain.cpp ${cpp}/Car.cpp ${cpp}/Map.cpp ${cpp}/TrafficLight.cpp ${cpp}/RoadSign.cpp ${cpp}/View.cpp ${cpp}/UnitTest.cpp)

add_library(lib STATIC ${SOURCE_LIB})

add_executable(main ${MAIN}) 

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/SFML/cmake/Modules/FindSFML.cmake")
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	add_library(sfml STATIC ${SFML_LIBRARIES})
	target_link_libraries(main sfml lib)
endif()