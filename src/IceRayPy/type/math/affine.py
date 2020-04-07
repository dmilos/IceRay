import ctypes
import inspect


Scalar = ctypes.c_double

import IceRayPy.type.math.coord

Coord3D = IceRayPy.type.math.coord.Scalar3D

class Scalar1D(ctypes.Structure):
    _fields_ = [ ("11", Scalar), ("12", Scalar)
                ]

class Scalar2D(ctypes.Structure):
    _fields_ = [ ("11", Scalar), ("12", Scalar), ("13", Scalar),
                 ("21", Scalar), ("22", Scalar), ("23", Scalar)
                ]

class Scalar3D(ctypes.Structure):
    _fields_ = [ ("11", Scalar), ("12", Scalar), ("13", Scalar), ("14", Scalar),
                 ("21", Scalar), ("22", Scalar), ("23", Scalar), ("24", Scalar),
                 ("31", Scalar), ("32", Scalar), ("33", Scalar), ("34", Scalar)
                ]

class Scalar4D(ctypes.Structure):
    _fields_ = [ ("11", Scalar), ("12", Scalar), ("13", Scalar), ("14", Scalar), ("15", Scalar),
                 ("21", Scalar), ("22", Scalar), ("23", Scalar), ("24", Scalar), ("25", Scalar),
                 ("31", Scalar), ("32", Scalar), ("33", Scalar), ("34", Scalar), ("35", Scalar),
                 ("41", Scalar), ("42", Scalar), ("43", Scalar), ("44", Scalar), ("45", Scalar)
                ]


Pointer = ctypes.POINTER




def lookAt( P_dll, P_eye : Coord3D, P_view: Coord3D, P_up: Coord3D ):
    result = Scalar3D()

    f = P_dll.IceRayC_Type_Math_Affine3D_LookAt
    f.argtypes = [ ctypes.POINTER( Scalar3D ), ctypes.POINTER( Coord3D ), ctypes.POINTER( Coord3D ), ctypes.POINTER( Coord3D ) ]
    f.restype = ctypes.c_int
    f( result, P_eye, P_view, P_up )

    return result

def id( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_ID( Pointer( result ) )
    return result

def zero( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_Zero( result )
    return result


def move3D( P_dll, P_move : Coord3D ):
    result = Scalar3D()

    f = P_dll.IceRayC_Type_Math_Affine3D_Move
    f.argtypes = [ ctypes.POINTER( Scalar3D ), ctypes.POINTER( Coord3D ) ]
    f.restype = ctypes.c_int
    f( result, P_move )

    return result

def scaleS( P_dll, P_scale ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_ScaleV( Pointer( result ), Scalar( P_scale ) )
    return result

def scaleV( P_dll, P_scale : Coord3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_ScaleV( Pointer( result ), P_scale )
    return result

def rotateX( P_dll, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_RotateX( Pointer( result ), P_alpha )
    return result

def rotateY( P_dll, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_RotateY( Pointer( result ), P_alpha )
    return result

def rotateZ( P_dll, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_RotateY( Pointer( result ), P_alpha )
    return result

def rotateA( P_dll, P_direction : Coord3D, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_RotateA( Pointer( result ), P_direction, Scalar( P_alpha ) )
    return result

def compose3D( P_dll, P_left : Scalar3D, P_right : Scalar3D ):
    result = Scalar3D()

    f = P_dll.IceRayC_Type_Math_Affine3D_Compose
    f.argtypes = [ ctypes.POINTER( Scalar3D ), ctypes.POINTER( Scalar3D ), ctypes.POINTER( Scalar3D ) ]
    f.restype = ctypes.c_int
    f( result, P_left, P_right )

    return result

