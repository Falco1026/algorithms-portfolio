cmake_minimum_required(VERSION 4.0)
project(Question_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Question_1 main.cpp
        "Aditional Library/QueueFunctions.cpp"
        "Aditional Library/QueueFunctions.h"
        "Aditional Library/Queue.h"
        "Aditional Library/QueueElement.h"
        "Aditional Library/QueueNode.h")
