cmake_minimum_required(VERSION 3.10)

include ("./config.cmake" )

project( ${SOLUTION_NAME} )

include ("./install.cmake" )

option( ICERAY_SWITCH_DEBUG "Enable Debug" OFF )


if ( MSVC )
    option( ICERAY_WINDOWS_USE_GDI "Enable Debug" ON )
endif()

add_subdirectory(memorylib)
add_subdirectory(core)
add_subdirectory(clib)
add_subdirectory(cdll)
#add_subdirectory(sizeof)


message( "_main::SOLUTION_ROOTDIR: " ${SOLUTION_ROOTDIR} )


if(MSVC)
    configure_file( "env-set.bat.config"    "${SOLUTION_INSTALLDIR_SCRIPTDIR_FULL}/env-set.bat" )
    configure_file( "env-clear.bat.config"  "${SOLUTION_INSTALLDIR_SCRIPTDIR_FULL}/env-clear.bat" )
    configure_file( "env-check.bat.config"  "${SOLUTION_INSTALLDIR_SCRIPTDIR_FULL}/env-check.bat" )
endif()

if( UNIX )
    configure_file( "env-set.sh.config"    "${SOLUTION_INSTALLDIR_SCRIPTDIR_FULL}/env-set.sh" )
    configure_file( "env-clear.sh.config"  "${SOLUTION_INSTALLDIR_SCRIPTDIR_FULL}/env-clear.sh" )
    configure_file( "env-check.sh.config"  "${SOLUTION_INSTALLDIR_SCRIPTDIR_FULL}/env-check.sh" )
endif()


add_compile_options(
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>:
        -Wno-unused-variable
        -Wno-unused-private-field
        -Wunused-local-typedef
        -Wunused-variable #!< enable if you want to develop
        -Wself-assign     #!< enable if you want to develop
        -Wunused-but-set-variable 
        -Wself-assign-field
    >
    $<$<CXX_COMPILER_ID:MSVC>:/wd4101>
)

include ("./info.cmake")