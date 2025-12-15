#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import math
import IceRayPy

Coord3D = IceRayPy.type.math.coord.Scalar3D
Matrix3D = IceRayPy.type.math.matrix.Scalar3D


def Sphere( P_dll, P_dummy = None ):
    return IceRayPy.core.geometry.simple.Quadric( P_dll )

def Cylinder( P_dll, P_dummy = None ):
    result = IceRayPy.core.geometry.simple.Quadric( P_dll )
    matrix = IceRayPy.type.math.matrix.id3D(P_dll)
    matrix.a33 = 0;
    result.matrix( matrix )
    result.scalar( -1 )
    return result

def Paraboloid( P_dll, P_dummy = None ):
    result = IceRayPy.core.geometry.simple.Quadric( P_dll )
    matrix = IceRayPy.type.math.matrix.id3D(P_dll)
    matrix.a33 = 0;
    result.matrix( matrix )
    vector = Coord3D(0,0,-1)
    result.vector( vector )
    result.scalar( 0 )
    return result

def Saddle( P_dll, P_dummy = None ):
    result = IceRayPy.core.geometry.simple.Quadric( P_dll )
    matrix = IceRayPy.type.math.matrix.id3D(P_dll)
    matrix.a22 = -1;
    matrix.a33 = 0;
    result.matrix( matrix )
    vector = Coord3D(0,0,-1)
    result.vector( vector )
    result.scalar( 0 )
    return result

def Nuke( P_dll, P_dummy = None ):
    result = IceRayPy.core.geometry.simple.Quadric( P_dll )
    matrix = IceRayPy.type.math.matrix.id3D(P_dll)
    matrix.a33 = -1;
    result.matrix( matrix )
    result.scalar( -0.5 )
    return result

def Cone( P_dll, P_dummy = None ):
    result = IceRayPy.core.geometry.simple.Quadric( P_dll )
    matrix = IceRayPy.type.math.matrix.id3D(P_dll)
    matrix.a33 = -1;
    result.matrix( matrix )
    result.scalar( 0 )
    return result

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )