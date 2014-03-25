cmake_minimum_required(VERSION 2.6)
project(hello_asio CXX)

include_directories(~/boost_1_55_0)
link_directories(~/boost_1_55_0/stage/lib)

add_executable(hello_asio hello_asio.cc)
target_link_libraries(hello_asio 
    boost_date_time
    boost_system
    )
