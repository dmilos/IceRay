cmake_minimum_required(VERSION 2.8)

project(testCmake)

file( GLOB_RECURSE SOURCE_HPP "${CMAKE_SOURCE_DIR}/../../../src/main/interface/python/*.hpp")


set( hpp_file_list    "./hpp.lst.txt" )
set( cpp_file_list    "./cpp.lst.txt" )

file( STRINGS ${cpp_file_list} FILE_LIST )
foreach(file_item IN LISTS FILE_LIST )
  list( APPEND SOURCE_CPP "${directory_source}/IceRay/${file_item}")
endforeach(file_item)
 
source_group( TREE "${CMAKE_SOURCE_DIR}/../../../src/" FILES ${SOURCE_HPP} )
source_group( TREE "${CMAKE_SOURCE_DIR}/../../../src/" FILES ${SOURCE_CPP} ) 

add_executable( testCmake ${SOURCE} )

