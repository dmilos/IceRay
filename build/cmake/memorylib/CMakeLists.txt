cmake_minimum_required(VERSION 3.10)

include( "./config.cmake" )
include( "./install.cmake" )

set( ICERAY_SUBMODULE_MEMORY_PROJECT_NAME_FULL ${COMPONENT_NAME_BARE} CACHE INTERNAL "" )


set( directory__root "${CMAKE_CURRENT_SOURCE_DIR}/../../.." )

set( directory_source          "${SOLUTION_ROOTDIR}/submodule/memory/src" )
set( directory_include         "${directory_source}/memory" )

set( hpp_file_list    "./hpp.lst.txt" )
file( STRINGS ${hpp_file_list} FILE_LIST )
foreach(file_item IN LISTS FILE_LIST )
  list( APPEND SOURCE_HPP "${directory_source}/${file_item}")
endforeach(file_item)

source_group( TREE "${directory_include}/" PREFIX "Header Files\\${PROJECT_NAME_BARE}" FILES ${SOURCE_HPP} )

set( cpp_file_list    "./cpp.lst.txt" )
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


add_library(${COMPONENT_NAME_BARE} STATIC ${SOURCE_CPP} ${SOURCE_HPP})

set_target_properties(${COMPONENT_NAME_BARE} PROPERTIES VERSION ${COMPONENT_VERSION__FINAL} )
set_property( TARGET ${COMPONENT_NAME_BARE} PROPERTY POSITION_INDEPENDENT_CODE ON )
set_property( TARGET ${COMPONENT_NAME_BARE} PROPERTY CXX_VISIBILITY_PRESET hidden )
set_property( TARGET ${COMPONENT_NAME_BARE} PROPERTY OUTPUT_NAME "${COMPONENT_NAME_OUTPUT}" )


if( UNIX )
    target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -frtti )
    target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -fexceptions )
    target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -Wno-unused-local-typedefs )
    target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -Wno-unused-variable )
   #target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -Wmaybe-uninitialized )

    if( ICERAY_SWITCH_DEBUG )
        #target_compile_options( ${COMPONENT_NAME_BARE} PRIVATE -fsanitize=address )
        #target_link_options(    ${COMPONENT_NAME_BARE} PRIVATE -fsanitize=address )

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
    #target_compile_options(${COMPONENT_NAME_BARE} PRIVATE /Zp1)
    #target_compile_definitions( ${COMPONENT_NAME_BARE} PRIVATE  $<$<CONFIG:DEBUG>:_SECURE_SCL> )
    #target_compile_definitions( ${COMPONENT_NAME_BARE} PRIVATE  $<$<CONFIG:DEBUG>:_ITERATOR_DEBUG_LEVEL=2> )
    #target_compile_definitions( ${COMPONENT_NAME_BARE} PRIVATE  $<$<CONFIG:DEBUG>:_HAS_ITERATOR_DEBUGGING> )
endif()

message( STATUS "memory::CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}" )
message( STATUS "memory::CMAKE_C_FLAGS:   ${CMAKE_C_FLAGS}" )
message( STATUS "memory::SOLUTION_INSTALLDIR_BINDIR:   ${SOLUTION_INSTALLDIR_BINDIR}" )
message( STATUS "memory::COMPONENT_NAME_BARE:    ${COMPONENT_NAME_BARE}" )
message( STATUS "memory::CMAKE_INSTALL_PREFIX:   ${CMAKE_INSTALL_PREFIX}" )

