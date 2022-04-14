cmake_minimum_required(VERSION 2.8)

set( PROJECT_NAME "IceRayLib" )
set( PROJECT_LIB "IceRayLib" )


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
set( cpp_file_list    "./cpp.lst.txt" )

#Processing

file( GLOB_RECURSE SOURCE_HPP "${directory_source}/*IceRay/.hpp")
source_group( TREE "${directory_include}/" PREFIX "Header Files\\${PROJECT_NAME}" FILES ${SOURCE_HPP} )

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

add_library( ${PROJECT_LIB} ${SOURCE_CPP} ${SOURCE_HPP}  )

target_include_directories(  ${PROJECT_LIB} PRIVATE "${directory_include}")

target_link_libraries(${PROJECT_LIB} PRIVATE IceRayCoreLib )
add_dependencies( ${PROJECT_LIB} IceRayCoreLib )
