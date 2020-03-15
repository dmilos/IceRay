import math
import IceRayCpp

def name( ):
    return "circle"

def make( P_height = 1 + 1 + (math.sqrt(5)-1)/2, P_sample = 32 ):

    circle =  IceRayCpp.LightCircle()

    circle.center( IceRayCpp.MathTypeCoord3D().load( 0, 0, P_height ) )
    ##circle.x( IceRayCpp.MathTypeCoord3D().load( 0, 0, 0 ) )
    ##circle.y( IceRayCpp.MathTypeCoord3D().load( 0, 0, 0 ) )

    circle.sample( P_sample )

    return { 'this': circle }
