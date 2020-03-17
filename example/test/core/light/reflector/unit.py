import math
import IceRayCpp

def name( ):
    return "reflector"

def make( P_height = 1 + 1 + (math.sqrt(5)-1)/2 ):

    reflector = IceRayCpp.LightReflector(  )

    reflector.center( IceRayCpp.MathTypeCoord3D().load( 0, 0, P_height ) )

    reflector.direction( IceRayCpp.MathTypeCoord3D().load(0,0,-1) )

    reflector.inner( 1 )
    reflector.outer( 2 )

    return { 'this': reflector }
