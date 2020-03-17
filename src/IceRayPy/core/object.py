class Object:
    def __init__( self, P_dll, P_geometry = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Object0()
        self.m_cargo['geometry'] ={}; self.m_cargo['geometry']['own'] = False
        self.m_cargo['medium'] ={};   self.m_cargo['medium']['own'] = False
        self.m_cargo['pigment'] ={};  self.m_cargo['pigment']['own'] = False
        if( None != P_geometry ):
            self.geometry( P_geometry )

    def __del__( self ):
        #self.m_cargo['dll'].IceRayC_Object_Release( self.m_cargo['this'] )
        #if( True == self.m_cargo['geometry']['own'] ):
        #    self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['geometry']['cargo']['this'] )
        #if( True == self.m_cargo['medium']['own'] ):
        #    self.m_cargo['dll'].IceRayC_Medium_Release( self.m_cargo['medium']['cargo']['this'] )
        #if( True == self.m_cargo['pigment']['own'] ):
        #    self.m_cargo['dll'].IceRayC_Pigment_Release( self.m_cargo['pigment']['cargo']['this'] )
        pass

    def geometry( self,P_geometry, P_own = False ):
        if( True ==  self.m_cargo['geometry']['own'] ):
            self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['geometry']['cargo']['this'] )

        self.m_cargo['dll'].IceRayC_Object_Geometry( self.m_cargo['this'], P_geometry['this'] )
        self.m_cargo['geometry']['cargo'] = P_geometry;
        if( True == P_own ):
            self.m_cargo['geometry']['own'] = True

    def pigment(self, P_pigment, P_own = False):
        if( True ==  self.m_cargo['pigment']['own'] ):
            self.m_cargo['dll'].IceRayC_Pigment_Release( self.m_cargo['pigment']['cargo']['this'] )

        self.m_cargo['dll'].IceRayC_Object_Pigment( self.m_cargo['this'], P_pigment['this'] )
        self.m_cargo['pigment']['cargo'] = P_pigment;
        if( True == P_own ):
            self.m_cargo['pigment']['own'] = True

    def medium(self, P_medium, P_own = False):
        if( True ==  self.m_cargo['medium']['own'] ):
            self.m_cargo['dll'].IceRayC_Medium_Release( self.m_cargo['medium']['cargo']['this'] )

        self.m_cargo['dll'].IceRayC_Object_Medium( self.m_cargo['this'], P_medium['this'] )
        self.m_cargo['medium']['cargo'] = P_medium;
        if( True == P_own ):
            self.m_cargo['medium']['own'] = True

