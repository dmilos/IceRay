#print( '<' + __name__ + ' name=\'' +   __file__ + '\'/>' )
import ctypes
import inspect

import IceRayPy.type.math.coord

AddressOf = ctypes.addressof

ScalarType = IceRayPy.type.basic.Scalar
Coord3D = IceRayPy.type.math.coord.Scalar3D

class Scalar1D(ctypes.Structure):
    _fields_ = [ ("11", ScalarType), ("12", ScalarType)
                ]

class Scalar2D(ctypes.Structure):
    _fields_ = [ ("11", ScalarType), ("12", ScalarType), ("13", ScalarType),
                 ("21", ScalarType), ("22", ScalarType), ("23", ScalarType)
                ]

class Scalar3D(ctypes.Structure):
    _fields_ = [ ("11", ScalarType), ("12", ScalarType), ("13", ScalarType), ("14", ScalarType),
                 ("21", ScalarType), ("22", ScalarType), ("23", ScalarType), ("24", ScalarType),
                 ("31", ScalarType), ("32", ScalarType), ("33", ScalarType), ("34", ScalarType)
                ]

class Scalar4D(ctypes.Structure):
    _fields_ = [ ("11", ScalarType), ("12", ScalarType), ("13", ScalarType), ("14", ScalarType), ("15", ScalarType),
                 ("21", ScalarType), ("22", ScalarType), ("23", ScalarType), ("24", ScalarType), ("25", ScalarType),
                 ("31", ScalarType), ("32", ScalarType), ("33", ScalarType), ("34", ScalarType), ("35", ScalarType),
                 ("41", ScalarType), ("42", ScalarType), ("43", ScalarType), ("44", ScalarType), ("45", ScalarType)
                ]


def lookAt( P_dll, P_eye : Coord3D, P_view: Coord3D, P_up: Coord3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_LookAt( AddressOf( result ), AddressOf( P_eye ), AddressOf( P_view ), AddressOf( P_up ) )
    return result

def id3D( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_ID( AddressOf( result ) )
    return result

def zero3D( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_Zero( AddressOf( result ) )
    return result

def move3D( P_dll, P_move : Coord3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_Move( AddressOf( result ), AddressOf( P_move ) )
    return result

def scaleS( P_dll, P_scale : ScalarType ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_ScaleS( AddressOf( result ), ScalarType( P_scale ) )
    return result

def scaleV( P_dll, P_scale : Coord3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_ScaleV( AddressOf( result ), AddressOf( P_scale ) )
    return result

def rotateX( P_dll, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_RotateX( AddressOf( result ), ScalarType( P_alpha ) )
    return result

def rotateY( P_dll, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_RotateY( AddressOf( result ), ScalarType( P_alpha ) )
    return result

def rotateZ( P_dll, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine3D_RotateY( AddressOf( result ), ScalarType( P_alpha ) )
    return result

def rotateA( P_dll, P_direction : Coord3D, P_alpha : ScalarType ):
    result = Scalar3D()
    f = P_dll.IceRayC_Type_Math_Affine3D_RotateA( AddressOf( result ), AddressOf( P_direction ), ScalarType( P_alpha ) )
    return result

def rotateD( P_dll, P_pivot : Coord3D, P_direction : Coord3D, P_alpha : ScalarType ):
    result = Scalar3D()
    f = P_dll.IceRayC_Type_Math_Affine3D_RotateA( AddressOf( result ), AddressOf( P_pivot ), AddressOf( P_direction ), ScalarType( P_alpha ) )
    return result

def compose3D( P_dll, P_left : Scalar3D, P_right : Scalar3D ):
    result = Scalar3D()

    P_dll.IceRayC_Type_Math_Affine3D_Compose( AddressOf( result ), AddressOf( P_left ), AddressOf( P_right ) )
    return result

def system3D( P_dll, P_pivot : Coord3D, P_X : Coord3D, P_Y : Coord3D, P_Z : Coord3D ):
    result = Scalar3D()
    f = P_dll.IceRayC_Type_Math_Affine3D_System( AddressOf( result ), AddressOf( P_pivot ), AddressOf( P_X ), AddressOf( P_Y ), AddressOf( P_Z ) )
    return result

def system3D_Z( P_dll, P_pivot : Coord3D, P_Z : Coord3D ):
    result = Scalar3D()
    f = P_dll.IceRayC_Type_Math_Affine3D_SystemZ( AddressOf( result ), AddressOf( P_pivot ), AddressOf( P_Z ) )
    return result

#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
