cmake_minimum_required(VERSION 2.8)


set( PROJECT_NAME_BARE "IceRay" ) #!< TODO Take this from INI
set( PROJECT_VERSION   "1.0.0.0" )#!< TODO Take this from INI

set( PROJECT_DLL_NAME_FULL ${PROJECT_NAME_BARE}DLL-${PROJECT_VERSION} )
set( PROJECT_DLL           ${PROJECT_DLL_NAME_FULL} )

project( ${PROJECT_DLL_NAME_FULL} )


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
source_group( TREE "${directory_include}/" PREFIX "Header Files\\${PROJECT_NAME_BARE}" FILES ${SOURCE_HPP} )

file( STRINGS ${cpp_file_list} FILE_LIST )
foreach(file_item IN LISTS FILE_LIST )
  list( APPEND SOURCE_CPP "${directory_source}/${file_item}")
endforeach(file_item)

source_group( TREE "${directory_source}" FILES ${SOURCE_CPP} )

include_directories( "${directory_submodule__root}/color/src")
include_directories( "${directory_submodule__root}/container/src")
include_directories( "${directory_submodule__root}/math/src")
include_directories( "${directory_submodule__root}/memory/src")
include_directories( "${directory_submodule__root}/PNM/src")

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
endif()
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /wd4624")
endif()


set( COMMAND_ARGUMENTS "0 1" )
set( COMMAND_CMD32_DEBUG    "$(prg_python38)" )
set( COMMAND_ARG32_DEBUG    ${directory__root}"/example/test2/list.py" )
set( COMMAND_CMD32_RELEASE  "$(prg_python38) " )
set( COMMAND_ARG32_RELEASE  ${directory__root}"/example/test2/list.py" )

set( COMMAND_CMD64_DEBUG    "$(prg_python38)" )
set( COMMAND_ARG64_DEBUG    ${directory__root}"/example/test2/list.py" )
set( COMMAND_CMD64_RELEASE  "$(prg_python38) " )
set( COMMAND_ARG64_RELEASE  ${directory__root}"/example/test2/list.py" )


set( COMMAND_ENVIRONMENT_RELEASE "PATH=%PATH%" )
set( COMMAND_ENVIRONMENT_DEBUG   "PATH=%PATH%" )
configure_file( template.vcxproj.user.in ${CMAKE_BINARY_DIR}/cdll/${PROJECT_DLL_NAME_FULL}.vcxproj.user @ONLY )


add_library( ${PROJECT_DLL_NAME_FULL} SHARED ${SOURCE_CPP} ${SOURCE_HPP}  )

target_include_directories(  ${PROJECT_DLL_NAME_FULL} PRIVATE "${directory_include}")

target_link_libraries(${PROJECT_DLL_NAME_FULL} PRIVATE ${PROJECT_NAME_BARE}Lib-${PROJECT_VERSION} )
add_dependencies(     ${PROJECT_DLL_NAME_FULL}         ${PROJECT_NAME_BARE}Lib-${PROJECT_VERSION} )
