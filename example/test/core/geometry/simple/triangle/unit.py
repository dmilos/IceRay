import math
import copy
import IceRayCpp

def name( ):
    return "triangle"

def make( ):

    I_origin = IceRayCpp.MathTypeCoord3D()
    I_eX     = IceRayCpp.MathTypeCoord3D()
    I_eY     = IceRayCpp.MathTypeCoord3D()

    I_origin.load( 0, 0, 0 )
    I_eX    .load( 1, 0, 0 )
    I_eY    .load( 1, 1, 0 )

    triangle = IceRayCpp.GeometrySimpleTriangle( I_origin, I_eX, I_eY )

    return { 'this': triangle }

def hexa( P_radius = 1, P_position =  IceRayCpp.MathTypeCoord3D().fill(0) ):
    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['list'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    vNNN = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( -1, -1, -1 );
    vNNP = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( -1, -1, +1 );
    vNPN = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( -1, +1, -1 );
    vNPN = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( -1, +1, +1 );
    vPNN = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( +1, -1, -1 );
    vPNN = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( +1, -1, +1 );
    vPPN = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( +1, +1, -1 );
    vPPN = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( +1, +1, +1 );

    if( True ):
        geometry_cargo['SideXNa'] = IceRayCpp.GeometrySimpleTriangle( vNNN, vNNN, vNNN )
        geometry_cargo['SideXNb'] = IceRayCpp.GeometrySimpleTriangle( vNNN, vNNN, vNNN )
        geometry_cargo['this'].push( geometry_cargo['SideXNa'] )
        geometry_cargo['this'].push( geometry_cargo['SideXNb'] )

    if( True ):
        geometry_cargo['SideXPa'] = IceRayCpp.GeometrySimpleTriangle( vNNN, vNNN, vNNN )
        geometry_cargo['SideXPb'] = IceRayCpp.GeometrySimpleTriangle( vNNN, vNNN, vNNN )
        geometry_cargo['this'].push( geometry_cargo['SideXPa'] )
        geometry_cargo['this'].push( geometry_cargo['SideXPb'] )

    if( True ):
        geometry_cargo['SideYNa'] = IceRayCpp.GeometrySimpleTriangle( vNNN, vNNN, vNNN )
        geometry_cargo['SideYNb'] = IceRayCpp.GeometrySimpleTriangle( vNNN, vNNN, vNNN )
        geometry_cargo['this'].push( geometry_cargo['SideYNa'] )
        geometry_cargo['this'].push( geometry_cargo['SideYNb'] )

    if( True ):
        geometry_cargo['SideYPa'] = IceRayCpp.GeometrySimpleTriangle( vNNN, vNNN, vNNN )
        geometry_cargo['SideYPb'] = IceRayCpp.GeometrySimpleTriangle( vNNN, vNNN, vNNN )
        geometry_cargo['this'].push( geometry_cargo['SideYPa'] )
        geometry_cargo['this'].push( geometry_cargo['SideYPb'] )

    if( True ):
        geometry_cargo['SideZNa'] = IceRayCpp.GeometrySimpleTriangle( vNNN, vNNN, vNNN )
        geometry_cargo['SideZNb'] = IceRayCpp.GeometrySimpleTriangle( vNNN, vNNN, vNNN )
        geometry_cargo['this'].push( geometry_cargo['SideZNa'] )
        geometry_cargo['this'].push( geometry_cargo['SideZNb'] )

    if( True ):
        geometry_cargo['SideZPa'] = IceRayCpp.GeometrySimpleTriangle( vNNN, vNNN, vNNN )
        geometry_cargo['SideZPb'] = IceRayCpp.GeometrySimpleTriangle( vNNN, vNNN, vNNN )
        geometry_cargo['this'].push( geometry_cargo['SideZPa'] )
        geometry_cargo['this'].push( geometry_cargo['SideZPb'] )

    return geometry_cargo


def tetra( P_radius = 1, P_position =  IceRayCpp.MathTypeCoord3D().fill(0) ):
    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['list'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    v0 = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load(0,0,1);
    v1 = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load(  2*math.sqrt(2)/3.0,                   0, -1.0/3.0 );
    v2 = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( -  math.sqrt(2)/3.0,  math.sqrt(2.0/3.0), -1.0/3.0 );
    v3 = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( -  math.sqrt(2)/3.0, -math.sqrt(2.0/3.0), -1.0/3.0 );

    if( True ):
        geometry_cargo['Side0'] = IceRayCpp.GeometrySimpleTriangle( v0, v1, v2 )
        geometry_cargo['this'].push( geometry_cargo['Side0'] )

    if( True ):
        geometry_cargo['Side1'] = IceRayCpp.GeometrySimpleTriangle( v0, v1, v3 )
        geometry_cargo['this'].push( geometry_cargo['Side1'] )

    if( True ):
        geometry_cargo['Side2'] = IceRayCpp.GeometrySimpleTriangle( v0, v2, v3 )
        geometry_cargo['this'].push( geometry_cargo['Side2'] )

    if( True ):
        geometry_cargo['Side3'] = IceRayCpp.GeometrySimpleTriangle( v1, v2, v3 )
        geometry_cargo['this'].push( geometry_cargo['Side3'] )

    return geometry_cargo

def octa( P_radius = 1, P_position =  IceRayCpp.MathTypeCoord3D().fill(0) ):

    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['list'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    vXp = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( +1,  0,  0 );
    vXm = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( -1,  0,  0 );
    vYm = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load(  0, +1,  0 );
    vYp = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load(  0, -1,  0 );
    vZp = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load(  0,  0, +1 );
    vZm = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load(  0,  0, -1 );

    if( True ): # vZp, vXp, vYp
        geometry_cargo['Side0'] = IceRayCpp.GeometrySimpleTriangle( vZp, vXp, vYp )
        geometry_cargo['this'].push( geometry_cargo['Side0'] )

    if( True ): # vZp, vXm, vYm
        geometry_cargo['Side1'] = IceRayCpp.GeometrySimpleTriangle( vZp, vXm, vYm )
        geometry_cargo['this'].push( geometry_cargo['Side1'] )

    if( True ): # vZp, vXp, vYm
        geometry_cargo['Side2'] = IceRayCpp.GeometrySimpleTriangle( vZp, vXp, vYm )
        geometry_cargo['this'].push( geometry_cargo['Side2'] )

    if( True ): # vZp, vYp, vXm
        geometry_cargo['Side3'] = IceRayCpp.GeometrySimpleTriangle( vZp, vYp, vXm )
        geometry_cargo['this'].push( geometry_cargo['Side3'] )

    if( True ): # vZm, vXp, vYp
        geometry_cargo['Side4'] = IceRayCpp.GeometrySimpleTriangle( vZm, vXp, vYp )
        geometry_cargo['this'].push( geometry_cargo['Side4'] )

    if( True ): # vZm, vXm, vYm
        objectSide5_cargo = {}
        objectSide5_cargo['this'] = IceRayCpp.CoreObject()
        geometry_cargo['Side5'] = IceRayCpp.GeometrySimpleTriangle( vZm, vXm, vYm )
        geometry_cargo['this'].push( geometry_cargo['Side5'] )

    if( True ): # vZm, vYp, vXm
        geometry_cargo['Side6'] = IceRayCpp.GeometrySimpleTriangle( vZm, vXp, vYm )
        geometry_cargo['this'].push( geometry_cargo['Side6'] )

    if( True ): # vZm, vYp, vXm
        geometry_cargo['Side7'] = IceRayCpp.GeometrySimpleTriangle( vZm, vYp, vXm )
        geometry_cargo['this'].push( geometry_cargo['Side7'] )

    return geometry_cargo

def icosa( P_radius = 1, P_position =  IceRayCpp.MathTypeCoord3D().fill(0) ):
    height = math.sqrt( 0.2 )
    width = math.sqrt( 1- height*height)
    move = 36

    top    = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load(0, 0, +1)
    bottom = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load(0, 0, -1)

    up = [0,0,0,0,0]
    up[0]   = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(0 * 72) ), width * math.sin( math.radians(0 * 72)), height )
    up[1]   = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(1 * 72) ), width * math.sin( math.radians(1 * 72)), height )
    up[2]   = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(2 * 72) ), width * math.sin( math.radians(2 * 72)), height )
    up[3]   = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(3 * 72) ), width * math.sin( math.radians(3 * 72)), height )
    up[4]   = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(4 * 72) ), width * math.sin( math.radians(4 * 72)), height )

    down=[0,0,0,0,0]
    down[0] = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(move + 0 * 72) ), width * math.sin(math.radians(move + 0 * 72)), -height )
    down[1] = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(move + 1 * 72) ), width * math.sin(math.radians(move + 1 * 72)), -height )
    down[2] = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(move + 2 * 72) ), width * math.sin(math.radians(move + 2 * 72)), -height )
    down[3] = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(move + 3 * 72) ), width * math.sin(math.radians(move + 3 * 72)), -height )
    down[4] = P_position + P_radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(move + 4 * 72) ), width * math.sin(math.radians(move + 4 * 72)), -height )

    #a = P_radius / math.sin(  math.radians(72) )
    #print( 'Edge= ', a );
    #print("Norms")
    #print( IceRayCpp.MathLinearVector3DLength( top ) )
    #print( IceRayCpp.MathLinearVector3DLength( bottom ) )
    #
    #for index in range(0,5)  :
    #    print( IceRayCpp.MathLinearVector3DLength( up[index] ) )
    #    print( IceRayCpp.MathLinearVector3DLength( down[index] ) )
    #    print( IceRayCpp.MathLinearVector3DLength( top - up[index] ) )
    #    print( IceRayCpp.MathLinearVector3DLength( bottom - down[index] ) )
    #
    #for i in range(0,5)  :
    #    for j in range(0,5)  :
    #        print( str( IceRayCpp.MathLinearVector3DLength( up[i] - down[j] ) ) + "    ", end='' )
    #    print()

    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['rtss'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['rtss'] )

    geometry_cargo['trgs']={}

    for index in range(0,5):
        name = 'Side' + str(index)
        geometry_cargo['trgs'][ name ] = IceRayCpp.GeometrySimpleTriangle( top, up[index], up[(index+1)%5] )
        geometry_cargo['this'].push( geometry_cargo['trgs'][ name ] )

        name = 'Side' + str(index+5)
        geometry_cargo['trgs'][ name ] = IceRayCpp.GeometrySimpleTriangle( down[index], up[index], up[(index+1)%5] )
        geometry_cargo['this'].push( geometry_cargo['trgs'][ name ] )

        name = 'Side' + str(index+10)
        geometry_cargo['trgs'][ name ] = IceRayCpp.GeometrySimpleTriangle( up[(index+1)%5], down[index], down[(index+1)%5] )
        geometry_cargo['this'].push( geometry_cargo['trgs'][ name ] )

        name = 'Side' + str(index+15)
        geometry_cargo['trgs'][ name ] = IceRayCpp.GeometrySimpleTriangle( bottom, down[index], down[(index+1)%5] )
        geometry_cargo['this'].push( geometry_cargo['trgs'][ name ] )

    return geometry_cargo

