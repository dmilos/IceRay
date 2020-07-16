print( '<' + __name__ + ' name=\'' +   __file__ + '\'/>' )
import ctypes
import inspect

import IceRayPy.type.math.coord

AddresOf = ctypes.addressof

SizeType = IceRayPy.type.basic.Scalar
Coord3D = IceRayPy.type.math.coord.Scalar3D

class Scalar1D(ctypes.Structure):
    _fields_ = [ ("11", SizeType), ("12", SizeType)
                ]

class Scalar2D(ctypes.Structure):
    _fields_ = [ ("11", SizeType), ("12", SizeType), ("13", SizeType),
                 ("21", SizeType), ("22", SizeType), ("23", SizeType)
                ]

class Scalar3D(ctypes.Structure):
    _fields_ = [ ("11", SizeType), ("12", SizeType), ("13", SizeType), ("14", SizeType),
                 ("21", SizeType), ("22", SizeType), ("23", SizeType), ("24", SizeType),
                 ("31", SizeType), ("32", SizeType), ("33", SizeType), ("34", SizeType)
                ]

class Scalar4D(ctypes.Structure):
    _fields_ = [ ("11", SizeType), ("12", SizeType), ("13", SizeType), ("14", SizeType), ("15", SizeType),
                 ("21", SizeType), ("22", SizeType), ("23", SizeType), ("24", SizeType), ("25", SizeType),
                 ("31", SizeType), ("32", SizeType), ("33", SizeType), ("34", SizeType), ("35", SizeType),
                 ("41", SizeType), ("42", SizeType), ("43", SizeType), ("44", SizeType), ("45", SizeType)
                ]


def lookAt( P_dll, P_eye : Coord3D, P_view: Coord3D, P_up: Coord3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_LookAt( AddresOf( result ), AddresOf( P_eye ), AddresOf( P_view ), AddresOf( P_up ) )
    return result

def id3D( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_ID( AddresOf( result ) )
    return result

def zero3D( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_Zero( AddresOf( result ) )
    return result


def move3D( P_dll, P_move : Coord3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_Move( AddresOf( result ), AddresOf( P_move ) )
    return result

def scaleS( P_dll, P_scale ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_ScaleV( AddresOf( result ), Scalar( P_scale ) )
    return result

def scaleV( P_dll, P_scale : Coord3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_ScaleV( AddresOf( result ), AddresOf( P_scale ) )
    return result

def rotateX( P_dll, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_RotateX( AddresOf( result ), Scalar( P_alpha ) )
    return result

def rotateY( P_dll, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_RotateY( AddresOf( result ), Scalar( P_alpha ) )
    return result

def rotateZ( P_dll, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_RotateY( AddresOf( result ), Scalar( P_alpha ) )
    return result

def rotateA( P_dll, P_direction : Coord3D, P_alpha ):
    result = Scalar3D()
    f = P_dll.IceRayC_Type_Math_Affine3D_RotateA( AddresOf( result ), AddresOf( P_direction ), Scalar( P_alpha ) )
    f.argtypes = [ ctypes.POINTER( Scalar3D ), ctypes.POINTER( Scalar3D ), ctypes.POINTER( Scalar3D ) ]
    f.restype = IceRayPy.type.basic.Integer

    return result

def compose3D( P_dll, P_left : Scalar3D, P_right : Scalar3D ):
    result = Scalar3D()

    P_dll.IceRayC_Type_Math_Affine3D_Compose(  AddresOf( result ), AddresOf( P_left ), AddresOf( P_right ) )

    return result

