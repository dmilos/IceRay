import math
import IceRayCpp

def name( ):
    return "sphere"

def _pile_sphere( P_count = [10,10,10]):
    cargo={}

    radius = 0.9*( 2.0/P_count[0]/2 );

    for x in range( 0, P_count[0] ):
        cx = x / ( 1.0 * P_count[0] ) * 2 - 1 + 1.0/P_count[0]
        for y in range( 0,P_count[1]):
            cy = y / ( 1.0 * P_count[1] ) * 2 - 1 + 1.0/P_count[1]
            for z in range( 0, P_count[2] ):
                cz = z / ( 1.0 * P_count[2] ) * 2 - 1 + 1.0/P_count[2]
                name = '{:10}-{:10}-{:10}'.format(x,y,z)
                cargo[ name ] = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load( cx, cy, cz ), radius );

    #print( len( cargo ) )

    return cargo;

def _pile_box():
    cargo=[]
    return cargo;

def list( P_size = [3,3,3] ):

    cargo={}
    cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    cargo['list'] = IceRayCpp.GeometryRTSSList()
    cargo['this'].rtss( cargo['list'] )

    pile = _pile_sphere( P_size );

    cargo['pile'] = pile

    for name, geometry in pile.items() :
        cargo['this'].push( geometry )

    return cargo

def uniform(
     P_size = IceRayCpp.MathTypeSize3D().load( 15, 15, 15 )
    ,P_grid = IceRayCpp.MathTypeSize3D().load( 15, 15, 15 )
    ):

    cargo={}
    cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    cargo['uniform'] = IceRayCpp.GeometryRTSSUniform()
    cargo['this'].rtss( cargo['uniform'] )

    pile = _pile_sphere(P_size);

    cargo['pile'] = pile

    for name, geometry in pile.items() :
        cargo['this'].push( geometry )

    cargo['uniform'].dimension( P_grid )

    return cargo

