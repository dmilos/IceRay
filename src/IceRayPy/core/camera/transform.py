import sys
#print( '<' + __name__ + '>' )
import IceRayCpp

class Transform:
    m_child = None
    def __init__( self, P_child = IceRayCpp.CameraFlatPerspective() ):
        P_child = self.m_child

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

#print( '</' + __name__ + '>' )
