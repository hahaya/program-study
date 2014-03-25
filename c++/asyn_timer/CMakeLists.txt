cmake_minimum_required(VERSION 2.6)
project(asyn_timer CXX)

include_directories(~/boost_1_55_0)
link_directories(~/boost_1_55_0/stage/lib)

add_executable(asyn_timer asyn_timer.cc)
target_link_libraries(asyn_timer boost_date_time boost_system)
