import math
import IceRayCpp

def name( ):
    return "line"

def make( P_height = 1+1 + (math.sqrt(5)-1)/2 ):

    point = IceRayCpp.LightPoint()

    spot = IceRayCpp.LightTypeSpot()
    #spot._0( IceRayCpp.GraphTypeColorRGB().fill( 0.4 ) )
    #spot._1( IceRayCpp.GraphTypeColorRGB().fill( 0.3 ) )
    #spot._2( IceRayCpp.GraphTypeColorRGB().load(1,2,3) )

    point.spot( spot )

    point.center( IceRayCpp.MathTypeCoord3D().load(0,0,P_height) )

    return { 'this': point }

def makeX( P_x = 1 + 1 + (math.sqrt(5)-1)/2 ):

    point = IceRayCpp.LightPoint()

    spot = IceRayCpp.LightTypeSpot()
    #spot._0( IceRayCpp.GraphTypeColorRGB().fill( 0.4 ) )
    #spot._1( IceRayCpp.GraphTypeColorRGB().fill( 0.3 ) )
    #spot._2( IceRayCpp.GraphTypeColorRGB().load(1,2,3) )

    point.spot( spot )

    point.center( IceRayCpp.MathTypeCoord3D().load( P_x, 0, 0 ) )

    return { 'this': point }

def makeY( P_y = 1 + 1 + (math.sqrt(5)-1)/2 ):

    point = IceRayCpp.LightPoint()

    spot = IceRayCpp.LightTypeSpot()
    #spot._0( IceRayCpp.GraphTypeColorRGB().fill( 0.4 ) )
    #spot._1( IceRayCpp.GraphTypeColorRGB().fill( 0.3 ) )
    #spot._2( IceRayCpp.GraphTypeColorRGB().load(1,2,3) )

    point.spot( spot )

    point.center( IceRayCpp.MathTypeCoord3D().load( 0, P_y, 0 ) )

    return { 'this': point }

def makeZ( P_z = 1 + (math.sqrt(5)-1)/2 ):

    point = IceRayCpp.LightPoint()

    spot = IceRayCpp.LightTypeSpot()
    #spot._0( IceRayCpp.GraphTypeColorRGB().fill( 0.4 ) )
    #spot._1( IceRayCpp.GraphTypeColorRGB().fill( 0.3 ) )
    #spot._2( IceRayCpp.GraphTypeColorRGB().load(1,2,3) )

    point.spot( spot )

    point.center( IceRayCpp.MathTypeCoord3D().load( 0, 0, P_z ) )

    return { 'this': point }
