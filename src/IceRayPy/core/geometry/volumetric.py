import ctypes

import IceRayPy
import IceRayPy.type.math.interval

Pointer  = ctypes.POINTER
AddressOf = ctypes.addressof

Scalar      = IceRayPy.type.basic.Scalar
Coord3D     = IceRayPy.type.math.coord.Scalar3D
Interval3D  = IceRayPy.type.math.interval.Scalar3D

class Vacuum:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Vacuum0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def lo( self, P_lo : Coord3D):
        self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Vacuum_Lo( self.m_cargo['this'], AddressOf(P_lo) )

    def hi( self, P_hi : Coord3D ):
        self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Vacuum_Hi( self.m_cargo['this'], AddressOf(P_hi) )

    def box( self, P_box :Interval3D ):
        self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Vacuum_Box( self.m_cargo['this'], AddressOf( P_box ) )


class Mist:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Smoke0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def hull( self, P_hull ):
        self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Smoke_Hull( self.m_cargo['this'], P_hull.m_cargo['this'] )
        self.m_cargo['hull'] = P_hull

    def density( self, P_density ):
        self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Mist_Density( self.m_cargo['this'], Scalar( P_density ) )

    def precision( self, P_precision ):
        self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Mist_Precision( self.m_cargo['this'], Scalar( P_precision ) )

class Smoke:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Smoke0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def hull( self, P_hull ):
        self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Smoke_Hull( self.m_cargo['this'], P_hull.m_cargo['this'] )
        self.m_cargo['hull'] = P_hull

