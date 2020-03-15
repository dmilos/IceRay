import math
import IceRayCpp

def name( ):
    return "spline"

def make( P_height = 1 + 1 + (math.sqrt(5)-1)/2, P_sample = 32 ):
    spline = IceRayCpp.LightSpline()

    spline.cp( 0, IceRayCpp.MathTypeCoord3D().load( -1, -1, P_height ) )
    spline.cp( 1, IceRayCpp.MathTypeCoord3D().load(  1, -1, P_height ) )
    spline.cp( 2, IceRayCpp.MathTypeCoord3D().load( -1,  1, P_height ) )
    spline.cp( 3, IceRayCpp.MathTypeCoord3D().load(  1,  1, P_height ) )

    spline.sample( P_sample )

    return { 'this': spline }
