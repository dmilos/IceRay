class Object:

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_RTSS_Object0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def push( P_child ):
        self.m_cargo['dll'].IceRayC_Geometry_RTSS_Object_Push( self.m_cargo['this'], TODO )
        pass #TODO

    def rtss( P_rtss ):
        self.m_cargo['dll'].IceRayC_Geometry_RTSS_Object_Rtss( self.m_cargo['this'], TODO )
        pass #TODO

class List:

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_RTSS_List0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

class Uniform:

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_RTSS_Uniform0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def size( self, P_size ):
        pass
        #TODO self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )
