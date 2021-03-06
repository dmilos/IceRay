print( '<' + __name__ + ' name=\'' +   __file__ + '\'/>' )
import ctypes
import IceRayPy

Scalar  = IceRayPy.type.basic.Scalar
Coord3D = IceRayPy.type.math.coord.Scalar3D

AddresOf = ctypes.addressof


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


def id( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_ID( AddresOf( result ) )
    return result

def zero( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_Zero( AddresOf( result ) )
    return result

def scaleS( P_scale ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_ScaleV( AddresOf( result ), Scalar( P_scale ) )
    return result

def scaleV( P_scale : Coord3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_ScaleV( AddresOf( result ), P_scale )
    return result

def rotateX( P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_RotateX( AddresOf( result ), P_alpha )
    return result

def rotateY( P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_RotateY( AddresOf( result ), P_alpha )
    return result

def rotateZ( P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_RotateY( AddresOf( result ), P_alpha )
    return result

def rotateA( P_direction : Coord3D, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_RotateA( AddresOf( result ), P_direction, Scalar( P_alpha ) )
    return result

def compose( P_left : Scalar3D,  P_right : Scalar3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_Compose( AddresOf( result ), AddresOf( P_left ), AddresOf( P_right ) )
    return result

