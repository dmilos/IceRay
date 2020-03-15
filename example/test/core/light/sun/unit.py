import math
import IceRayCpp

def name( ):
    return "sun"

def area( P_height = 1 + 1 + (math.sqrt(5)-1)/2, P_sample = 100 ):

    sun = IceRayCpp.LightSun()

    area = IceRayCpp.LightArea()
    area.origin( IceRayCpp.MathTypeCoord3D().load(-1,-1,P_height) )
    area.x( IceRayCpp.MathTypeCoord3D().load( 2, 0, 0 ) )
    area.y( IceRayCpp.MathTypeCoord3D().load( 0, 2, 0 ) )
    area.sample( P_sample )

    sun.child( area )

    return { 'this': sun, 'child': area }

def circle( P_height = 1 + 1 + (math.sqrt(5)-1)/2, P_sample = 100 ):

    sun = IceRayCpp.LightSun()

    circle =  IceRayCpp.LightCircle()
    circle.center( IceRayCpp.MathTypeCoord3D().load( 0, 0, P_height ) )
    circle.sample( P_sample )

    sun.child( circle )

    return { 'this': sun, 'child': circle }

def disc( P_height = 1 + 1 + (math.sqrt(5)-1)/2, P_sample = 100 ):

    sun = IceRayCpp.LightSun()

    disc = IceRayCpp.LightDisc()
    disc.origin( IceRayCpp.MathTypeCoord3D().load( 0, 0, P_height ) )
    disc.x( IceRayCpp.MathTypeCoord3D().load( 1, 0, 0 ) )
    disc.y( IceRayCpp.MathTypeCoord3D().load( 0, 1, 0 ) )
    disc.sample( P_sample )

    sun.child( disc )

    return { 'this': sun, 'child': disc }

def line( P_height = 1 + 1 + (math.sqrt(5)-1)/2, P_sample = 100 ):
    sun = IceRayCpp.LightSun()

    line = IceRayCpp.LightLine()
    line.start( IceRayCpp.MathTypeCoord3D().load( -2, -2, P_height ) )
    line.end(  IceRayCpp.MathTypeCoord3D().load(   2,  2, P_height ) )
    line.sample( P_sample )

    sun.child( line )

    return { 'this': sun, 'child': line }

def point( P_height = 1 + 1 + (math.sqrt(5)-1)/2 ):

    sun = IceRayCpp.LightSun()

    point = IceRayCpp.LightPoint()
    point.spot( IceRayCpp.LightTypeSpot() )
    point.center( IceRayCpp.MathTypeCoord3D().load(0,0,P_height) )

    sun.child( point )

    return { 'this': sun, 'child': point }

