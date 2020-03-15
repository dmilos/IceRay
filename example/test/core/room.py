import IceRayCpp
import math

#from test.core import *
import material.medium.linear
import decoration

def vacuum( P_geometry, P_light, P_surfaceExponat, P_surfaceRoom, P_medium = material.medium.linear.make() ):

    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['list'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    if( True ):
        objectVacuum_cargo = {}
        objectVacuum_cargo['this'] = IceRayCpp.GeometryVolumetricVacuum( )
        geometry_cargo['this'].push( objectVacuum_cargo['this'] )
        geometry_cargo['vacuum'] = objectVacuum_cargo

    objectExponat_cargo = {}
    objectExponat_cargo['geometry'] = P_geometry['this']
    objectExponat_cargo['this'] = IceRayCpp.CoreObject()

    objectExponat_cargo['this'].geometry( objectExponat_cargo['geometry'] );
    objectExponat_cargo['this'].surface( P_surfaceExponat['this'] );
    objectExponat_cargo['surface'] = P_surfaceExponat

    #objectExponat_cargo['this'].medium( P_medium['this'] );
    #objectExponat_cargo['medium'] = P_medium

    geometry_cargo['this'].push( objectExponat_cargo['this'] )
    geometry_cargo['exponat'] = objectExponat_cargo

    object = IceRayCpp.CoreObject()
    object.geometry( geometry_cargo['this'] )

    #geometry_cargo['medium'] = material.medium.linear.make( )
    #object.medium( geometry_cargo['medium']['this'] );

    P_light['this'].barrier( geometry_cargo['this'] )

    return { 'this': object, 'geometry': geometry_cargo }

def plane( P_geometry, P_light, P_surfaceExponat, P_surfaceRoom, P_medium = material.medium.linear.make() ):

    level = -1

    point = IceRayCpp.MathTypeCoord3D().load( 0, 0,  level )
    normal = IceRayCpp.MathTypeCoord3D().load(0,0,1)

    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['list'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    if( True ):
        objectPlane_cargo = {}
        objectPlane_cargo['this'] = IceRayCpp.CoreObject()
        objectPlane_cargo['geometry'] = IceRayCpp.GeometrySimplePlane( point, normal )

        objectPlane_cargo['this'].geometry( objectPlane_cargo['geometry'] );
        objectPlane_cargo['this'].surface( P_surfaceRoom['floor']['this'] );
        objectPlane_cargo['surface'] = P_surfaceRoom['floor']
        geometry_cargo['this'].push( objectPlane_cargo['this'] )
        geometry_cargo['plate'] = objectPlane_cargo

    objectExponat_cargo = {}
    objectExponat_cargo['geometry'] = P_geometry['this']
    objectExponat_cargo['this'] = IceRayCpp.CoreObject()

    objectExponat_cargo['this'].geometry( objectExponat_cargo['geometry'] );
    objectExponat_cargo['this'].surface( P_surfaceExponat['this'] );
    objectExponat_cargo['surface'] = P_surfaceExponat

    #objectExponat_cargo['this'].medium( P_medium['this'] );
    #objectExponat_cargo['medium'] = P_medium

    geometry_cargo['this'].push( objectExponat_cargo['this'] )


    geometry_cargo['exponat'] = objectExponat_cargo

    object = IceRayCpp.CoreObject()
    object.geometry( geometry_cargo['this'] )

    #geometry_cargo['medium'] = material.medium.linear.make( )
    #object.medium( geometry_cargo['medium']['this'] );

    P_light['this'].barrier( geometry_cargo['this'] )
    return { 'this': object, 'geometry': geometry_cargo }

def plate( P_geometry, P_light, P_surfaceExponat, P_surfaceRoom, P_medium = material.medium.linear.make() ):

    level = - 1;
    width = 5
    depth =5
    lo = IceRayCpp.MathTypeCoord3D().load( -width, -depth,  level - 0.01 )
    hi = IceRayCpp.MathTypeCoord3D().load( +width, +depth,level)

    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['list'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    if( True ):
        objectPlate_cargo = {}
        objectPlate_cargo['this'] = IceRayCpp.CoreObject()
        objectPlate_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( lo, hi )

        objectPlate_cargo['this'].geometry( objectPlate_cargo['geometry'] );
        objectPlate_cargo['this'].surface( P_surfaceRoom['floor']['this'] );
        objectPlate_cargo['surface'] = P_surfaceRoom['floor']
        geometry_cargo['this'].push( objectPlate_cargo['this'] )
        geometry_cargo['plate'] = objectPlate_cargo

    objectExponat_cargo = {}
    objectExponat_cargo['geometry'] = P_geometry['this']
    objectExponat_cargo['this'] = IceRayCpp.CoreObject()

    objectExponat_cargo['this'].geometry( objectExponat_cargo['geometry'] );
    objectExponat_cargo['this'].surface( P_surfaceExponat['this'] );
    objectExponat_cargo['surface'] = P_surfaceExponat

    #objectExponat_cargo['this'].medium( P_medium['this'] );
    #objectExponat_cargo['medium'] = P_medium

    geometry_cargo['this'].push( objectExponat_cargo['this'] )


    geometry_cargo['exponat'] = objectExponat_cargo

    object = IceRayCpp.CoreObject()
    object.geometry( geometry_cargo['this'] )

    #geometry_cargo['medium'] = material.medium.linear.make( )
    #object.medium( geometry_cargo['medium']['this'] );

    P_light['this'].barrier( geometry_cargo['this'] )
    return { 'this': object, 'geometry': geometry_cargo }

def cube( P_geometry, P_light, P_surfaceExponat, P_surfaceRoom, P_medium = material.medium.linear.make() ):

    I_size = 6 / 2
    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['list'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    if( True ):
        objectBox_cargo = {}
        objectBox_cargo['this'] = IceRayCpp.CoreObject()
        objectBox_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().fill( -I_size ), IceRayCpp.MathTypeCoord3D().fill( I_size ) )
        objectBox_cargo['this'].geometry( objectBox_cargo['geometry'] );
        objectBox_cargo['this'].surface( P_surfaceRoom['box']['this'] );
        objectBox_cargo['surface'] = P_surfaceRoom['box']
        geometry_cargo['this'].push( objectBox_cargo['this'] )
        geometry_cargo['box'] = objectBox_cargo

    objectExponat_cargo = {}
    objectExponat_cargo['geometry'] = P_geometry['this']
    objectExponat_cargo['this'] = IceRayCpp.CoreObject()

    objectExponat_cargo['this'].geometry( objectExponat_cargo['geometry'] );
    objectExponat_cargo['this'].surface( P_surfaceExponat['this'] );
    objectExponat_cargo['surface'] = P_surfaceExponat

    #objectExponat_cargo['this'].medium( P_medium['this'] );
    #objectExponat_cargo['medium'] = P_medium

    geometry_cargo['this'].push( objectExponat_cargo['this'] )


    geometry_cargo['exponat'] = objectExponat_cargo

    object = IceRayCpp.CoreObject()
    object.geometry( geometry_cargo['this'] )

    #geometry_cargo['medium'] = material.medium.linear.make( )
    #object.medium( geometry_cargo['medium']['this'] );

    P_light['this'].barrier( P_geometry['this'] )
    return { 'this': object, 'geometry': geometry_cargo }

def cylinder( P_geometry, P_light, P_surfaceExponat, P_surfaceRoom, P_medium = material.medium.linear.make() ):

    radius = 5

    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['list'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    if( True ):
        objectFloor_cargo = {}
        objectFloor_cargo['this'] = IceRayCpp.CoreObject()
        objectFloor_cargo['geometry'] = IceRayCpp.GeometrySimpleDisc( IceRayCpp.MathTypeCoord3D().load( 0, 0, -radius ), IceRayCpp.MathTypeCoord3D().load( 0,0,1 ), radius )
        objectFloor_cargo['this'].geometry( objectFloor_cargo['geometry'] );
        objectFloor_cargo['this'].surface( P_surfaceRoom['floor']['this'] );
        objectFloor_cargo['surface'] = P_surfaceRoom['floor']
        geometry_cargo['this'].push( objectFloor_cargo['this'] )
        geometry_cargo['floor'] = objectFloor_cargo

    if( True  ):
        objectCeil_cargo = {}
        objectCeil_cargo['this'] = IceRayCpp.CoreObject()
        objectCeil_cargo['geometry'] = IceRayCpp.GeometrySimpleDisc( IceRayCpp.MathTypeCoord3D().load( 0, 0, radius), IceRayCpp.MathTypeCoord3D().load( 0,0,1 ), radius )
        objectCeil_cargo['this'].geometry( objectCeil_cargo['geometry'] );
        objectCeil_cargo['this'].surface( P_surfaceRoom['ceil']['this'] );
        objectCeil_cargo['surface'] = P_surfaceRoom['ceil']
        geometry_cargo['this'].push( objectCeil_cargo['this'] )
        geometry_cargo['ceil'] = objectCeil_cargo

    if( True ):
        objectBuble_cargo = {}
        objectBuble_cargo['this'] = IceRayCpp.CoreObject()
        objectBuble_cargo['geometry'] = IceRayCpp.GeometrySimpleCylinder( radius, 2*radius )
        objectBuble_cargo['this'].geometry( objectBuble_cargo['geometry'] );
        objectBuble_cargo['this'].surface( P_surfaceRoom['fence']['this'] );
        objectBuble_cargo['surface'] = P_surfaceRoom['fence']
        geometry_cargo['this'].push( objectBuble_cargo['this'] )
        geometry_cargo['fence'] = objectBuble_cargo

    if( False   ):
        objectPlusX_cargo = {}
        objectPlusX_cargo['this'] = IceRayCpp.CoreObject()
        objectPlusX_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( 1.9,-0.4,-0.4), IceRayCpp.MathTypeCoord3D().load(2,0.4,0.4) )
        objectPlusX_cargo['this'].geometry( objectPlusX_cargo['geometry'] );
        objectPlusX_cargo['this'].surface( P_surfaceRoom['left']['this'] );
        objectPlusX_cargo['surface'] = P_surfaceRoom['left']
        geometry_cargo['this'].push( objectPlusX_cargo['this'] )
        geometry_cargo['plusX'] = objectPlusX_cargo


    objectExponat_cargo = {}
    objectExponat_cargo['geometry'] = P_geometry['this']
    objectExponat_cargo['this'] = IceRayCpp.CoreObject()

    objectExponat_cargo['this'].geometry( objectExponat_cargo['geometry'] );
    objectExponat_cargo['this'].surface( P_surfaceExponat['this'] );
    objectExponat_cargo['surface'] = P_surfaceExponat

    #objectExponat_cargo['this'].medium( P_medium['this'] );
    #objectExponat_cargo['medium'] = P_medium

    geometry_cargo['this'].push( objectExponat_cargo['this'] )


    geometry_cargo['exponat'] = objectExponat_cargo

    object = IceRayCpp.CoreObject()
    object.geometry( geometry_cargo['this'] )

    #geometry_cargo['medium'] = material.medium.linear.make( )
    #object.medium( geometry_cargo['medium']['this'] );

    P_light['this'].barrier( P_geometry['this'] )
    return { 'this': object, 'geometry': geometry_cargo }

def sphere( P_geometry, P_light, P_surfaceExponat, P_surfaceRoom, P_medium = material.medium.linear.make() ):

    radius = 4

    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['list'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    if( True ):
        objectBuble_cargo = {}
        objectBuble_cargo['this'] = IceRayCpp.CoreObject()
        objectBuble_cargo['geometry'] = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().fill( 0 ), radius )
        objectBuble_cargo['this'].geometry( objectBuble_cargo['geometry'] );
        objectBuble_cargo['this'].surface( P_surfaceRoom['bubble']['this'] );
        objectBuble_cargo['surface'] = P_surfaceRoom['bubble']
        geometry_cargo['this'].push( objectBuble_cargo['this'] )
        geometry_cargo['bubble'] = objectBuble_cargo

    decoration.coordinat_system( geometry_cargo, P_surfaceRoom, 3, 0.2,   )


    objectExponat_cargo = {}
    objectExponat_cargo['geometry'] = P_geometry['this']
    objectExponat_cargo['this'] = IceRayCpp.CoreObject()

    objectExponat_cargo['this'].geometry( objectExponat_cargo['geometry'] );
    objectExponat_cargo['this'].surface( P_surfaceExponat['this'] );
    objectExponat_cargo['surface'] = P_surfaceExponat

    #objectExponat_cargo['this'].medium( P_medium['this'] );
    #objectExponat_cargo['medium'] = P_medium

    geometry_cargo['this'].push( objectExponat_cargo['this'] )


    geometry_cargo['exponat'] = objectExponat_cargo

    object = IceRayCpp.CoreObject()
    object.geometry( geometry_cargo['this'] )

    #geometry_cargo['medium'] = material.medium.linear.make( )
    #object.medium( geometry_cargo['medium']['this'] );

    P_light['this'].barrier( geometry_cargo['this'] )

    return { 'this': object, 'geometry': geometry_cargo }

def cornell_close( P_geometry, P_light, P_surfaceExponat, P_surfaceRoom, P_medium = material.medium.linear.make() ):

    move = [ 0,0, 5 ]
    I_dimension = [ 12, 12, 12 ]

    lo = IceRayCpp.MathTypeCoord3D().load(123,123,123)
    lo[0] = -I_dimension[0]/2 + move[0]
    lo[1] = -I_dimension[1]/2 + move[1]
    lo[2] = -I_dimension[2]/2 + move[2]

    hi = IceRayCpp.MathTypeCoord3D().load(123,123,123)
    hi[0] = +I_dimension[0]/2 + move[0]
    hi[1] = +I_dimension[1]/2 + move[1]
    hi[2] = +I_dimension[2]/2 + move[2]

    wall = 0.1

    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['list'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    if( True ):
        objectFloor_cargo = {}
        objectFloor_cargo['this'] = IceRayCpp.CoreObject()
        objectFloor_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( lo[0], lo[1], lo[2]-wall ),
                                                                     IceRayCpp.MathTypeCoord3D().load( hi[0], hi[0], lo[2] ) )
        objectFloor_cargo['this'].geometry( objectFloor_cargo['geometry'] );
        objectFloor_cargo['this'].surface( P_surfaceRoom['floor']['this'] );
        objectFloor_cargo['surface'] = P_surfaceRoom['floor']
        geometry_cargo['this'].push( objectFloor_cargo['this'] )
        geometry_cargo['floor'] = objectFloor_cargo

    if( True ):
        objectCeil_cargo = {}
        objectCeil_cargo['this'] = IceRayCpp.CoreObject()
        objectCeil_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( lo[0], lo[1], hi[2]        ),
                                                                    IceRayCpp.MathTypeCoord3D().load( hi[0], hi[1], hi[2] + wall ) )
        objectCeil_cargo['this'].geometry( objectCeil_cargo['geometry'] );
        objectCeil_cargo['this'].surface( P_surfaceRoom['ceil']['this'] );
        objectCeil_cargo['surface'] = P_surfaceRoom['ceil']
        geometry_cargo['this'].push( objectCeil_cargo['this'] )
        geometry_cargo['ceil'] = objectCeil_cargo

    if( True ):
        objectBg_cargo = {}
        objectBg_cargo['this'] = IceRayCpp.CoreObject()
        objectBg_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( lo[0], lo[1]-wall, lo[2]),
                                                                  IceRayCpp.MathTypeCoord3D().load( hi[0], lo[1],      hi[2]) )
        objectBg_cargo['this'].geometry( objectBg_cargo['geometry'] );
        objectBg_cargo['this'].surface( P_surfaceRoom['background']['this'] );
        objectBg_cargo['surface'] = P_surfaceRoom['background']
        geometry_cargo['this'].push( objectBg_cargo['this'] )
        geometry_cargo['background'] = objectBg_cargo

    if( True ):
        objectFg_cargo = {}
        objectFg_cargo['this'] = IceRayCpp.CoreObject()
        objectFg_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( lo[0], hi[1],        lo[2] ),
                                                                  IceRayCpp.MathTypeCoord3D().load( hi[0], hi[1] + wall, hi[2] ) )
        objectFg_cargo['this'].geometry( objectFg_cargo['geometry'] );
        objectFg_cargo['this'].surface( P_surfaceRoom['foreground']['this'] );
        objectFg_cargo['surface'] = P_surfaceRoom['foreground']
        geometry_cargo['this'].push( objectFg_cargo['this'] )
        geometry_cargo['foreground'] = objectFg_cargo

    if( True ):
        objectLeft_cargo = {}
        objectLeft_cargo['this'] = IceRayCpp.CoreObject()
        objectLeft_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load(lo[0]-wall, lo[1], lo[2]),
                                                                    IceRayCpp.MathTypeCoord3D().load(lo[0],      hi[1], hi[2]) )
        objectLeft_cargo['this'].geometry( objectLeft_cargo['geometry'] );
        objectLeft_cargo['this'].surface( P_surfaceRoom['left']['this'] );
        objectLeft_cargo['surface'] = P_surfaceRoom['left']
        geometry_cargo['this'].push( objectLeft_cargo['this'] )
        geometry_cargo['left'] = objectLeft_cargo

    if( True ):
        objectRight_cargo = {}
        objectRight_cargo['this'] = IceRayCpp.CoreObject()
        objectRight_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( hi[0],      lo[1], lo[2] ),
                                                                     IceRayCpp.MathTypeCoord3D().load( hi[0]+ wall,hi[1], hi[2] ) )
        objectRight_cargo['this'].geometry( objectRight_cargo['geometry'] );
        objectRight_cargo['this'].surface( P_surfaceRoom['right']['this'] );
        objectRight_cargo['surface'] = P_surfaceRoom['right']
        geometry_cargo['this'].push( objectRight_cargo['this'] )
        geometry_cargo['right'] = objectRight_cargo

    #decoration.coordinat_system( geometry_cargo, P_surfaceRoom, 2, 0.1  )

    if( 'light' in P_surfaceRoom ):
        objectLight_cargo = {}
        objectLight_cargo['this'] = IceRayCpp.CoreObject()
        objectLight_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( -0.25-2,-0.25-2,2.9-1), IceRayCpp.MathTypeCoord3D().load(0.25-2,0.25-2,3-1) )
        objectLight_cargo['this'].geometry( objectLight_cargo['geometry'] );
        objectLight_cargo['this'].surface( P_surfaceRoom['light']['this'] );
        objectLight_cargo['surface'] = P_surfaceRoom['left']
        geometry_cargo['this'].push( objectLight_cargo['this'] )
        geometry_cargo['light'] = objectLight_cargo

    objectExponat_cargo = {}
    objectExponat_cargo['geometry'] = P_geometry['this']
    objectExponat_cargo['this'] = IceRayCpp.CoreObject()

    objectExponat_cargo['this'].geometry( objectExponat_cargo['geometry'] );
    objectExponat_cargo['this'].surface( P_surfaceExponat['this'] );
    objectExponat_cargo['surface'] = P_surfaceExponat

    #objectExponat_cargo['this'].medium( P_medium['this'] );
    #objectExponat_cargo['medium'] = P_medium

    geometry_cargo['this'].push( objectExponat_cargo['this'] )
    P_light['this'].barrier( geometry_cargo['this'] )


    geometry_cargo['exponat'] = objectExponat_cargo

    object = IceRayCpp.CoreObject()
    object.geometry( geometry_cargo['this'] )

    #geometry_cargo['medium'] = material.medium.linear.make( )
    #object.medium( geometry_cargo['medium']['this'] );

    return { 'this': object, 'geometry': geometry_cargo }

