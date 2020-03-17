class Identical:

    def __init__( self, P_dll,  P_child = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_Identical0()


    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Identical_Child( self.m_cargo['this'], self.m_cargo['child']['this'] )

class Translate:

    def __init__( self, P_dll,  P_child = None , P_move = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_Translate0()

        if( None != P_child ):
            self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_Translate_Child(  self.m_cargo['this'], self.m_cargo['child']['this'])

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Translate_Child( self.m_cargo['this'], self.m_cargo['child']['this'] )

class Affine:

    def __init__( self, P_dll,  P_child = None , P_affine = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine0()

        if( None != P_child ):
            self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine_Child(  self.m_cargo['this'], self.m_cargo['child']['this'])

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Geometry_Release( self.m_cargo['this'] )
        self.m_cargo['child'] = None

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Geometry_Transform_Affine_Child( self.m_cargo['this'], self.m_cargo['child']['this'] )

