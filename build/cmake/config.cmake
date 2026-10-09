#!/cmake Solution configuration



set( SOLUTION_NAME     "IceRay"  )

set( SOLUTION_ROOTDIR     ${CMAKE_SOURCE_DIR}/../..  )
get_filename_component( SOLUTION_ROOTDIR ${SOLUTION_ROOTDIR} ABSOLUTE )

set( SOLUTION_SOURCEDIR   ${SOLUTION_ROOTDIR}/src  )

set( SOLUTION_VERSION_MAJOR       1  )
set( SOLUTION_VERSION_MINOR       0  )
set( SOLUTION_VERSION_REVISION    0  )
set( SOLUTION_VERSION_BUILD       0  )

set( SOLUTION_VERSION__FINAL   ${SOLUTION_VERSION_MAJOR}.${SOLUTION_VERSION_MINOR}.${SOLUTION_VERSION_REVISION}.${SOLUTION_VERSION_BUILD} )

#if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
#    add_compile_options( -Wno-unused-variable          )
#    add_compile_options( -Wno-unused-private-field     )
#    add_compile_options( -Wno-unused-local-typedef     )
#    add_compile_options( -Wno-unused-but-set-variable  )
#    add_compile_options( -Wno-self-assign-field        )
#    add_compile_options( -Wunused-variable             )
#    add_compile_options( -Wself-assign                 )
#    add_compile_options( -Wself-assign-field           )
#    add_compile_options( -Wunused-variable             )
#elseif(MSVC)
#    #add_compile_options(/wd4250)
#endif()
