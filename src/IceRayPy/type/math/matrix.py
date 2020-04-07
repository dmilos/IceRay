import ctypes

Scalar = ctypes.c_double

import IceRayPy.type.math.coord

Coord3D = IceRayPy.type.math.coord.Scalar3D

class Scalar1D(ctypes.Structure):
    _fields_ = [ ("11", Scalar), ("12", Scalar)
                ]

class Scalar2D(ctypes.Structure):
    _fields_ = [ ("11", Scalar), ("12", Scalar),
                 ("21", Scalar), ("22", Scalar)
                ]

class Scalar3D(ctypes.Structure):
    _fields_ = [ ("11", Scalar), ("12", Scalar), ("13", Scalar),
                 ("21", Scalar), ("22", Scalar), ("23", Scalar),
                 ("31", Scalar), ("32", Scalar), ("33", Scalar)
                ]

class Scalar4D(ctypes.Structure):
    _fields_ = [ ("11", Scalar), ("12", Scalar), ("13", Scalar), ("14", Scalar),
                 ("21", Scalar), ("22", Scalar), ("23", Scalar), ("24", Scalar),
                 ("31", Scalar), ("32", Scalar), ("33", Scalar), ("34", Scalar),
                 ("41", Scalar), ("42", Scalar), ("43", Scalar), ("44", Scalar)
                ]


Pointer = ctypes.POINTER

def id( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_ID( Pointer( result ) )
    return result

def zero( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_Zero( Pointer( result ) )
    return result

def scaleS( P_scale ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_ScaleV( Pointer( result ), Scalar( P_scale ) )
    return result

def scaleV( P_scale : Coord3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_ScaleV( Pointer( result ), P_scale )
    return result

def rotateX( P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_RotateX( Pointer( result ), P_alpha )
    return result

def rotateY( P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_RotateY( Pointer( result ), P_alpha )
    return result

def rotateZ( P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_RotateY( Pointer( result ), P_alpha )
    return result

def rotateA( P_direction : Coord3D, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_RotateA( Pointer( result ), P_direction, Scalar( P_alpha ) )
    return result

def compose( P_left : Scalar3D,  P_right : Scalar3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_Compose( Pointer( result ), Pointer( P_left ), Pointer( P_right ) )
    return result

