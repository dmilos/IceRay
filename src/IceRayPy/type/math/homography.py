#print( '<' + __name__ + ' name=\'' +   __file__ + '\''+ '>' )
import ctypes
import IceRayPy

Scalar  = IceRayPy.type.basic.Scalar

Coord1D = IceRayPy.type.math.coord.Scalar1D
Coord2D = IceRayPy.type.math.coord.Scalar2D
Coord3D = IceRayPy.type.math.coord.Scalar3D

Matrix2D = IceRayPy.type.math.matrix.Scalar2D
Matrix3D = IceRayPy.type.math.matrix.Scalar3D
Matrix4D = IceRayPy.type.math.matrix.Scalar4D


AddressOf = ctypes.addressof


def core1D( P_dll, P_A, P_B ):
    result = Matrix2D()
    P_dll.IceRayC_Type_Math_Homography_Core1D( AddressOf( result ), Scalar( P_A ), Scalar( P_B ) )
    return result

def core2D( P_dll, P_point ):
    result = Matrix3D()
    P_dll.IceRayC_Type_Math_Homography_Core2D( AddressOf( result ), AddressOf( P_point ) )
    return result

def core3D( P_dll, P_point ):
    result = Matrix4D()
    P_dll.IceRayC_Type_Math_Homography_Core3D( AddressOf( result ), AddressOf( P_point ) )
    return result

def transform1D( P_dll, P_result, P_matrix, P_point ):
    result = Matrix4D()
    P_dll.IceRayC_Type_Math_Homography_Transform1D( AddressOf( result ), AddressOf( P_matrix ), AddressOf( P_point ) )
    return result

def transform2D( P_dll, P_result, P_matrix, P_point ):
    result = Matrix4D()
    P_dll.IceRayC_Type_Math_Homography_Transform2D( AddressOf( result ), AddressOf( P_matrix ), AddressOf( P_point ) )
    return result

def transform3D( P_dll, P_result, P_matrix, P_point ):
    result = Matrix4D()
    P_dll.IceRayC_Type_Math_Homography_Transform3D( AddressOf( result ), AddressOf( P_matrix ), AddressOf( P_point ) )
    return result

def invert3D( P_dll, P_right ):
    result = Matrix4D()
    P_dll.IceRayC_Type_Math_Matrix4D_Invert( AddressOf( result ), AddressOf( P_right ) )
    return result

def compose3D( P_dll, P_result, P_left, P_right ):
    result = Matrix4D()
    P_dll.IceRayC_Type_Math_Matrix4D_Multiply( AddressOf( result ), AddressOf( P_left ), AddressOf( P_right ) )
    return result

def system3D( P_dll, P_O : Coord3D, P_X : Coord3D, P_Y : Coord3D, P_Z : Coord3D, P_T : Coord3D ):
    result = Matrix4D()
    f = P_dll.IceRayC_Type_Math_Homography_System3D( AddressOf( result ), AddressOf( P_O ), AddressOf( P_X ), AddressOf( P_Y ), AddressOf( P_Z ), AddressOf( P_T ) )
    return result


#def transform1D( P_dll, P_homography: Matrix2D, P_point: Coord1D ):
#    I_result = Coord1D()
#    P_dll.IceRayC_Type_Math_Homography_Transform1D( AddressOf( I_result ), AddressOf( P_homography ), AddressOf( P_point ) )
#    return I_result

def transform2D( P_dll, P_homography: Matrix3D, P_point: Coord2D ):
    I_result = Coord2D()
    P_dll.IceRayC_Type_Math_Homography_Transform2D( AddressOf( I_result ), AddressOf( P_homography ), AddressOf( P_point ) )
    return I_result

def transform3D( P_dll, P_homography: Matrix4D, P_point: Coord3D ):
    I_result = Coord3D()
    P_dll.IceRayC_Type_Math_Homography_Transform3D( AddressOf( I_result ), AddressOf( P_homography ), AddressOf( P_point ) )
    return I_result

def construct3D( P_dll
            ,P_tO : Coord3D, P_tX : Coord3D, P_tY : Coord3D, P_tZ : Coord3D, P_tT : Coord3D
            ,P_sO : Coord3D, P_sX : Coord3D, P_sY : Coord3D, P_sZ : Coord3D, P_sT : Coord3D
    ):
    result = Matrix4D()
    P_dll.IceRayC_Type_Math_Homography_Construct3D( AddressOf( result )
     ,AddressOf( P_tO ), AddressOf( P_tX ), AddressOf( P_tY ), AddressOf( P_tZ ), AddressOf( P_tT )
     ,AddressOf( P_sO ), AddressOf( P_sX ), AddressOf( P_sY ), AddressOf( P_sZ ), AddressOf( P_sT )
     )
    return result

#print( '</' + __name__ + ' name=\'' +   __file__ + '\''+ '>' )
