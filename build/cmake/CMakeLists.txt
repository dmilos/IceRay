cmake_minimum_required(VERSION 3.10)

project(IceRay)

option( ICERAY_SWITCH_DEBUG "Enable Debug" OFF )


add_subdirectory(memorylib)
add_subdirectory(core)
add_subdirectory(clib)
add_subdirectory(cdll)
#add_subdirectory(sizeof)
