cmake_minimum_required(VERSION 2.6)
project(sync_timer CXX)

include_directories(~/boost_1_55_0)
link_directories(~/boost_1_55_0/stage/lib)

add_executable(sync_timer sync_timer.cc)
target_link_libraries(sync_timer 
    boost_date_time
    boost_system
    )
