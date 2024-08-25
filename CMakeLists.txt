cmake_minimum_required (VERSION 3.8)
project (ConsoleHelper)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_DEBUG_POSTFIX "-d")

set(CONSOLE_LIB_SRC "")
if (WIN32)
	set(CONSOLE_LIB_SRC ${CONSOLE_LIB_SRC}  src/ConsoleController.cpp)
endif()

include_directories("Include")

add_library(ConsoleHelper STATIC ${CONSOLE_LIB_SRC})

add_executable(ConsoleTest "Test/main.cpp")
target_link_libraries(ConsoleTest ConsoleHelper)