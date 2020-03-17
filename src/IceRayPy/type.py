class Picture:

    def __init__(self, P_dll, P_filename = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Type_Picture0()
        if( None != P_filename ):
            self.load( P_filename )
            
    def __del__(self):
        self.m_cargo['dll'].IceRayC_Type_Picture_Release( self.m_cargo['this'] )
        
    def load(self, P_filename )
        self.m_cargo['dll'].IceRayC_Type_Picture_Load( self.m_cargo['this'], c_str( P_filename) )

