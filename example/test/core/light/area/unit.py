import math
import IceRayCpp

def name( ):
    return "area"

def make( P_height = 1 + 1 + (math.sqrt(5)-1)/2, P_sample = 32 ):

    area = IceRayCpp.LightArea()
    area.origin( IceRayCpp.MathTypeCoord3D().load(-1,-1,P_height) )
    area.x( IceRayCpp.MathTypeCoord3D().load( 2, 0, 0 ) )
    area.y( IceRayCpp.MathTypeCoord3D().load( 0, 2, 0 ) )
    area.sample( P_sample )

    return { 'this': area }

