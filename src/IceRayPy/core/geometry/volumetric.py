import ctypes

Scalar = ctypes.c_double

class Vacuum:

    def __init__( self, P_dll,  P_child = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Vacuum0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

    def lo( self, P_lo ):
        pass #TODO

    def hi( self, P_lo ):
        pass #TODO

    def box( self, P_lo ):
        pass #TODO

    def box( self, P_lo, P_hi ):
        pass #TODO

class Mist:

    def __init__( self, P_dll,  P_child = None ):
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

    def __init__( self, P_dll,  P_child = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Smoke0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def hull( self, P_hull ):
        self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Smoke_Hull( self.m_cargo['this'], P_hull.m_cargo['this'] )
        self.m_cargo['hull'] = P_hull
