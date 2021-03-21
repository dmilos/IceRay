cmake_minimum_required(VERSION 2.8)

#primary variables
set( name_bare       "IceRay" ) #!< TODO Take this from INI
project( ${name_bare} )

set( directory__root "${CMAKE_CURRENT_SOURCE_DIR}/../../.." )

set( directory_source          "${directory__root}/src" )
set( directory_submodule__root "${directory__root}/submodule" )
set( directory_temp            "${directory__root}/temp" )

set( project_version "1.0.0.0" )#!< TODO Take this from INI
set( name_full ${name_bare}Lib-${project_version} )


#secondary variables
set( directory_output  ${name_bare}-${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION} )

set( directory_obj    "${directory_temp}/${directory_output}/obj" )
set( directory_lib    "${directory_temp}/${directory_output}/lib" )
set( directory_pdb    "${directory_temp}/${directory_output}/pdb" )
set( directory_dll    "${directory_temp}/${directory_output}/dll" )

#Internal variables
set( hpp_file_list    "./hpp.lst.txt" )
set( cpp_file_list    "./cpp.lst.txt" )

#Processing

file( GLOB_RECURSE SOURCE_HPP "${directory_source}/*IceRay/.hpp")

#file( STRINGS ${hpp_file_list} FILE_LIST )
#message("${FILE_LIST}")
#foreach(file_item IN LISTS FILE_LIST )
#  message("${file_item}")
#  list( APPEND hpp_files "${directory_source}/IceRay/${file_item}")
#endforeach(file_item)
source_group( TREE "${directory_source}" FILES ${SOURCE_HPP} )


file( STRINGS ${cpp_file_list} FILE_LIST )
foreach(file_item IN LISTS FILE_LIST )
  list( APPEND SOURCE_CPP "${directory_source}/IceRay/${file_item}")
endforeach(file_item)

source_group( TREE "${directory_source}" FILES ${SOURCE_CPP} )

include_directories( "${directory_source}")

include_directories( "${directory_submodule__root}/color/src")
include_directories( "${directory_submodule__root}/container/src")
include_directories( "${directory_submodule__root}/math/src")
include_directories( "${directory_submodule__root}/memory/src")
include_directories( "${directory_submodule__root}/PNM/src")
include_directories( "${directory_submodule__root}/PNM/src")

include_directories( "z:/work/code/cpp/prj/github/math/work/src"  )
include_directories( "z:/work/code/cpp/prj/github/color/work/src" )
include_directories( "z:/work/code/cpp/prj/github/PNM/src"        )

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
endif()
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /wd4624")
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${directory_obj}/arc)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${directory_lib}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${directory_dll}/bin)

add_library(${name_full} STATIC ${SOURCE_CPP} ${SOURCE_HPP})

