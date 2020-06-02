import ctypes

print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )


import IceRayPy.type
import IceRayPy.type.math
import IceRayPy.type.math.coord
import IceRayPy.core.geometry

Pointer  = ctypes.POINTER
AddresOf = ctypes.addressof

Scalar  = IceRayPy.type.basic.Scalar
VoidPtr = IceRayPy.type.basic.VoidPtr
Integer = IceRayPy.type.basic.Integer
Coord3D = IceRayPy.type.math.coord.Scalar3D


class Sphere : #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll,  P_center = None , P_radius = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Sphere0()

        # TODOif None != P_center:
        # TODO    self.m_cargo['dll'].IceRayC_Geometry_Sphere_Center()
        # TODO
        # TODOif None != P_radius:
        # TODO    slef.m_cargo['this'] = IceRayC_Geometry_Sphere_Radius( P_radius )
        # TODO    return

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def center( self, P_center : Coord3D ):
        return self.m_cargo['dll'].IceRayC_Geometry_Sphere_Center( self.m_cargo['this'], AddresOf( P_center ) )

    def radius( self, P_radius ):
        self.m_cargo['dll'].IceRayC_Geometry_Sphere_Radius( self.m_cargo['this'], Scalar( P_radius) )


class Box: #( IceRayPy.core.geometry.Generic ):

    def __init__( self, P_dll,  P_lo = None , P_hi = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Box0()
        #self.hi( Coord3D(1,1,0) ) #TODO remove

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def lo( self, P_lo: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Box_Lo( self.m_cargo['this'], AddresOf( P_lo ) )

    def hi( self, P_hi: Coord3D ):
        return self.m_cargo['dll'].IceRayC_Geometry_Box_Hi( self.m_cargo['this'], AddresOf( P_hi ) )

    def box( self, P_lo: Coord3D, P_hi: Coord3D ):
        self.lo( P_lo )
        self.hi( P_hi )


class Cone: #( IceRayPy.core.geometry.Generic ):

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Cone0()

        # TODO lo hi

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )


class Cylinder: #( IceRayPy.core.geometry.Generic ):

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Cylinder0()

        # TODO lo hi, radius

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )


class Disc: #( IceRayPy.core.geometry.Generic ):

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Disc0()

        # TODO lo hi

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def radius( self, P_radius ):
        self.m_cargo['dll'].IceRayC_Geometry_Disc_Radius( self.m_cargo['this'], Scalar( P_radius ) )

    def center( self, P_center: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Disc_Center( self.m_cargo['this'], AddresOf( P_center ) )

    def normal( self, P_normal: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Disc_Normal( self.m_cargo['this'], AddresOf( P_normal ) )


class Ellipsoid:  #( IceRayPy.core.geometry.Generic ):

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def center( self, P_center: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid_Center( self.m_cargo['this'], AddresOf( P_center ) )

    def radiusS( self, P_radius ):
        return self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid_RadiusS( self.m_cargo['this'], Scalar( P_radius ) )

    def radiusV( self, P_radius: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid_RadiusV( self.m_cargo['this'], AddresOf( P_radius ) )

    def system( self, P_eX: Coord3D, P_eY: Coord3D, P_eZ: Coord3D ):
        return self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid_RadiusV( self.m_cargo['this'], AddresOf( P_eX ), AddresOf( P_eY ), AddresOf( P_eZ ) )


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

    # def radius( self, P_radius  ):
    #     self.m_cargo['dll'].IceRayC_Geometry_Paraoloid_Radius( self.m_cargo['this'], Scalar( P_radius ) )


class Plane:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Plane0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def origin( self, P_origin: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Plane_Origin( self.m_cargo['this'], AddresOf( P_origin ) )

    def normal( self, P_normal: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Plane_Normal( self.m_cargo['this'], AddresOf( P_normal ) )


class Quadric:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Quadric0()

        # TODO lo hi

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )


class Saddle:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Saddle0()

        # TODO lo hi

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )


class Torus:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Torus0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def minor( self, P_minor ):
        self.m_cargo['dll'].IceRayC_Geometry_Torus_Minor( self.m_cargo['this'], Scalar( P_minor ) )


class Triangle:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Triangle0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def origin( self, P_origin: Coord3D  ): #TODO
        return self.m_cargo['dll'].IceRayC_Geometry_Triangle_Origin( self.m_cargo['this'], AddresOf( P_origin ) )

    def eX( self, P_eX: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Triangle_eX( self.m_cargo['this'], AddresOf( P_eX ) )

    def eY( self, P_eY: Coord3D  ):
        return self.m_cargo['dll'].IceRayC_Geometry_Triangle_eY( self.m_cargo['this'], AddresOf( P_eY ) )


class UCylinder:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_UCylinder0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )


class USphere:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_USphere0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )


print( '</' + __name__ + ' name=\'' +   __file__ + '\'>' )
