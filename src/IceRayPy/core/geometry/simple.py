#print( '<' + __name__ + ' name=\'' +   __file__ + '\''+ '>' )
import ctypes



import IceRayPy.type
import IceRayPy.type.math
import IceRayPy.type.math.coord
import IceRayPy.core.geometry

Pointer  = ctypes.POINTER
AddressOf = ctypes.addressof

Scalar  = IceRayPy.type.basic.Scalar
VoidPtr = IceRayPy.type.basic.VoidPtr
Integer = IceRayPy.type.basic.Integer
Coord3D = IceRayPy.type.math.coord.Scalar3D
Matrix3D = IceRayPy.type.math.matrix.Scalar3D


class Sphere : #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll,  P_center = None , P_radius = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Sphere0()

        if None != P_center:
            self.center( P_center )

        if None != P_radius:
            self.radius( P_radius )

        return

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def center( self, P_center : Coord3D ):
        return self.m_cargo['dll'].IceRayC_Geometry_Sphere_Center( self.m_cargo['this'], AddressOf( P_center ) )

    def radius( self, P_radius ):
        self.m_cargo['dll'].IceRayC_Geometry_Sphere_Radius( self.m_cargo['this'], Scalar( P_radius ) )


class Cone: #( IceRayPy.core.geometry.Generic ):

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Cone0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

class Cylinder: #( IceRayPy.core.geometry.Generic ):

    def __init__( self, P_dll, P_radius = None, P_height = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Cylinder0()
        if None != P_radius:
            self.radius( P_radius )
        if None != P_height:
            self.height( P_height )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def radius( self, P_radius ):
        self.m_cargo['dll'].IceRayC_Geometry_Cylinder_Radius( self.m_cargo['this'], Scalar( P_radius ) )

    def height( self, height ):
        self.m_cargo['dll'].IceRayC_Geometry_Cylinder_Height( self.m_cargo['this'], Scalar( height ) )



class Ellipsoid:  #( IceRayPy.core.geometry.Generic ):

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def center( self, P_center: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid_Center( self.m_cargo['this'], AddressOf( P_center ) )

    def radiusS( self, P_radius ):
        return self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid_RadiusS( self.m_cargo['this'], Scalar( P_radius ) )

    def radiusV( self, P_radius: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid_RadiusV( self.m_cargo['this'], AddressOf( P_radius ) )

    def system( self, P_eX: Coord3D, P_eY: Coord3D, P_eZ: Coord3D ):
        return self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid_RadiusV( self.m_cargo['this'], AddressOf( P_eX ), AddressOf( P_eY ), AddressOf( P_eZ ) )


class Hyperboloid:  #( IceRayPy.core.geometry.Generic ):

    def __init__( self, P_dll, P_core = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Hyperboloid0()
        if(  None != P_core ):
            self.core( P_core )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def core( self, P_core ):
        self.m_cargo['dll'].IceRayC_Geometry_Hyperboloid_Core( self.m_cargo['this'], Scalar( P_core ) )


class Paraboloid:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Paraboloid0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )



class Quadric:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Quadric0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def lo( self, P_lo = None ):
        if( None != P_lo ):
            self.m_cargo['dll'].IceRayC_Geometry_Quadric_Lo_Set( self.m_cargo['this'], AddressOf( P_lo ) )
        result = Coord3D()
        self.m_cargo['dll'].IceRayC_Geometry_Quadric_Lo_Get( self.m_cargo['this'], AddressOf( result ) )
        return result

    def hi( self, P_hi ):
        if( None != P_hi ):
            self.m_cargo['dll'].IceRayC_Geometry_Quadric_Hi_Set( self.m_cargo['this'], AddressOf( P_hi ) )
        result = Coord3D()
        self.m_cargo['dll'].IceRayC_Geometry_Quadric_Hi_Get( self.m_cargo['this'], AddressOf( result ) )
        return result

    def matrix( self, P_matrix ):
        if( None != P_matrix ):
            self.m_cargo['dll'].IceRayC_Geometry_Quadric_Matrix_Set( self.m_cargo['this'], AddressOf( P_matrix ) )
        result = Matrix3D()
        self.m_cargo['dll'].IceRayC_Geometry_Quadric_Matrix_Get( self.m_cargo['this'], AddressOf( result ) )
        return result

    def vector( self, P_vector ):
        if( None != P_vector ):
            self.m_cargo['dll'].IceRayC_Geometry_Quadric_Vector_Set( self.m_cargo['this'], AddressOf( P_vector ) )
        result = Coord3D()
        self.m_cargo['dll'].IceRayC_Geometry_Quadric_Vector_Get( self.m_cargo['this'], AddressOf( result ) )
        return result

    def scalar( self, P_scalar ):
        if( None != P_scalar ):
            self.m_cargo['dll'].IceRayC_Geometry_Quadric_Scalar_Set( self.m_cargo['this'], Scalar( P_scalar ) )
        result = Scalar()
        self.m_cargo['dll'].IceRayC_Geometry_Quadric_Scalar_Get( self.m_cargo['this'], AddressOf( result ) )
        return result


class Saddle:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Saddle0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )


class Torus:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll, P_minor = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Torus0()
        if( None != P_minor ):
            self.minor( P_minor )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def minor( self, P_minor ):
        self.m_cargo['dll'].IceRayC_Geometry_Torus_Minor( self.m_cargo['this'], Scalar( P_minor ) )




class CylinderU:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_CylinderU0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )


class SphereU:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_USphere0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )


#print( '</' + __name__ + ' name=\'' +   __file__ + '\''+ '>' )
