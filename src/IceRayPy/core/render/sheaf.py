
class ALL:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Sheaf_ALL0()


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Sheaf_Release( self.m_cargo['this'] )

class First:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Sheaf_First0()


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Sheaf_Release( self.m_cargo['this'] )

class Random:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Sheaf_Random0()


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Sheaf_Release( self.m_cargo['this'] )
