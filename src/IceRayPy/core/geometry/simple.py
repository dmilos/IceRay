import ctypes

import IceRayPy.type
import IceRayPy.type.math
import IceRayPy.type.math.coord

Scalar = ctypes.c_double
Coord3D = IceRayPy.type.math.coord.Scalar3D


class Sphere:
    def __init__( self, P_dll,  P_center = None , P_radius = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Sphere0()

        # TODOif None == P_center:
        # TODO    self.m_cargo['dll'].IceRayC_Geometry_Sphere_Center()
        # TODO
        # TODOif None == P_radius:
        # TODO    slef.m_cargo['this'] = IceRayC_Geometry_Sphere_Radius( P_radius )
        # TODO    return

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def center( self, P_center : Coord3D ):
        self.m_cargo['dll'].IceRayC_Geometry_Sphere_Center( self.m_cargo['this'], P_center )

    def radius( self, P_radius ):
        self.m_cargo['dll'].IceRayC_Geometry_Sphere_Radius( self.m_cargo['this'], Scalar( P_radius) )


class Box:

    def __init__( self, P_dll,  P_lo = None , P_hi = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Box0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def lo( self, P_lo: Coord3D  ):
        self.m_cargo['dll'].IceRayC_Geometry_Box_Lo( self.m_cargo['this'], P_lo )

    def hi( self, P_hi: Coord3D  ):
        self.m_cargo['dll'].IceRayC_Geometry_Box_Hi( self.m_cargo['this'], P_hi )


class Cone:

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Cone0()

        # TODO lo hi

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

class Cylinder:

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Cylinder0()

        # TODO lo hi, radius

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

class Disc:

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
        self.m_cargo['dll'].IceRayC_Geometry_Disc_Radius( self.m_cargo['this'], P_center )

class Ellipsoid:

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def center( self, P_center: Coord3D  ):
        self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid_Center( self.m_cargo['this'], P_center )

    def radiusS( self, P_radius ):
        self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid_RadiusS( self.m_cargo['this'], Scalar( P_radius ) )

    def radiusV( self, P_radius: Coord3D  ):
        self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid_RadiusV( self.m_cargo['this'], P_radius )

    def system( self, P_system ):
        self.m_cargo['dll'].IceRayC_Geometry_Ellipsoid_System( self.m_cargo['this'], P_system )


class Hyperboloid:

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Hyperboloid0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def core( self, P_core ):
        self.m_cargo['dll'].IceRayC_Geometry_Hyperboloid_Core( self.m_cargo['this'], Scalar( P_core ) )


class Paraboloid:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Paraboloid0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    # def radius( self, P_radius  ):
    #     self.m_cargo['dll'].IceRayC_Geometry_Paraoloid_Radius( self.m_cargo['this'], Scalar( P_radius ) )


class Plane:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Paraboloid0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def origin( self, P_point: Coord3D  ):
        self.m_cargo['dll'].IceRayC_Geometry_Plane_Origin( self.m_cargo['this'], P_point )

    def normal( self, P_normal: Coord3D  ):
        self.m_cargo['dll'].IceRayC_Geometry_Plane_Normal( self.m_cargo['this'], P_normal )


class Quadric:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Quadric0()

        # TODO lo hi

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

class Saddle:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Saddle0()

        # TODO lo hi

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

class Torus:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Torus0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def minor( self, P_minor ):
        self.m_cargo['dll'].IceRayC_Geometry_Torus_Minor( self.m_cargo['this'], Scalar( P_minor ) )


class Triangle:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Triangle0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def p0( self, P_0: Coord3D  ): #TODO
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )


class UCylinder:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_UCylinder0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

class USphere:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_USphere0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )
