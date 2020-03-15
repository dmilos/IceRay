import math
import IceRayCpp

def name( ):
    return "line"

def make( P_height = 1 + 1 + (math.sqrt(5)-1)/2, P_sample = 32 ):

    line = IceRayCpp.LightLine()

    line.start( IceRayCpp.MathTypeCoord3D().load( -2, -2, P_height ) )
    line.end(  IceRayCpp.MathTypeCoord3D().load(   2,  2, P_height ) )

    #line.start( IceRayCpp.MathTypeCoord3D().load(  0,  0, 3 ) )
    #line.end(  IceRayCpp.MathTypeCoord3D().load(   0,  0, 3 ) )

    line.sample( P_sample )

    return { 'this': line }
