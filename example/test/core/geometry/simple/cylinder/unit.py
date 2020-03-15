import math
import IceRayCpp

def name( ):
    return "cylinder"

def make( P_radius = (math.sqrt(5)-1)/2 ):
    geometry = IceRayCpp.GeometrySimpleCylinder()
    geometry.radius( P_radius )

    return { 'this': geometry }