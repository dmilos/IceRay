cmake_minimum_required(VERSION 3.10)

#primary variables
set( PROJECT_NAME_BARE            "IceRay" ) #!< TODO Take this from INI
set( PROJECT_NAME_DECOR_POSTFIX      "Lib" )
set( ICERAY_PROJECT_VERSION      "1.0.0.0" )#!< TODO Take this from INI

set( ICERAY_PROJECT_NAME_FULL                  ${PROJECT_NAME_BARE}${PROJECT_NAME_DECOR_POSTFIX}-${ICERAY_PROJECT_VERSION} )
set( ICERAY_CORE_LIBRARY_PROJECT_NAME_FULL     ${ICERAY_PROJECT_NAME_FULL} CACHE INTERNAL "" )

project( ${ICERAY_PROJECT_NAME_FULL} )


set( directory__root "${CMAKE_CURRENT_SOURCE_DIR}/../../.." )

set( directory_include          "${directory__root}/src" )
set( directory_source           "${directory__root}/src" )
set( directory_submodule__root  "${directory__root}/submodule" )
set( directory_temp             "${directory__root}/temp" )
set( directory_obj    "${directory_temp}/${directory_output}/obj" )
set( directory_lib    "${directory_temp}/${directory_output}/lib" )
set( directory_pdb    "${directory_temp}/${directory_output}/pdb" )
set( directory_dll    "${directory_temp}/${directory_output}/dll" )

#Internal variables
set( hpp_file_list    "./hpp.lst.txt" )
#set( cpp_file_list    "./cpp.lst.txt" )
set( cpp_file_list    "./cpp-expand.lst.txt" )

#Processing
set( SOURCE_HPP "" )
#file( STRINGS ${hpp_file_list} FILE_LIST )
file( GLOB_RECURSE SOURCE_HPP "${directory_source}/IceRay/main/interface/c/*.hpp")
source_group( TREE "${directory_include}/" PREFIX "Header Files\\${PROJECT_NAME_BARE}" FILES ${SOURCE_HPP} )

set( SOURCE_CPP "" )
file( STRINGS ${cpp_file_list} FILE_LIST )
foreach(file_item IN LISTS FILE_LIST )
  list( APPEND SOURCE_CPP "${directory_source}/${file_item}")
endforeach(file_item)

source_group( TREE "${directory_source}" FILES ${SOURCE_CPP} )

include_directories( "${directory_source}")
include_directories( "${directory_submodule__root}/color/src")
include_directories( "${directory_submodule__root}/container/src")
include_directories( "${directory_submodule__root}/math/src")
include_directories( "${directory_submodule__root}/memory/src")
include_directories( "${directory_submodule__root}/PNM/src")
include_directories( "${directory_submodule__root}/TopLog/src")

add_library( ${ICERAY_PROJECT_NAME_FULL} STATIC ${SOURCE_CPP} ${SOURCE_HPP}  )


set_property( TARGET ${ICERAY_PROJECT_NAME_FULL} PROPERTY POSITION_INDEPENDENT_CODE ON )
set_property( TARGET ${ICERAY_PROJECT_NAME_FULL} PROPERTY CXX_VISIBILITY_PRESET hidden )

if( UNIX )
    target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -frtti )
    target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -fexceptions )
    target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -Wno-unused-local-typedefs )
    target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -Wno-unused-variable )
    #target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -Wmaybe-uninitialized )

    if( ICERAY_SWITCH_DEBUG )
        #target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -fsanitize=address )
        #target_link_options(    ${ICERAY_PROJECT_NAME_FULL} PRIVATE -fsanitize=address )
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
        target_compile_definitions( ${ICERAY_PROJECT_NAME_FULL} PRIVATE DEBUG )
        target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -g )
        target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -rdynamic )
        target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -ggdb )
        target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -g3 )
        target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -O0 )
        set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DDEBUG -g -rdynamic -ggdb -g3 -O0")
    endif()
endif()
if( MSVC )
    target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE /wd4624 )
    #target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE /Zp1    )
    #target_compile_definitions( ${ICERAY_PROJECT_NAME_FULL} PRIVATE  $<$<CONFIG:DEBUG>:_SECURE_SCL> )
    #target_compile_definitions( ${ICERAY_PROJECT_NAME_FULL} PRIVATE  $<$<CONFIG:DEBUG>:_ITERATOR_DEBUG_LEVEL=2> )
    #target_compile_definitions( ${ICERAY_PROJECT_NAME_FULL} PRIVATE  $<$<CONFIG:DEBUG>:_HAS_ITERATOR_DEBUGGING> )
endif()

target_include_directories(  ${ICERAY_PROJECT_NAME_FULL} PRIVATE "${directory_include}")

target_link_libraries(  ${ICERAY_PROJECT_NAME_FULL} PRIVATE ${ICERAY_CORE_CORE_PROJECT_NAME_FULL} )
add_dependencies(       ${ICERAY_PROJECT_NAME_FULL}         ${ICERAY_CORE_CORE_PROJECT_NAME_FULL} )


message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_C_FLAGS: ${CMAKE_CXX_FLAGS}")

