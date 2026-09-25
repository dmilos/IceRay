cmake_minimum_required(VERSION 3.10)

include( "./config.cmake" )
include( "./install.cmake" )

set( ICERAY_CORE_LIBRARY_PROJECT_NAME_FULL     ${COMPONENT_NAME_BARE} CACHE INTERNAL "" )


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

#Processing
set( SOURCE_HPP "" )
#file( STRINGS ${hpp_file_list} FILE_LIST )
file( GLOB_RECURSE SOURCE_HPP "${directory_source}/IceRay/main/interface/c/*.hpp")
source_group( TREE "${directory_include}/" PREFIX "Header Files\\${COMPONENT_NAME_BARE}" FILES ${SOURCE_HPP} )

#set( cpp_file_list    "./cpp.lst.txt" )
set( cpp_file_list    "./cpp-expand.lst.txt" )
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

add_library( ${COMPONENT_NAME_BARE} STATIC ${SOURCE_CPP} ${SOURCE_HPP}  )

set_property( TARGET ${COMPONENT_NAME_BARE} PROPERTY CXX_VISIBILITY_PRESET hidden )
set_property( TARGET ${COMPONENT_NAME_BARE} PROPERTY POSITION_INDEPENDENT_CODE ON )
set_property( TARGET ${COMPONENT_NAME_BARE} PROPERTY OUTPUT_NAME "${COMPONENT_NAME_OUTPUT}" )
set_target_properties(${COMPONENT_NAME_BARE} PROPERTIES VERSION ${COMPONENT_VERSION__FINAL} )

if( UNIX )
    target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -frtti )
    target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -fexceptions )
    target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -Wno-unused-local-typedefs )
    target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -Wno-unused-variable )
    #target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -Wmaybe-uninitialized )

    if( ICERAY_SWITCH_DEBUG )
        #target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -fsanitize=address )
        #target_link_options(    ${COMPONENT_NAME_BARE} PRIVATE -fsanitize=address )
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
        target_compile_definitions( ${COMPONENT_NAME_BARE} PRIVATE DEBUG )
        target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -g )
        target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -rdynamic )
        target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -ggdb )
        target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -g3 )
        target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -O0 )
        set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DDEBUG -g -rdynamic -ggdb -g3 -O0")
    endif()
endif()

if( MSVC )
    if( ICERAY_WINDOWS_USE_GDI )
        target_compile_definitions(  ${COMPONENT_NAME_BARE}  PRIVATE ICERAY_WINDOWS_USE_GDI=1 )
    endif()

    target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE /wd4624 )
    #target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE /Zp1    )
    #target_compile_definitions( ${COMPONENT_NAME_BARE} PRIVATE  $<$<CONFIG:DEBUG>:_SECURE_SCL> )
    #target_compile_definitions( ${COMPONENT_NAME_BARE} PRIVATE  $<$<CONFIG:DEBUG>:_ITERATOR_DEBUG_LEVEL=2> )
    #target_compile_definitions( ${COMPONENT_NAME_BARE} PRIVATE  $<$<CONFIG:DEBUG>:_HAS_ITERATOR_DEBUGGING> )
endif()

target_include_directories(  ${COMPONENT_NAME_BARE} PRIVATE "${directory_include}")

target_link_libraries(  ${COMPONENT_NAME_BARE} PRIVATE ${ICERAY_CORE_CORE_PROJECT_NAME_FULL} )
add_dependencies(       ${COMPONENT_NAME_BARE}         ${ICERAY_CORE_CORE_PROJECT_NAME_FULL} )

install( TARGETS ${COMPONENT_NAME_BARE}         DESTINATION ${SOLUTION_INSTALLDIR_BINDIR}/${COMPONENT_NAME_BARE} )
#if( MSVC OR WIN32 )
#    install( FILES $<TARGET_PDB_FILE:${COMPONENT_NAME_BARE}>  DESTINATION ${SOLUTION_INSTALLDIR_BINDIR}/${COMPONENT_NAME_BARE} OPTIONAL )
#endif()

message( STATUS "clib::CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}" )
message( STATUS "clib::CMAKE_C_FLAGS:   ${CMAKE_C_FLAGS}" )
message( STATUS "clib::SOLUTION_INSTALLDIR_BINDIR:   ${SOLUTION_INSTALLDIR_BINDIR}" )
message( STATUS "clib::COMPONENT_NAME_BARE:    ${COMPONENT_NAME_BARE}" )
message( STATUS "clib::CMAKE_INSTALL_PREFIX:   ${CMAKE_INSTALL_PREFIX}" )

