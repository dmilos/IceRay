import math
import IceRayCpp

def name( ):
    return "line"

def tetra( P_radius = 1 + 1 + (math.sqrt(5)-1)/2 ):

    chandelier = IceRayCpp.LightChandelier()

    pointL = IceRayCpp.LightPoint(  )
    pointR = IceRayCpp.LightPoint(  )
    pointF = IceRayCpp.LightPoint(  )
    pointB = IceRayCpp.LightPoint(  )

    spot = IceRayCpp.LightTypeSpot()

    spot._0(  IceRayCpp.GraphTypeColorRGB().load( 1,0,0 ) )
    spot.center( P_radius *IceRayCpp.MathTypeCoord3D().load( math.sqrt(8/9.0), 0, -1/3.0 ) )
    pointL.spot( spot )

    spot._0(  IceRayCpp.GraphTypeColorRGB().load( 0,1,0 ) )
    spot.center( P_radius *IceRayCpp.MathTypeCoord3D().load( -math.sqrt(2/9.0), math.sqrt(2/3.0), -1/3.0 ) )
    pointR.spot( spot )

    spot._0(  IceRayCpp.GraphTypeColorRGB().load( 0,0,1 ) )
    spot.center( P_radius *IceRayCpp.MathTypeCoord3D().load( -math.sqrt(2/9.0), -math.sqrt(2/3.0), -1/3.0 ) )
    pointF.spot( spot )

    spot._0(  IceRayCpp.GraphTypeColorRGB().load( 1,1,1 ) )
    spot.center( P_radius *IceRayCpp.MathTypeCoord3D().load( 0, 0, 1 ) )
    pointB.spot( spot )

    chandelier.add( pointL )
    chandelier.add( pointR )
    chandelier.add( pointF )
    chandelier.add( pointB )

    return { 'this': chandelier, '1': pointL, '2': pointR, '3': pointF, '4': pointB }

def octa(  P_edge   = 1 + 1 + (math.sqrt(5)-1)/2):
    chandelier = IceRayCpp.LightChandelier()

    point000 = IceRayCpp.LightPoint(  )
    point001 = IceRayCpp.LightPoint(  )
    point010 = IceRayCpp.LightPoint(  )
    point011 = IceRayCpp.LightPoint(  )
    point100 = IceRayCpp.LightPoint(  )
    point101 = IceRayCpp.LightPoint(  )
    point110 = IceRayCpp.LightPoint(  )
    point111 = IceRayCpp.LightPoint(  )

    spot = IceRayCpp.LightTypeSpot()

    spot._0(  IceRayCpp.GraphTypeColorRGB().load( 0,0,0 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( -P_edge, -P_edge, -P_edge ) )
    point000.spot( spot )

    spot._0(  IceRayCpp.GraphTypeColorRGB().load( 0,0,1 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( +P_edge, -P_edge, -P_edge ) )
    point001.spot( spot )

    spot._0(  IceRayCpp.GraphTypeColorRGB().load( 0,1,0 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( -P_edge, +P_edge, -P_edge ) )
    point010.spot( spot )

    spot._0(  IceRayCpp.GraphTypeColorRGB().load( 0,1,1 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( +P_edge, +P_edge, -P_edge ) )
    point011.spot( spot )

    spot._0(  IceRayCpp.GraphTypeColorRGB().load( 1,0,0 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( -P_edge, -P_edge, +P_edge ) )
    point100.spot( spot )

    spot._0(  IceRayCpp.GraphTypeColorRGB().load( 1,0,1 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( +P_edge, -P_edge, +P_edge ) )
    point101.spot( spot )

    spot._0(  IceRayCpp.GraphTypeColorRGB().load( 1,1,0 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( -P_edge, +P_edge, +P_edge ) )
    point110.spot( spot )

    spot._0(  IceRayCpp.GraphTypeColorRGB().load( 1,1,1 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( +P_edge, +P_edge, +P_edge ) )
    point111.spot( spot )

    chandelier.add( point000 )
    chandelier.add( point001 )
    chandelier.add( point010 )
    chandelier.add( point011 )
    chandelier.add( point100 )
    chandelier.add( point101 )
    chandelier.add( point110 )
    chandelier.add( point111 )

    return { 'this': chandelier, 
      '1': point000, '2': point001, '3': point010, '4': point011,
      '5': point100, '6': point101, '7': point110, '8': point111

      }

def hexa( P_radius  = 1 + 1 + (math.sqrt(5)-1)/2 ):

    chandelier = IceRayCpp.LightChandelier()

    pointL = IceRayCpp.LightPoint()
    pointR = IceRayCpp.LightPoint()
    pointF = IceRayCpp.LightPoint()
    pointB = IceRayCpp.LightPoint()
    pointU = IceRayCpp.LightPoint()
    pointD = IceRayCpp.LightPoint()

    spot = IceRayCpp.LightTypeSpot()

    spot._0( IceRayCpp.GraphTypeColorRGB().load( 0,1,1 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( -P_radius,0,0 ) )
    pointL.spot( spot )

    spot._0( IceRayCpp.GraphTypeColorRGB().load( 1,0,0 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( +P_radius,0,0 ) )
    pointR.spot( spot )

    spot._0( IceRayCpp.GraphTypeColorRGB().load( 1,0,1 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( 0, -P_radius,0 ) )
    pointF.spot( spot )

    spot._0( IceRayCpp.GraphTypeColorRGB().load( 0,1,0 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( 0, +P_radius,0 ) )
    pointB.spot( spot )

    spot._0( IceRayCpp.GraphTypeColorRGB().load( 1,1,0 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( 0, 0, -P_radius ) )
    pointU.spot( spot )

    spot._0( IceRayCpp.GraphTypeColorRGB().load( 0,0,1 ) )
    spot.center( IceRayCpp.MathTypeCoord3D().load( 0, 0, +P_radius ) )
    pointD.spot( spot )

    chandelier.add( pointL )
    chandelier.add( pointR )
    chandelier.add( pointF )
    chandelier.add( pointB )
    chandelier.add( pointU )
    chandelier.add( pointD )

    return { 'this': chandelier, '1': pointL, '2': pointR, '3': pointF, '4': pointB, "5": pointU, '6': pointD }


