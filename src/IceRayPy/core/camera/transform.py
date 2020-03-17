
class Invert:
    def __init__( self, P_dll, P_child = None ):
        self.m_cargo={}
        self.m_cargo['dll']= P_dll
        self.m_cargo['child']= {}

        if( None != P_child ):
            self.chid( P_child )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )
        #TODO self.m_cargo['child']['this']

    def child(self):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        #TODO self.m_cargo['child']['this']
        pass

class Affine:

    def __init__( self, P_dll ):
        self.m_cargo={}
        self.m_cargo['dll']= P_dll
        if( None != P_child ):
            self.chid( P_child )

    def __del__( self ):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def child( self ):
        return self.m_cargo['child'];

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        #TODO self.m_cargo['child']['this']


    def move( self, P_move ):
        pass

    def move( self, P_scale ):
        pass

    def rotateX( self, P_angle ):
        pass

    def rotateY( self, P_angle ):
        pass

    def rotateZ( self, P_angle ):
        pass

    def rotateA( self, P_direction, P_alpha ):
        pass

    def rotatePitch( self, P_angle ):
        pass

    def rotateJaw( self, P_angle ):
        pass

    def rotateRoll( self, P_angle ):
        pass

