class Image
    def __init__(self, P_dll, P_picture = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pattern_Color_Image0()
        self.picture( P_picture )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pattern_Color_Release( self.m_cargo['this'] )

    def picture( slef, P_picture ):
        if( None == P_picture ):
            return

        self.m_cargo['picture'] = P_picture
        self.m_cargo['dll'].IceRayC_Material_Pattern_Color_Image_Picture( self.m_cargo['this'], P_picture['this'] )
