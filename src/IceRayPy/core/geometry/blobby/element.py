import ctypes

import IceRayPy

Scalar = IceRayPy.type.basic.Scalar
AddressOf = ctypes.addressof

class Sphere:
    def __init__( self, P_dll, P_center = None , P_radius = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Sphere0()

        #if None != P_center:
        #    self.center( P_center )
        #
        #if None != P_radius:
        #    self.radius( P_radius )
        #    return

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Release( self.m_cargo['this'] )

    def center( self, P_center ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Sphere_Center( self.m_cargo['this'], AddressOf( P_center ) )

    def core( self, P_radius ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Sphere_Core( self.m_cargo['this'], Scalar( P_radius) )

    def radius( self, P_radius ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Sphere_Radius( self.m_cargo['this'], Scalar( P_radius) )

class Cylinder:
    def __init__( self, P_dll, P_center = None , P_radius = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Cylinder0()

        # TODOif None != P_center:
        # TODO    self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Cylinder_Center()
        # TODO
        # TODOif None != P_radius:
        # TODO    self.m_cargo['this'] = IceRayC_Geometry_Blobby_Element_Cylinder_Radius( P_radius )
        # TODO    return

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Release( self.m_cargo['this'] )

    def bottom( self, P_bottom ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Cylinder_Bottom( self.m_cargo['this'], AddressOf( P_bottom ) )

    def top( self, P_top ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Cylinder_Top( self.m_cargo['this'], AddressOf( P_top ) )

    def core( self, P_core ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Cylinder_Core( self.m_cargo['this'], Scalar( P_core ) )

    def radius( self, P_radius ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Cylinder_Radius( self.m_cargo['this'], Scalar( P_radius ) )

class WatterZ:
    def __init__( self, P_dll, P_center = None , P_radius = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Cylinder0()

        # TODOif None != P_center:
        # TODO    self.m_cargo['dll'].IceRayC_Geometry_Cylinder_Center()
        # TODO
        # TODOif None != P_radius:
        # TODO    self.m_cargo['this'] = IceRayC_Geometry_Cylinder_Radius( P_radius )
        # TODO    return

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Release( self.m_cargo['this'] )

    def bottom( self, P_bottom ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Cylinder_Bottom( self.m_cargo['this'], P_bottom )

    def level( self, P_level ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Cylinder_Core( self.m_cargo['this'], Scalar( ( P_level ) ) )

class Vacuum:
    def __init__( self, P_dll, P_center = None , P_radius = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Vacuum0()

        # TODOif None != P_center:
        # TODO    self.m_cargo['dll'].IceRayC_Geometry_Vacuum_Center()
        # TODO
        # TODOif None != P_radius:
        # TODO    self.m_cargo['this'] = IceRayC_Geometry_Vacuum_Radius( P_radius )
        # TODO    return

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Release( self.m_cargo['this'] )

    def lo( self, P_bottom ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Vacuum_Lo( self.m_cargo['this'], P_bottom )

    def hi( self, P_top ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Vacuum_Hi( self.m_cargo['this'], P_top )

class Affine:
    def __init__( self, P_dll, P_center = None , P_radius = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Affine0()

        # TODOif None != P_center:
        # TODO    self.m_cargo['dll'].IceRayC_Geometry_Affine_Center()
        # TODO
        # TODOif None != P_radius:
        # TODO    self.m_cargo['this'] = IceRayC_Geometry_Affine_Radius( P_radius )
        # TODO    return

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Release( self.m_cargo['this'] )

class Translate:
    def __init__( self, P_dll, P_center = None , P_radius = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Translate0()

        # TODOif None == P_center:
        # TODO    self.m_cargo['dll'].IceRayC_Geometry_Affine_Center()
        # TODO
        # TODOif None == P_radius:
        # TODO    self.m_cargo['this'] = IceRayC_Geometry_Affine_Radius( P_radius )
        # TODO    return

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_Element_Release( self.m_cargo['this'] )

