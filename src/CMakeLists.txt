add_executable(lab5 Lab5.cpp
        ../include/mockos/ChmodProxy.h
        ../include/mockos/ChmodCommand.h)
target_link_libraries(lab5 mockos)
