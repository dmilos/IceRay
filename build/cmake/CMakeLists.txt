cmake_minimum_required(VERSION 3.10)

include ("./config.cmake" )
include ("./install.cmake" )


project( ${SOLUTION_NAME} )

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
    configure_file( "env-set.bat.config"    "${CMAKE_INSTALL_SCRIPTDIR}/env-set.bat" )
    configure_file( "env-clear.bat.config"  "${CMAKE_INSTALL_SCRIPTDIR}/env-clear.bat" )
    configure_file( "env-check.bat.config"  "${CMAKE_INSTALL_SCRIPTDIR}/env-check.bat" )
endif()

if (UNIX)
    configure_file( "env-set.sh.config"    "${CMAKE_INSTALL_SCRIPTDIR}/env-set.sh" )
    configure_file( "env-clear.sh.config"  "${CMAKE_INSTALL_SCRIPTDIR}/env-clear.sh" )
    configure_file( "env-check.sh.config"  "${CMAKE_INSTALL_SCRIPTDIR}/env-check.sh" )
endif()
