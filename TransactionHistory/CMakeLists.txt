cmake_minimum_required(VERSION 3.21)
project(TransactionHistory)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TransactionHistory
        Customer.h
        cmake-build-debug/customers.txt
        main.cpp)
