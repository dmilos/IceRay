import math
import IceRayCpp

def name( ):
    return "disc"

def make( P_height = 1 + 1 + (math.sqrt(5)-1)/2, P_sample = 32 ):

    disc = IceRayCpp.LightDisc()
    disc.center( IceRayCpp.MathTypeCoord3D().load( 0, 0, P_height ) )
    disc.x( IceRayCpp.MathTypeCoord3D().load( 1, 0, 0 ) )
    disc.y( IceRayCpp.MathTypeCoord3D().load( 0, 1, 0 ) )
    disc.sample( P_sample )

    return { 'this': disc }

