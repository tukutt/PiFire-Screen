cmake_minimum_required(VERSION 3.0.0)
project(play VERSION 0.1.0)



add_executable(play main.cpp)





add_custom_command(TARGET play
    POST_BUILD
    COMMAND /home/parker/projects/CM4/LvglTemplate_CM4/copy.sh
)