def cornell_open( P_geometry, P_light, P_surfaceExponat, P_surfaceRoom, P_medium = material.medium.linear.make() ):

    move       = [ 0, 0, (1+1+1 + (math.sqrt(5)-1)/2 )/2-1 ]
    I_dimension= [ 5, 5, (1+1+1 + (math.sqrt(5)-1)/2 ) ]

    move       = [ 0, 0, 2.2 ]
    I_dimension= [ 6.5, 6.5, 6.5 ]

    lo = IceRayCpp.MathTypeCoord3D().load(123,123,123)
    lo[0] = -I_dimension[0]/2 + move[0]
    lo[1] = -I_dimension[1]/2 + move[1]
    lo[2] = -I_dimension[2]/2 + move[2]

    hi = IceRayCpp.MathTypeCoord3D().load(123,123,123)
    hi[0] = +I_dimension[0]/2 + move[0]
    hi[1] = +I_dimension[1]/2 + move[1]
    hi[2] = +I_dimension[2]/2 + move[2]

    wall = 0.1

    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['list'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    if( True ):
        objectFloor_cargo = {}
        objectFloor_cargo['this'] = IceRayCpp.CoreObject()
        objectFloor_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( lo[0], lo[1], lo[2]-wall ),
                                                                     IceRayCpp.MathTypeCoord3D().load( hi[0], hi[0], lo[2] ) )
        objectFloor_cargo['this'].geometry( objectFloor_cargo['geometry'] );
        objectFloor_cargo['this'].surface( P_surfaceRoom['floor']['this'] );
        objectFloor_cargo['surface'] = P_surfaceRoom['floor']
        geometry_cargo['this'].push( objectFloor_cargo['this'] )
        geometry_cargo['floor'] = objectFloor_cargo

    if( True ):
        objectCeil_cargo = {}
        objectCeil_cargo['this'] = IceRayCpp.CoreObject()
        objectCeil_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( lo[0], lo[1], hi[2]        ),
                                                                    IceRayCpp.MathTypeCoord3D().load( hi[0], hi[1], hi[2] + wall ) )
        objectCeil_cargo['this'].geometry( objectCeil_cargo['geometry'] );
        objectCeil_cargo['this'].surface( P_surfaceRoom['ceil']['this'] );
        objectCeil_cargo['surface'] = P_surfaceRoom['ceil']
        geometry_cargo['this'].push( objectCeil_cargo['this'] )
        geometry_cargo['ceil'] = objectCeil_cargo

    if( True ):
        objectBg_cargo = {}
        objectBg_cargo['this'] = IceRayCpp.CoreObject()
        objectBg_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( lo[0], lo[1]-wall, lo[2]),
                                                                  IceRayCpp.MathTypeCoord3D().load( hi[0], lo[1],      hi[2]) )
        objectBg_cargo['this'].geometry( objectBg_cargo['geometry'] );
        objectBg_cargo['this'].surface( P_surfaceRoom['background']['this'] );
        objectBg_cargo['surface'] = P_surfaceRoom['background']
        geometry_cargo['this'].push( objectBg_cargo['this'] )
        geometry_cargo['background'] = objectBg_cargo

    if( False ):
        objectFg_cargo = {}
        objectFg_cargo['this'] = IceRayCpp.CoreObject()
        objectFg_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( lo[0], hi[1],        lo[2] ),
                                                                  IceRayCpp.MathTypeCoord3D().load( hi[0], hi[1] + wall, hi[2] ) )
        objectFg_cargo['this'].geometry( objectFg_cargo['geometry'] );
        objectFg_cargo['this'].surface( P_surfaceRoom['foreground']['this'] );
        objectFg_cargo['surface'] = P_surfaceRoom['foreground']
        geometry_cargo['this'].push( objectFg_cargo['this'] )
        geometry_cargo['foreground'] = objectFg_cargo

    if( True ):
        objectLeft_cargo = {}
        objectLeft_cargo['this'] = IceRayCpp.CoreObject()
        objectLeft_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load(lo[0]-wall, lo[1], lo[2]),
                                                                    IceRayCpp.MathTypeCoord3D().load(lo[0],      hi[1], hi[2]) )
        objectLeft_cargo['this'].geometry( objectLeft_cargo['geometry'] );
        objectLeft_cargo['this'].surface( P_surfaceRoom['left']['this'] );
        objectLeft_cargo['surface'] = P_surfaceRoom['left']
        geometry_cargo['this'].push( objectLeft_cargo['this'] )
        geometry_cargo['left'] = objectLeft_cargo

    if( True ):
        objectRight_cargo = {}
        objectRight_cargo['this'] = IceRayCpp.CoreObject()
        objectRight_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( hi[0],      lo[1], lo[2] ),
                                                                     IceRayCpp.MathTypeCoord3D().load( hi[0]+ wall,hi[1], hi[2] ) )
        objectRight_cargo['this'].geometry( objectRight_cargo['geometry'] );
        objectRight_cargo['this'].surface( P_surfaceRoom['right']['this'] );
        objectRight_cargo['surface'] = P_surfaceRoom['right']
        geometry_cargo['this'].push( objectRight_cargo['this'] )
        geometry_cargo['right'] = objectRight_cargo

    #decoration.coordinat_system( geometry_cargo, P_surfaceRoom, 2, 0.1  )

    if( 'light' in P_surfaceRoom ):
        objectLight_cargo = {}
        objectLight_cargo['this'] = IceRayCpp.CoreObject()
        objectLight_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( -0.25-2,-0.25-2,2.9-1), IceRayCpp.MathTypeCoord3D().load(0.25-2,0.25-2,3-1) )
        objectLight_cargo['this'].geometry( objectLight_cargo['geometry'] );
        objectLight_cargo['this'].surface( P_surfaceRoom['light']['this'] );
        objectLight_cargo['surface'] = P_surfaceRoom['left']
        geometry_cargo['this'].push( objectLight_cargo['this'] )
        geometry_cargo['light'] = objectLight_cargo

    objectExponat_cargo = {}
    objectExponat_cargo['geometry'] = P_geometry['this']
    objectExponat_cargo['this'] = IceRayCpp.CoreObject()

    objectExponat_cargo['this'].geometry( objectExponat_cargo['geometry'] );
    objectExponat_cargo['this'].surface( P_surfaceExponat['this'] );
    objectExponat_cargo['surface'] = P_surfaceExponat

    #objectExponat_cargo['this'].medium( P_medium['this'] );
    #objectExponat_cargo['medium'] = P_medium

    geometry_cargo['this'].push( objectExponat_cargo['this'] )
    P_light['this'].barrier( geometry_cargo['this'] )


    geometry_cargo['exponat'] = objectExponat_cargo

    object = IceRayCpp.CoreObject()
    object.geometry( geometry_cargo['this'] )

    #geometry_cargo['medium'] = material.medium.linear.make( )
    #object.medium( geometry_cargo['medium']['this'] );

    return { 'this': object, 'geometry': geometry_cargo }


