cmake_minimum_required(VERSION 3.10)

#primary variables
set( PROJECT_NAME_BARE            "Memory" ) #!< TODO Take this from INI
set( PROJECT_NAME_DECOR_POSTFIX      "Lib" )
set( ICERAY_PROJECT_VERSION      "1.0.0.0" )#!< TODO Take this from INI

set( ICERAY_PROJECT_NAME_FULL                  ${PROJECT_NAME_BARE}${PROJECT_NAME_DECOR_POSTFIX}-${ICERAY_PROJECT_VERSION} )
set( ICERAY_SUBMODULE_MEMORY_PROJECT_NAME_FULL ${ICERAY_PROJECT_NAME_FULL} CACHE INTERNAL "" )

project( ${ICERAY_PROJECT_NAME_FULL} )

set( directory__root  "${CMAKE_CURRENT_SOURCE_DIR}/../../.." )

#secondary variables
set( directory_source          "${directory__root}/submodule/memory/src" )
set( directory_temp            "${directory__root}/temp" )
set( directory_include         "${directory_source}/memory" )

set( directory_output  ${PROJECT_NAME_BARE}-${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION} )

#tercial variables
set( directory_obj    "${directory_temp}/${directory_output}/obj" )
set( directory_lib    "${directory_temp}/${directory_output}/lib" )
set( directory_pdb    "${directory_temp}/${directory_output}/pdb" )
set( directory_dll    "${directory_temp}/${directory_output}/dll" )

#Internal variables
set( hpp_file_list    "./hpp.lst.txt" )
set( cpp_file_list    "./cpp.lst.txt" )

#Processing

#file( GLOB_RECURSE SOURCE_HPP "${directory_source}/*.hpp")

file( STRINGS ${hpp_file_list} FILE_LIST )
foreach(file_item IN LISTS FILE_LIST )
  list( APPEND SOURCE_HPP "${directory_source}/${file_item}")
endforeach(file_item)

source_group( TREE "${directory_include}/" PREFIX "Header Files\\${PROJECT_NAME_BARE}" FILES ${SOURCE_HPP} )


file( STRINGS ${cpp_file_list} FILE_LIST )
foreach(file_item IN LISTS FILE_LIST )
  list( APPEND SOURCE_CPP "${directory_source}/${file_item}")
endforeach(file_item)

source_group( TREE "${directory_source}" FILES ${SOURCE_CPP} )

include_directories( "${directory_source}")


if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
endif()
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /wd4624")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${directory_obj}/arc)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${directory_lib}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${directory_dll}/bin)


add_library(${ICERAY_PROJECT_NAME_FULL} STATIC ${SOURCE_CPP} ${SOURCE_HPP})


set_property( TARGET ${ICERAY_PROJECT_NAME_FULL} PROPERTY POSITION_INDEPENDENT_CODE ON )


if( UNIX )
    target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -frtti )
    target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -fexceptions )
    target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -Wno-unused-local-typedefs )
    target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -Wno-unused-variable )
    if( ICERAY_SWITCH_DEBUG )
        #target_compile_options( ${ICERAY_PROJECT_NAME_FULL} PRIVATE -fsanitize=address )
        #target_link_options(    ${ICERAY_PROJECT_NAME_FULL} PRIVATE -fsanitize=address )

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
    target_compile_options(${ICERAY_PROJECT_NAME_FULL} PRIVATE /Zp1)

    target_compile_definitions( ${ICERAY_PROJECT_NAME_FULL} PRIVATE  $<$<CONFIG:DEBUG>:_SECURE_SCL> )
    target_compile_definitions( ${ICERAY_PROJECT_NAME_FULL} PRIVATE  $<$<CONFIG:DEBUG>:_ITERATOR_DEBUG_LEVEL=2> )
    target_compile_definitions( ${ICERAY_PROJECT_NAME_FULL} PRIVATE  $<$<CONFIG:DEBUG>:_HAS_ITERATOR_DEBUGGING> )
endif()

message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_C_FLAGS: ${CMAKE_CXX_FLAGS}")


