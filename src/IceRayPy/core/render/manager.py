
class TheOne:
    m_cargo  = {}

    def __init__( self, P_dll ):
        self.m_cargo={}

        self.m_cargo['dll']=P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Render_Engine0()


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_RenderEngine_Release( self.m_cargo['this'] )

    def scanner( self, P_scanner ):
        self.m_cargo['scanner'] = P_scanner
        self.m_cargo['dll'].IceRayC_Render_Engine_Scanner( self.m_cargo['this'], P_scanner.m_cargo['this']  )

    def pixel( self, P_pixel ):
        self.m_cargo['scanner'] = P_pixel
        self.m_cargo['dll'].IceRayC_Render_Engine_Pixel( self.m_cargo['this'], P_pixel.m_cargo['this']  )

    def pierce( self, P_pierce ):
        self.m_cargo['pierce'] = P_pierce
        self.m_cargo['dll'].IceRayC_Render_Engine_Pierce( self.m_cargo['this'], P_pierce.m_cargo['this']  )

    def sheaf( self, P_sheaf ):
        self.m_cargo['sheaf'] = P_sheaf
        self.m_cargo['dll'].IceRayC_Render_Engine_Sheaf( self.m_cargo['this'], P_sheaf.m_cargo['this']  )

    def ray( self, P_ray ):
        self.m_cargo['ray'] = P_ray
        self.m_cargo['dll'].IceRayC_Render_Engine_Ray( self.m_cargo['this'], P_ray.m_cargo['this']  )

    def start( self, P_picture ):
        self.m_cargo['dll'].IceRayC_Render_Engine_Start( self.m_cargo['this'], P_picture.m_cargo['this'] )

    def stop( self ):
        self.m_cargo['dll'].IceRayC_Render_Engine_Stop( self.m_cargo['this'] )

    def progress( self ):
        self.m_cargo['dll'].IceRayC_Render_Engine_Stop( self.m_cargo['this'] )



