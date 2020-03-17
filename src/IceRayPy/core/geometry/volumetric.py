class Vacuum:

    def __init__( self, P_dll,  P_child = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Vacuum0()


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Light_Release( self.m_cargo['this'] )

class Smoke:

    def __init__( self, P_dll,  P_child = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Volumetric_Smoke0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