def dodeka( P_radius = 1, P_position =  IceRayCpp.MathTypeCoord3D().fill(0) ):
    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['rtss'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['rtss'] )

    geometry_cargo['trgs']={}

    height = 0.8

    ceil = [0,0,0,0,0]
    ceil[0]   = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(0 * 72) ), math.sin( math.radians(0 * 72)), height )
    ceil[1]   = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(1 * 72) ), math.sin( math.radians(1 * 72)), height )
    ceil[2]   = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(2 * 72) ), math.sin( math.radians(2 * 72)), height )
    ceil[3]   = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(3 * 72) ), math.sin( math.radians(3 * 72)), height )
    ceil[4]   = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(4 * 72) ), math.sin( math.radians(4 * 72)), height )

    floor=[0,0,0,0,0]
    floor[0] = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(36 + 0 * 72) ), math.sin(math.radians(36 + 0 * 72)), -height )
    floor[1] = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(36 + 1 * 72) ), math.sin(math.radians(36 + 1 * 72)), -height )
    floor[2] = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(36 + 2 * 72) ), math.sin(math.radians(36 + 2 * 72)), -height )
    floor[3] = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(36 + 3 * 72) ), math.sin(math.radians(36 + 3 * 72)), -height )
    floor[4] = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(36 + 4 * 72) ), math.sin(math.radians(36 + 4 * 72)), -height )

    plus = [0,0,0,0,0]
    plus[0]   = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(0 * 72) ), math.sin( math.radians(0 * 72)), height )
    plus[1]   = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(1 * 72) ), math.sin( math.radians(1 * 72)), height )
    plus[2]   = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(2 * 72) ), math.sin( math.radians(2 * 72)), height )
    plus[3]   = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(3 * 72) ), math.sin( math.radians(3 * 72)), height )
    plus[4]   = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(4 * 72) ), math.sin( math.radians(4 * 72)), height )

    minus=[0,0,0,0,0]
    minus[0] = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(36 + 0 * 72) ), math.sin(math.radians(36 + 0 * 72)), -height )
    minus[1] = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(36 + 1 * 72) ), math.sin(math.radians(36 + 1 * 72)), -height )
    minus[2] = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(36 + 2 * 72) ), math.sin(math.radians(36 + 2 * 72)), -height )
    minus[3] = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(36 + 3 * 72) ), math.sin(math.radians(36 + 3 * 72)), -height )
    minus[4] = 1 * IceRayCpp.MathTypeCoord3D().load( math.cos( math.radians(36 + 4 * 72) ), math.sin(math.radians(36 + 4 * 72)), -height )

    for point in plus :
        point[0] *= 1.5;
        point[1] *= 1.5;
        point[2] = height / 2;
        print( point[0], point[1], point[2]  )

    for point in minus :
        point[0] *= 1.5;
        point[1] *= 1.5;
        point[2] = -height / 2;

    # normalization
    for point in ceil :
        len = IceRayCpp.MathLinearVector3DLength( point );
        print( point[0], point[1], point[2]  )
        point[0] /= len; point[1] /= len; point[2] /= len;
        print( point[0], point[1], point[2]  )
        print('---')

    for point in floor :
        len = IceRayCpp.MathLinearVector3DLength( point );
        point[0] /= len; point[1] /= len; point[2] /= len;

    for point in plus :
        len = IceRayCpp.MathLinearVector3DLength( point );
        point[0] /= len; point[1] /= len; point[2] /= len;
        print( point[0], point[1], point[2]  )

    for minus in minus :
        len = IceRayCpp.MathLinearVector3DLength( point );
        point[0] /= len; point[1] /= len; point[2] /= len;


    print( IceRayCpp.MathLinearVector3DLength( ceil[0] - ceil[1] ) )
    print( IceRayCpp.MathLinearVector3DLength( ceil[0] - plus[1] ) )




    # TODO if( True ):
    # TODO     geometry_cargo['Side0'] = IceRayCpp.GeometrySimpleTriangle( vZp, vXp, vYp )
    # TODO     geometry_cargo['this'].push( geometry_cargo['Side0'] )


    return geometry_cargo


dodeka()