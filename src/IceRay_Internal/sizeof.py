#!/usr/bin/env python3

import ctypes

Double   = ctypes.c_double
Float    = ctypes.c_float
Scalar   = ctypes.c_double
Unsigned = ctypes.c_uint
Boolean  = ctypes.c_int
Integer  = ctypes.c_int
Size     = ctypes.c_size_t
VoidPtr  = ctypes.c_void_p

print( "Double  : " + str( ctypes.sizeof( Double   ) ) )
print( "Float   : " + str( ctypes.sizeof( Float    ) ) )
print( "Scalar  : " + str( ctypes.sizeof( Scalar   ) ) )
print( "Unsigned: " + str( ctypes.sizeof( Unsigned ) ) )
print( "Boolean : " + str( ctypes.sizeof( Boolean  ) ) )
print( "Integer : " + str( ctypes.sizeof( Integer  ) ) )
print( "Size    : " + str( ctypes.sizeof( Size     ) ) )
print( "VoidPtr : " + str( ctypes.sizeof( VoidPtr  ) ) )


### ### ### size.h ### ### ###

size_h = open('size.h','w' )

size_h.write( "#ifndef ed34bf7e80b54156b5855f4daca28fe2\n" )
size_h.write( "#define ed34bf7e80b54156b5855f4daca28fe2\n" )
size_h.write( " \n" )
#size_h.write( "#include <cstddef>\n" )
#size_h.write( " \n" )

if( 4 == ctypes.sizeof( Size ) ):
    size_h.write( "typedef std::uint32_t IceRayC_TypeSize, IceRayC_Type_Size;\n" )

if( 8 == ctypes.sizeof( Size ) ):
    size_h.write( "typedef std::uint64_t IceRayC_TypeSize, IceRayC_Type_Size;\n" )

size_h.write( " \n" )
size_h.write( "#endif\n" )


### ### ### int.h ### ### ###

int_h = open('int.h','w' )

int_h.write( "#ifndef d471bb02d24e47f580668b2358d20e88\n" )
int_h.write( "#define d471bb02d24e47f580668b2358d20e88\n" )
int_h.write( " \n" )
#int_h.write( "#include <cstddef>\n" )
#int_h.write( " \n" )

if( 4 == ctypes.sizeof( Integer ) ):
    int_h.write( "typedef std::int32_t IceRayC_TypeInteger;\n" )

if( 8 == ctypes.sizeof( Integer ) ):
    int_h.write( "typedef std::int64_t IceRayC_TypeInteger;\n" )

int_h.write( " \n" )
int_h.write( "#endif\n" )

### ### ### bool.h ### ### ###

bool_h = open('bool.h','w' )

bool_h.write( "#ifndef x5b876687523d4322ab63d78dcd390c14\n" )
bool_h.write( "#define x5b876687523d4322ab63d78dcd390c14\n" )
bool_h.write( " \n" )
#bool_h.write( "#include <cstddef>\n" )
#bool_h.write( " \n" )

if( 4 == ctypes.sizeof( Boolean ) ):
    bool_h.write( "typedef std::int32_t  IceRayC_Type_Bool;\n" )

if( 8 == ctypes.sizeof( Boolean ) ):
    bool_h.write( "typedef std::int64_t  IceRayC_Type_Bool;\n" )

bool_h.write( " \n" )
bool_h.write( "#endif\n" )

# scalar.h

scalar_h = open('scalar.h','w' )

scalar_h.write( "#ifndef x5b876687523d4322ab63d78dcd390c14\n" )
scalar_h.write( "#define x5b876687523d4322ab63d78dcd390c14\n" )
scalar_h.write( " \n" )
#scalar_h.write( "#include <cstddef>\n" )
#scalar_h.write( " \n" )

scalar_h.write( "typedef double IceRayC_TypeScalar, IceRayC_Type_Scalar\n" )

scalar_h.write( " \n" )
scalar_h.write( "#endif\n" )







