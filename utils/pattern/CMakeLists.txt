#cmake_minimum_required(VERSION 4.2)
#cmake_minimum_required(VERSION  3.31.6)
cmake_minimum_required(VERSION 2.8)

project( PatternTestPrj )

set( PROJECT_EXE_NAME       "PatternTestExe"   )
set( directory__root "${CMAKE_CURRENT_SOURCE_DIR}/../.." )
set( directory_submodule__root  "${directory__root}/submodule" )
set( directory_iceray  "${directory__root}/src" )

add_executable( ${PROJECT_EXE_NAME} main.cpp )

target_include_directories( ${PROJECT_EXE_NAME} PUBLIC "${directory_iceray}")

target_include_directories( ${PROJECT_EXE_NAME} PUBLIC "${directory_submodule__root}/color/src")
target_include_directories( ${PROJECT_EXE_NAME} PUBLIC "${directory_submodule__root}/container/src")
target_include_directories( ${PROJECT_EXE_NAME} PUBLIC "${directory_submodule__root}/math/src")
target_include_directories( ${PROJECT_EXE_NAME} PUBLIC "${directory_submodule__root}/memory/src")
target_include_directories( ${PROJECT_EXE_NAME} PUBLIC "${directory_submodule__root}/PNM/src")
target_include_directories( ${PROJECT_EXE_NAME} PUBLIC "${directory_submodule__root}/TopLog/src")

 
if( MSVC )
    target_include_directories( ${PROJECT_EXE_NAME}  PUBLIC  $ENV{OPENCV__msvc__INCLUDE} )
    target_link_libraries ( ${PROJECT_EXE_NAME}
        debug     $ENV{OPENCV__msvc_64_LIBFILE_DEBUG}
        optimized $ENV{OPENCV__msvc_64_LIBFILE_RELEASE}
     )

    target_link_directories( ${PROJECT_EXE_NAME}
        PUBLIC $<$<CONFIG:DEBUG>:$ENV{OPENCV__msvc_64_LIBDIR_DEBUG}>
        PUBLIC $<$<CONFIG:RELEASE>:$ENV{OPENCV__msvc_64_LIBDIR_RELEASE}>
     )

    set( OPENCV_BIN_DEBUG   $ENV{OPENCV__msvc_64_DLLDIR_DEBUG}   )
    set( OPENCV_BIN_RELEASE $ENV{OPENCV__msvc_64_DLLDIR_RELEASE} )
    configure_file( templatevcxproj.user.in ${PROJECT_EXE_NAME}.vcxproj.user   )

endif()


 
