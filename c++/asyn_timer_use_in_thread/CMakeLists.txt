cmake_minimum_required(VERSION 2.6)
project(main CXX)

include_directories(~/boost_1_55_0)
link_directories(~/boost_1_55_0/stage/lib)

add_executable(main main.cc)
target_link_libraries(main boost_date_time boost_system boost_thread)
