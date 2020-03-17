class Intersect:

    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Complex_Intersect0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def left( self, P_left, P_where = None ):
        if( None == P_where ):
            self.m_cargo['dll'].IceRayC_Geometry_Complex_Intersect_Left0( self.m_cargo['this'], P_left['this'] )
        else:
            self.m_cargo['dll'].IceRayC_Geometry_Complex_Intersect_Left1( self.m_cargo['this'], P_left['this'], P_where )

    def right( self, P_right, P_where = None ):
        if( None == P_where ):
            self.m_cargo['dll'].IceRayC_Geometry_Complex_Intersect_Right0( self.m_cargo['this'], P_left['this'] )
        else:
            self.m_cargo['dll'].IceRayC_Geometry_Complex_Intersect_Right1( self.m_cargo['this'], P_left['this'], P_where )
