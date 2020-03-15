import math
import IceRayCpp

def name( ):
    return "blobby"


def solo( P_core = 0.6 ):
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbySphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), P_core, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].rtss( cargo['rtss'] )
    return cargo

def line( P_distance = 1.2, P_core = 0.6 ):
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbySphere( IceRayCpp.MathTypeCoord3D().load(-P_distance/2,0,0), P_core, 1 )
    cargo['2'] = IceRayCpp.GeometryBlobbySphere( IceRayCpp.MathTypeCoord3D().load(+P_distance/2,0,0), P_core, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].add( cargo['2'] )

    cargo['this'].rtss( cargo['rtss'] )
    return cargo

def triangle( P_radius = 0.8, P_core = 0.6 ):
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians( 0 * 120 ) ), math.sin( math.radians( 0 * 120 ) ) , 0 ), P_core, 1 )
    cargo['2'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians( 1 * 120 ) ), math.sin( math.radians( 1 * 120 ) ) , 0 ), P_core, 1 )
    cargo['3'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians( 2 * 120 ) ), math.sin( math.radians( 2 * 120 ) ) , 0 ), P_core, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].add( cargo['2'] )
    cargo['this'].add( cargo['3'] )

    cargo['this'].rtss( cargo['rtss'] )
    return cargo

def tetra(  P_radius = 0.89, P_core = 0.6 ):
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load(                 0,                    0,  1         ), P_core, 1 )
    cargo['2'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load(  2*math.sqrt(2)/3,                    0, -0.3333333 ), P_core, 1 )
    cargo['3'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( -  math.sqrt(2)/3,  math.sqrt(0.666666), -0.3333333 ), P_core, 1 )
    cargo['4'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( -  math.sqrt(2)/3, -math.sqrt(0.666666), -0.3333333 ), P_core, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].add( cargo['2'] )
    cargo['this'].add( cargo['3'] )
    cargo['this'].add( cargo['4'] )

    cargo['this'].rtss( cargo['rtss'] )
    return cargo

def hexa(  P_radius = 1, P_core = 0.6 ):
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( -1,  0,  0 ), P_core, 1 )
    cargo['2'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( +1,  0,  0 ), P_core, 1 )
    cargo['3'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load(  0, -1,  0 ), P_core, 1 )
    cargo['4'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load(  0, +1,  0 ), P_core, 1 )
    cargo['5'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load(  0,  0, -1 ), P_core, 1 )
    cargo['6'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load(  0,  0, +1 ), P_core, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].add( cargo['2'] )
    cargo['this'].add( cargo['3'] )
    cargo['this'].add( cargo['4'] )
    cargo['this'].add( cargo['5'] )
    cargo['this'].add( cargo['6'] )

    cargo['this'].rtss( cargo['rtss'] )
    return cargo

def octa(  P_radius = 0.7, P_core = 0.6 ):
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( -1, -1, -1 ), P_core, 1 )
    cargo['2'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( +1, -1, -1 ), P_core, 1 )
    cargo['3'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( -1, +1, -1 ), P_core, 1 )
    cargo['4'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( +1, +1, -1 ), P_core, 1 )
    cargo['5'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( -1, -1, +1 ), P_core, 1 )
    cargo['6'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( +1, -1, +1 ), P_core, 1 )
    cargo['7'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( -1, +1, +1 ), P_core, 1 )
    cargo['8'] = IceRayCpp.GeometryBlobbySphere( P_radius * IceRayCpp.MathTypeCoord3D().load( +1, +1, +1 ), P_core, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].add( cargo['2'] )
    cargo['this'].add( cargo['3'] )
    cargo['this'].add( cargo['4'] )
    cargo['this'].add( cargo['5'] )
    cargo['this'].add( cargo['6'] )
    cargo['this'].add( cargo['7'] )
    cargo['this'].add( cargo['8'] )

    cargo['this'].rtss( cargo['rtss'] )
    return cargo

