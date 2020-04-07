
class UV:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Pierce_UV0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Pierce_Release( self.m_cargo['this'] )

class Projector:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Pierce_Projector0()

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Render_Pierce_Release( self.m_cargo['this'] )

    def camera( self, P_camera ):
        self.m_cargo['dll'].IceRayC_Render_Pierce_Projector_Camera( self.m_cargo['this'], P_camera.m_cargo['this'] )
        self.m_cargo['object'] = P_camera

    def sheaf( self, P_sheaf ):
        self.m_cargo['dll'].IceRayC_Render_Pierce_Projector_Sheaf( self.m_cargo['this'], P_sheaf.m_cargo['this'] )
        self.m_cargo['object'] = P_sheaf

