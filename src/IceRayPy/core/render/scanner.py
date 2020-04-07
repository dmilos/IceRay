
class Block:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Scanner_Block0()


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Scanner_Release( self.m_cargo['this'] )

class Parallel:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Scanner_Parallel0()


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Scanner_Release( self.m_cargo['this'] )
