#print( '<' + __name__ + ' name=\'' +   __file__ + '\'/>' )
import ctypes
import inspect

import IceRayPy.type.math.coord

AddressOf = ctypes.addressof

ScalarType = IceRayPy.type.basic.Scalar
Coord3D = IceRayPy.type.math.coord.Scalar3D

class Scalar1D(ctypes.Structure):
    _fields_ = [ ("11", ScalarType),
                 ("12", ScalarType)
                ]

class Scalar2D(ctypes.Structure):
    _fields_ = [ ("11", ScalarType), ("12", ScalarType),
                 ("21", ScalarType), ("22", ScalarType),
                 ("13", ScalarType), ("23", ScalarType)
                ]

class Scalar3D(ctypes.Structure):
    _fields_ = [ ("a11", ScalarType), ("a12", ScalarType), ("a13", ScalarType),
                 ("a21", ScalarType), ("a22", ScalarType), ("a23", ScalarType),
                 ("a31", ScalarType), ("a32", ScalarType), ("a33", ScalarType),
                 ("a14", ScalarType), ("a24", ScalarType), ("a34", ScalarType)
                ]

class Scalar4D(ctypes.Structure):
    _fields_ = [ ("11", ScalarType), ("12", ScalarType), ("13", ScalarType), ("14", ScalarType),
                 ("21", ScalarType), ("22", ScalarType), ("23", ScalarType), ("24", ScalarType),
                 ("31", ScalarType), ("32", ScalarType), ("33", ScalarType), ("34", ScalarType),
                 ("41", ScalarType), ("42", ScalarType), ("43", ScalarType), ("44", ScalarType),
                 ("15", ScalarType), ("25", ScalarType), ("35", ScalarType), ("45", ScalarType)
                ]


def print3D( P_3D : Scalar3D ):
    print( "[ " + str(P_3D.a11) + ', ' + str(P_3D.a12)+ ', ' + str(P_3D.a13)+ ', ' + str(P_3D.a14) + " ]", flush = True )
    print( "[ " + str(P_3D.a21) + ', ' + str(P_3D.a22)+ ', ' + str(P_3D.a23)+ ', ' + str(P_3D.a24) + " ]", flush = True )
    print( "[ " + str(P_3D.a31) + ', ' + str(P_3D.a32)+ ', ' + str(P_3D.a33)+ ', ' + str(P_3D.a34) + " ]", flush = True )
    pass

def lookAt( P_dll, P_eye : Coord3D, P_view: Coord3D, P_up: Coord3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine_LookAt3D( AddressOf( result ), AddressOf( P_eye ), AddressOf( P_view ), AddressOf( P_up ) )
    return result

def id3D( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine_ID3D( AddressOf( result ) )
    return result

def zero3D( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine_Zero3D( AddressOf( result ) )
    return result

def move3D( P_dll, P_move : Coord3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine_Move3D( AddressOf( result ), AddressOf( P_move ) )
    return result

def scaleS( P_dll, P_scale : ScalarType ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine_ScaleS3D( AddressOf( result ), ScalarType( P_scale ) )
    return result

def scaleV( P_dll, P_scale : Coord3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine_ScaleV3D( AddressOf( result ), AddressOf( P_scale ) )
    return result

def rotateX( P_dll, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine_RotateX3D( AddressOf( result ), ScalarType( P_alpha ) )
    return result

def rotateY( P_dll, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine_RotateY3D( AddressOf( result ), ScalarType( P_alpha ) )
    return result

def rotateZ( P_dll, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine_RotateY3D( AddressOf( result ), ScalarType( P_alpha ) )
    return result

def rotateA( P_dll, P_direction : Coord3D, P_alpha : ScalarType ):
    result = Scalar3D()
    f = P_dll.IceRayC_Type_Math_Affine_RotateA3D( AddressOf( result ), AddressOf( P_direction ), ScalarType( P_alpha ) )
    return result

def rotateD( P_dll, P_pivot : Coord3D, P_direction : Coord3D, P_alpha : ScalarType ):
    result = Scalar3D()
    f = P_dll.IceRayC_Type_Math_Affine_RotateA3D( AddressOf( result ), AddressOf( P_pivot ), AddressOf( P_direction ), ScalarType( P_alpha ) )
    return result

def invert3D( P_dll, P_right : Scalar3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine_Invert3D( AddressOf( result ), AddressOf( P_right ) )
    return result

def compose3D( P_dll, P_left : Scalar3D, P_right : Scalar3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Affine_Compose3D( AddressOf( result ), AddressOf( P_left ), AddressOf( P_right ) )
    return result

def system3D( P_dll, P_pivot : Coord3D, P_X : Coord3D, P_Y : Coord3D, P_Z : Coord3D ):
    result = Scalar3D()
    f = P_dll.IceRayC_Type_Math_Affine_System3D( AddressOf( result ), AddressOf( P_pivot ), AddressOf( P_X ), AddressOf( P_Y ), AddressOf( P_Z ) )
    return result

def system3D_Z( P_dll, P_pivot : Coord3D, P_Z : Coord3D ):
    result = Scalar3D()
    f = P_dll.IceRayC_Type_Math_Affine_SystemZ3D( AddressOf( result ), AddressOf( P_pivot ), AddressOf( P_Z ) )
    return result

def transform3D( P_dll, P_affine: Scalar3D, P_point: Coord3D ):
    I_result = Coord3D()
    P_dll.IceRayC_Type_Math_Affine_Transform3D( AddressOf( I_result ), AddressOf( P_affine ), AddressOf( P_point ) )
    return I_result

def construct3D( P_dll
            ,P_tO : Coord3D, P_tX : Coord3D, P_tY : Coord3D, P_tZ : Coord3D
            ,P_sO : Coord3D, P_sX : Coord3D, P_sY : Coord3D, P_sZ : Coord3D
    ):
   result = Scalar3D()
   f = P_dll.IceRayC_Type_Math_Affine_Construct3D(
      AddressOf( result )
     ,AddressOf( P_tO ), AddressOf( P_tX ), AddressOf( P_tY ), AddressOf( P_tZ )
     ,AddressOf( P_sO ), AddressOf( P_sX ), AddressOf( P_sY ), AddressOf( P_sZ )
    )
   return result

#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
