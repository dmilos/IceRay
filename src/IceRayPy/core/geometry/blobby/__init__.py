print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )
print( '</' + __name__ + ' name=\'' +   __file__ + '/>' )


class System:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Blobby_System0()

        # TODOif None == P_center:
        # TODO    self.m_cargo['dll'].IceRayC_Geometry_Sphere_Center()
        # TODO
        # TODOif None == P_radius:
        # TODO    slef.m_cargo['this'] = IceRayC_Geometry_Sphere_Radius( P_radius )
        # TODO    return

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )

    def push( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Blobby_System_Push( self.m_cargo['this'] )

    def rtss( self, P_rtss ):
        self.m_cargo['dll'].IceRayC_Geometry_RTSS_Release( self.m_cargo['this'], P_rtss.m_cargo['this'] )
        self.m_cargo['rtss'] = P_rtss
