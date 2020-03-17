import math
import IceRayCpp

def name( ):
    return "suns"


def make( P_height = 1 + (math.sqrt(5)-1)/2 ):

    sun = IceRayCpp.LightSunSpot()

    sun.spot( IceRayCpp.LightTypeSpot() )
    sun.center( IceRayCpp.MathTypeCoord3D().load(0,0,P_height) )

    return { 'this': sun }

