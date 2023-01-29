print( '<' + __name__ + ' name=\'' +   __file__ + '\''+ '>' )
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

def construct1D( P_dll, P_A, P_B ):
    result = Matrix2D()
    P_dll.IceRayC_Type_Math_Homography_Construct1D( AddressOf( result ), Scalar( P_A ), Scalar( P_B ) )
    return result

def construct2D( P_dll, P_point ):
    result = Matrix3D()
    P_dll.IceRayC_Type_Math_Homography_Construct2D( AddressOf( result ), AddressOf( P_point ) )
    return result

def construct3D( P_dll, P_point ):
    result = Matrix4D()
    P_dll.IceRayC_Type_Math_Homography_Construct3D( AddressOf( result ), AddressOf( P_point ) )
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

print( '</' + __name__ + ' name=\'' +   __file__ + '\''+ '>' )
