#print( '<' + __name__ + ' name=\'' +   __file__ + '\'/>' )
import ctypes
import IceRayPy

Scalar  = IceRayPy.type.basic.Scalar
Coord3D = IceRayPy.type.math.coord.Scalar3D

AddressOf = ctypes.addressof


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
    _fields_ = [ ("a11", Scalar), ("a12", Scalar), ("a13", Scalar), ("a14", Scalar),
                 ("a21", Scalar), ("a22", Scalar), ("a23", Scalar), ("a24", Scalar),
                 ("a31", Scalar), ("a32", Scalar), ("a33", Scalar), ("a34", Scalar),
                 ("a41", Scalar), ("a42", Scalar), ("a43", Scalar), ("a44", Scalar)
                ]

def print4D( P_4D : Scalar3D ):
    print( "[ " + str(P_4D.a11) + ', ' + str(P_4D.a12)+ ', ' + str(P_4D.a13)+ ', ' + str(P_4D.a14) + ' ]', flush = True )
    print( "[ " + str(P_4D.a21) + ', ' + str(P_4D.a22)+ ', ' + str(P_4D.a23)+ ', ' + str(P_4D.a24) + ' ]', flush = True )
    print( "[ " + str(P_4D.a31) + ', ' + str(P_4D.a32)+ ', ' + str(P_4D.a33)+ ', ' + str(P_4D.a34) + ' ]', flush = True )
    print( "[ " + str(P_4D.a41) + ', ' + str(P_4D.a42)+ ', ' + str(P_4D.a43)+ ', ' + str(P_4D.a44) + ' ]', flush = True )
    pass



def id3D( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_ID( AddressOf( result ) )
    return result

def zero3D( P_dll ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_Zero( AddressOf( result ) )
    return result

def scaleS( P_scale ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_ScaleV( AddressOf( result ), Scalar( P_scale ) )
    return result

def scaleV( P_scale : Coord3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_ScaleV( AddressOf( result ), AddressOf( P_scale ) )
    return result

def rotateX( P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_RotateX( AddressOf( result ), P_alpha )
    return result

def rotateY( P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_RotateY( AddressOf( result ), P_alpha )
    return result

def rotateZ( P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_RotateY( AddressOf( result ), P_alpha )
    return result

def rotateA( P_direction : Coord3D, P_alpha ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_RotateA( AddressOf( result ), AddressOf( P_direction ), Scalar( P_alpha ) )
    return result

def invert3D( P_left : Scalar3D,  P_right : Scalar3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_Invert( AddressOf( result ), AddressOf( P_right ) )
    return result

def compose3D( P_left : Scalar3D,  P_right : Scalar3D ):
    result = Scalar3D()
    P_dll.IceRayC_Type_Math_Matrix3D_Multiply( AddressOf( result ), AddressOf( P_left ), AddressOf( P_right ) )
    return result


def id4D( P_dll ):
    result = Scalar4D()
    P_dll.IceRayC_Type_Math_Matrix4D_ID( AddressOf( result ) )
    return result

def invert4D( P_dll ):
    result = Scalar4D()
    P_dll.IceRayC_Type_Math_Matrix4D_Invert( AddressOf( result ) )
    return result

def compose4D( P_left : Scalar3D,  P_right : Scalar3D ):
    result = Scalar4D()
    P_dll.IceRayC_Type_Math_Matrix4D_Multiply( AddressOf( result ), AddressOf( P_left ), AddressOf( P_right ) )
    return result

def zero4D( P_dll ):
    result = Scalar4D()
    P_dll.IceRayC_Type_Math_Matrix4D_Zero( AddressOf( result ) )
    return result


#print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