def tetra( P_geometry, P_light, P_surfaceExponat, P_surfaceRoom, P_medium = material.medium.linear.make() ):

    radius = 12

    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['list'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    v0 = radius * IceRayCpp.MathTypeCoord3D().load(0,0,1);
    v1 = radius * IceRayCpp.MathTypeCoord3D().load(  2*math.sqrt(2)/3,                    0, -0.3333333 );
    v2 = radius * IceRayCpp.MathTypeCoord3D().load( -  math.sqrt(2)/3,  math.sqrt(0.666666), -0.3333333 );
    v3 = radius * IceRayCpp.MathTypeCoord3D().load( -  math.sqrt(2)/3, -math.sqrt(0.666666), -0.3333333 );

    if( True ):
        objectSide0_cargo = {}
        objectSide0_cargo['this'] = IceRayCpp.CoreObject()
        objectSide0_cargo['geometry'] = IceRayCpp.GeometrySimpleTriangle( v0, v1, v2 )
        objectSide0_cargo['this'].geometry( objectSide0_cargo['geometry'] );
        objectSide0_cargo['this'].surface( P_surfaceRoom['Side0']['this'] );
        objectSide0_cargo['surface'] = P_surfaceRoom['Side0']
        geometry_cargo['this'].push( objectSide0_cargo['this'] )
        geometry_cargo['Side0'] = objectSide0_cargo

    if( True ):
        objectSide1_cargo = {}
        objectSide1_cargo['this'] = IceRayCpp.CoreObject()
        objectSide1_cargo['geometry'] = IceRayCpp.GeometrySimpleTriangle( v0, v1, v3 )
        objectSide1_cargo['this'].geometry( objectSide1_cargo['geometry'] );
        objectSide1_cargo['this'].surface( P_surfaceRoom['Side1']['this'] );
        objectSide1_cargo['surface'] = P_surfaceRoom['Side1']
        geometry_cargo['this'].push( objectSide1_cargo['this'] )
        geometry_cargo['Side1'] = objectSide1_cargo

    if( True ):
        objectSide2_cargo = {}
        objectSide2_cargo['this'] = IceRayCpp.CoreObject()
        objectSide2_cargo['geometry'] = IceRayCpp.GeometrySimpleTriangle( v0, v2, v3 )
        objectSide2_cargo['this'].geometry( objectSide2_cargo['geometry'] );
        objectSide2_cargo['this'].surface( P_surfaceRoom['Side2']['this'] );
        objectSide2_cargo['surface'] = P_surfaceRoom['Side2']
        geometry_cargo['this'].push( objectSide2_cargo['this'] )
        geometry_cargo['Side2'] = objectSide2_cargo

    if( True ):
        objectSide3_cargo = {}
        objectSide3_cargo['this'] = IceRayCpp.CoreObject()
        objectSide3_cargo['geometry'] = IceRayCpp.GeometrySimpleTriangle( v1, v2, v3 )
        objectSide3_cargo['this'].geometry( objectSide3_cargo['geometry'] );
        objectSide3_cargo['this'].surface( P_surfaceRoom['Side3']['this'] );
        objectSide3_cargo['surface'] = P_surfaceRoom['Side3']
        geometry_cargo['this'].push( objectSide3_cargo['this'] )
        geometry_cargo['Side3'] = objectSide3_cargo

    decoration.coordinat_system( geometry_cargo, P_surfaceRoom, 3, 0.2 )

    objectExponat_cargo = {}
    objectExponat_cargo['geometry'] = P_geometry['this']
    objectExponat_cargo['this'] = IceRayCpp.CoreObject()

    objectExponat_cargo['this'].geometry( objectExponat_cargo['geometry'] );
    objectExponat_cargo['this'].surface( P_surfaceExponat['this'] );
    objectExponat_cargo['surface'] = P_surfaceExponat

    #objectExponat_cargo['this'].medium( P_medium['this'] );
    #objectExponat_cargo['medium'] = P_medium

    geometry_cargo['this'].push( objectExponat_cargo['this'] )


    geometry_cargo['exponat'] = objectExponat_cargo

    object = IceRayCpp.CoreObject()
    object.geometry( geometry_cargo['this'] )

    #geometry_cargo['medium'] = material.medium.linear.make( )
    #object.medium( geometry_cargo['medium']['this'] );

    P_light['this'].barrier( geometry_cargo['this'] )

    return { 'this': object, 'geometry': geometry_cargo }

def octa( P_geometry, P_light, P_surfaceExponat, P_surfaceRoom, P_medium = material.medium.linear.make() ):
    #P_light['this'].barrier( P_geometry['this'] )

    radius = 5

    geometry_cargo={}
    geometry_cargo['this'] = IceRayCpp.GeometryRTSSGeometry( )
    geometry_cargo['list'] = IceRayCpp.GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    vXp = radius * IceRayCpp.MathTypeCoord3D().load( +1,  0,  0 );
    vXm = radius * IceRayCpp.MathTypeCoord3D().load( -1,  0,  0 );
    vYm = radius * IceRayCpp.MathTypeCoord3D().load(  0, +1,  0 );
    vYp = radius * IceRayCpp.MathTypeCoord3D().load(  0, -1,  0 );
    vZp = radius * IceRayCpp.MathTypeCoord3D().load(  0,  0, +1 );
    vZm = radius * IceRayCpp.MathTypeCoord3D().load(  0,  0, -1 );

    if( True ): # vZp, vXp, vYp
        objectSide0_cargo = {}
        objectSide0_cargo['this'] = IceRayCpp.CoreObject()
        objectSide0_cargo['geometry'] = IceRayCpp.GeometrySimpleTriangle( vZp, vXp, vYp )
        objectSide0_cargo['this'].geometry( objectSide0_cargo['geometry'] );
        objectSide0_cargo['this'].surface( P_surfaceRoom['Side0']['this'] );
        objectSide0_cargo['surface'] = P_surfaceRoom['Side0']
        geometry_cargo['this'].push( objectSide0_cargo['this'] )
        geometry_cargo['Side0'] = objectSide0_cargo

    if( True ): # vZp, vXm, vYm
        objectSide1_cargo = {}
        objectSide1_cargo['this'] = IceRayCpp.CoreObject()
        objectSide1_cargo['geometry'] = IceRayCpp.GeometrySimpleTriangle( vZp, vXm, vYm )
        objectSide1_cargo['this'].geometry( objectSide1_cargo['geometry'] );
        objectSide1_cargo['this'].surface( P_surfaceRoom['Side1']['this'] );
        objectSide1_cargo['surface'] = P_surfaceRoom['Side1']
        geometry_cargo['this'].push( objectSide1_cargo['this'] )
        geometry_cargo['Side1'] = objectSide1_cargo

    if( True ): # vZp, vXp, vYm
        objectSide2_cargo = {}
        objectSide2_cargo['this'] = IceRayCpp.CoreObject()
        objectSide2_cargo['geometry'] = IceRayCpp.GeometrySimpleTriangle( vZp, vXp, vYm )
        objectSide2_cargo['this'].geometry( objectSide2_cargo['geometry'] );
        objectSide2_cargo['this'].surface( P_surfaceRoom['Side2']['this'] );
        objectSide2_cargo['surface'] = P_surfaceRoom['Side2']
        geometry_cargo['this'].push( objectSide2_cargo['this'] )
        geometry_cargo['Side2'] = objectSide2_cargo

    if( True ): # vZp, vYp, vXm
        objectSide3_cargo = {}
        objectSide3_cargo['this'] = IceRayCpp.CoreObject()
        objectSide3_cargo['geometry'] = IceRayCpp.GeometrySimpleTriangle( vZp, vYp, vXm )
        objectSide3_cargo['this'].geometry( objectSide3_cargo['geometry'] );
        objectSide3_cargo['this'].surface( P_surfaceRoom['Side3']['this'] );
        objectSide3_cargo['surface'] = P_surfaceRoom['Side3']
        geometry_cargo['this'].push( objectSide3_cargo['this'] )
        geometry_cargo['Side3'] = objectSide3_cargo

    if( True ): # vZm, vXp, vYp
        objectSide4_cargo = {}
        objectSide4_cargo['this'] = IceRayCpp.CoreObject()
        objectSide4_cargo['geometry'] = IceRayCpp.GeometrySimpleTriangle( vZm, vXp, vYp )
        objectSide4_cargo['this'].geometry( objectSide4_cargo['geometry'] );
        objectSide4_cargo['this'].surface( P_surfaceRoom['Side4']['this'] );
        objectSide4_cargo['surface'] = P_surfaceRoom['Side4']
        geometry_cargo['this'].push( objectSide4_cargo['this'] )
        geometry_cargo['Side4'] = objectSide4_cargo

    if( True ): # vZm, vXm, vYm
        objectSide5_cargo = {}
        objectSide5_cargo['this'] = IceRayCpp.CoreObject()
        objectSide5_cargo['geometry'] = IceRayCpp.GeometrySimpleTriangle( vZm, vXm, vYm )
        objectSide5_cargo['this'].geometry( objectSide5_cargo['geometry'] );
        objectSide5_cargo['this'].surface( P_surfaceRoom['Side5']['this'] );
        objectSide5_cargo['surface'] = P_surfaceRoom['Side5']
        geometry_cargo['this'].push( objectSide5_cargo['this'] )
        geometry_cargo['Side5'] = objectSide5_cargo

    if( True ): # vZm, vYp, vXm
        objectSide6_cargo = {}
        objectSide6_cargo['this'] = IceRayCpp.CoreObject()
        objectSide6_cargo['geometry'] = IceRayCpp.GeometrySimpleTriangle( vZm, vXp, vYm  )
        objectSide6_cargo['this'].geometry( objectSide6_cargo['geometry'] );
        objectSide6_cargo['this'].surface( P_surfaceRoom['Side6']['this'] );
        objectSide6_cargo['surface'] = P_surfaceRoom['Side6']
        geometry_cargo['this'].push( objectSide6_cargo['this'] )
        geometry_cargo['Side6'] = objectSide6_cargo

    if( True ): # vZm, vYp, vXm
        objectSide7_cargo = {}
        objectSide7_cargo['this'] = IceRayCpp.CoreObject()
        objectSide7_cargo['geometry'] = IceRayCpp.GeometrySimpleTriangle( vZm, vYp, vXm )
        objectSide7_cargo['this'].geometry( objectSide7_cargo['geometry'] );
        objectSide7_cargo['this'].surface( P_surfaceRoom['Side7']['this'] );
        objectSide7_cargo['surface'] = P_surfaceRoom['Side7']
        geometry_cargo['this'].push( objectSide7_cargo['this'] )
        geometry_cargo['Side7'] = objectSide7_cargo


    decoration.coordinat_system( geometry_cargo, P_surfaceRoom, 3, 0.2 )

    objectExponat_cargo = {}
    objectExponat_cargo['geometry'] = P_geometry['this']
    objectExponat_cargo['this'] = IceRayCpp.CoreObject()

    objectExponat_cargo['this'].geometry( objectExponat_cargo['geometry'] );
    objectExponat_cargo['this'].surface( P_surfaceExponat['this'] );
    objectExponat_cargo['surface'] = P_surfaceExponat

    #objectExponat_cargo['this'].medium( P_medium['this'] );
    #objectExponat_cargo['medium'] = P_medium

    geometry_cargo['this'].push( objectExponat_cargo['this'] )


    geometry_cargo['exponat'] = objectExponat_cargo

    object = IceRayCpp.CoreObject()
    object.geometry( geometry_cargo['this'] )

    #geometry_cargo['medium'] = material.medium.linear.make( )
    #object.medium( geometry_cargo['medium']['this'] );

    P_light['this'].barrier( geometry_cargo['this'] )

    return { 'this': object, 'geometry': geometry_cargo }

def _icosahedron_triangle( P_surface, P_p0, P_p1, P_p2 ):
    object_cargo = {}
    object_cargo['this'] = IceRayCpp.CoreObject()
    object_cargo['geometry'] = IceRayCpp.GeometrySimpleTriangle( P_p0, P_p1, P_p2 )
    object_cargo['this'].geometry( object_cargo['geometry'] );
    object_cargo['this'].surface( P_surface['this'] );
    object_cargo['surface'] = P_surface

    return object_cargo

def icosa( P_geometry, P_light, P_surfaceExponat, P_surfaceRoom, P_medium = material.medium.linear.make() ):

    radius = 5
    a = radius / math.sin(  math.radians(72) )

    height = math.sqrt( 0.2 )
    width = math.sqrt( 1- height*height)

    move = 36

    top    = radius * IceRayCpp.MathTypeCoord3D().load(0, 0, +1)
    bottom = radius * IceRayCpp.MathTypeCoord3D().load(0, 0, -1)
    up = [0,0,0,0,0]
    up[0]   = radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(0 * 72) ), width * math.sin( math.radians(0 * 72)), height )
    up[1]   = radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(1 * 72) ), width * math.sin( math.radians(1 * 72)), height )
    up[2]   = radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(2 * 72) ), width * math.sin( math.radians(2 * 72)), height )
    up[3]   = radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(3 * 72) ), width * math.sin( math.radians(3 * 72)), height )
    up[4]   = radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(4 * 72) ), width * math.sin( math.radians(4 * 72)), height )

    down=[0,0,0,0,0]
    down[0] = radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(move + 0 * 72) ), width * math.sin(math.radians(move + 0 * 72)), -height )
    down[1] = radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(move + 1 * 72) ), width * math.sin(math.radians(move + 1 * 72)), -height )
    down[2] = radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(move + 2 * 72) ), width * math.sin(math.radians(move + 2 * 72)), -height )
    down[3] = radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(move + 3 * 72) ), width * math.sin(math.radians(move + 3 * 72)), -height )
    down[4] = radius * IceRayCpp.MathTypeCoord3D().load( width * math.cos( math.radians(move + 4 * 72) ), width * math.sin(math.radians(move + 4 * 72)), -height )

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

    for index in range(0,5):
        object = _icosahedron_triangle( P_surfaceRoom['Side' + str(index)], top, up[index], up[(index+1)%5] )
        geometry_cargo['this'].push( object['this'] )
        geometry_cargo['Side'+ str(index)] = object

        object = _icosahedron_triangle( P_surfaceRoom['Side' + str(5+index)], down[index], up[index], up[(index+1)%5 ] )
        geometry_cargo['this'].push( object['this'] )
        geometry_cargo['Side'+ str( 5 +index)] = object

        object = _icosahedron_triangle( P_surfaceRoom['Side' + str(10+index)], up[(index+1)%5], down[index], down[(index+1)%5 ] )
        geometry_cargo['this'].push( object['this'] )
        geometry_cargo['Side'+ str( 10 +index)] = object

        object = _icosahedron_triangle( P_surfaceRoom['Side' + str(15+index)], bottom, down[index], down[(index+1)%5] )
        geometry_cargo['this'].push( object['this'] )
        geometry_cargo['Side'+ str( 15 +index)] = object

    decoration.coordinat_system( geometry_cargo, P_surfaceRoom, 3, 0.2 )


    objectExponat_cargo = {}
    objectExponat_cargo['geometry'] = P_geometry['this']
    objectExponat_cargo['this'] = IceRayCpp.CoreObject()

    objectExponat_cargo['this'].geometry( objectExponat_cargo['geometry'] );
    objectExponat_cargo['this'].surface( P_surfaceExponat['this'] );
    objectExponat_cargo['surface'] = P_surfaceExponat

    #objectExponat_cargo['this'].medium( P_medium['this'] );
    #objectExponat_cargo['medium'] = P_medium

    geometry_cargo['this'].push( objectExponat_cargo['this'] )


    geometry_cargo['exponat'] = objectExponat_cargo

    object = IceRayCpp.CoreObject()
    object.geometry( geometry_cargo['this'] )

    #geometry_cargo['medium'] = material.medium.linear.make( )
    #object.medium( geometry_cargo['medium']['this'] );

    P_light['this'].barrier( geometry_cargo['this'] )

    return { 'this': object, 'geometry': geometry_cargo }
