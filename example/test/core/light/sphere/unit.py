import math
import IceRayCpp

def name( ):
    return "sphere"

def make( P_height = 1 + 1 + (math.sqrt(5)-1)/2, P_sample = 32, P_radius = 0.3 ):

    sphere = IceRayCpp.LightSphere()

    sphere.center( IceRayCpp.MathTypeCoord3D().load(0,0,P_height) )
    sphere.radius( P_radius )
    sphere.sample( P_sample )

    return { 'this': sphere }