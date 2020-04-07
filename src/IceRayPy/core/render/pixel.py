
class Constant:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Pixel_Constant0()


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Release( self.m_cargo['this'] )

class UV:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Pixel_UV0()


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Release( self.m_cargo['this'] )

class Basic:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_PixelBasic0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Pixel_Release( self.m_cargo['this'] )
