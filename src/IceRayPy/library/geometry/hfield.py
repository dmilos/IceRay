#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import math
Size2D = IceRayPy.type.math.coord.Size2D
Coord3D = IceRayPy.type.math.coord.Scalar3D

def Image( P_dll,
        P_config = None,
        #P_filename = None,
        #P_box = None
        ):

    result    = IceRayPy.core.geometry.hfield.System(P_dll)
    generator = IceRayPy.core.geometry.hfield.generator.Image(P_dll)

    picture   = IceRayPy.type.graph.Picture( P_dll )
    picture.size( 7, 7 )

    if( ( None != P_config ) and ( 'pigment' in P_config )and ( 'filename' in P_config['pigment'] ) ):
        if( 0 == picture.load( P_config['pigment']['filename'] ) ):
            IceRayPy.type.graph.Default( picture )
    else:
        IceRayPy.type.graph.Default( picture )

    generator.picture( picture )

    objectV = IceRayPy.core.geometry.hfield.object.Vacuum(P_dll)
    objectF = IceRayPy.core.geometry.hfield.object.Flat(P_dll)
    objectT = IceRayPy.core.geometry.hfield.object.Triangle(P_dll)
    objectQ = IceRayPy.core.geometry.hfield.object.Quad(P_dll)
    result.object( objectT )
    result.generator( generator )
    result.lo( Coord3D( 1.5 *  -1.0, 1.5 *  -picture.size()[1]/( 1.0*picture.size()[0]), -0.05 - 0.5 ) )
    result.hi( Coord3D( 1.5 *  +1.0, 1.5 *  +picture.size()[1]/( 1.0*picture.size()[0]), +0.05 - 0.5 ) )
    return result

def Expression( P_dll,
        P_config = None,
        P_box = None
        ):

    result    = IceRayPy.core.geometry.hfield.System(P_dll)

    generator = IceRayPy.core.geometry.hfield.generator.Expression(P_dll)
    generator.pattern('x+y')

    objectQ = IceRayPy.core.geometry.hfield.object.Quad(P_dll)
    objectF = IceRayPy.core.geometry.hfield.object.Flat(P_dll)
    objectV = IceRayPy.core.geometry.hfield.object.Vacuum(P_dll)
    result.object( objectQ )
    result.generator( generator )
    return result

def Table2x2( P_dll,
        P_config = None,
        P_box = None
        ):

    result    = IceRayPy.core.geometry.hfield.System(P_dll)

    generator = IceRayPy.core.geometry.hfield.generator.Table(P_dll)
    generator.size( Size2D( 2, 2 ) )
    generator.value( Size2D(0,0), 1 )
    generator.value( Size2D(0,1), 0 )

    generator.value( Size2D(1,0), 0 )
    generator.value( Size2D(1,1), 1 )

    objectQ = IceRayPy.core.geometry.hfield.object.Quad(P_dll)
    objectF = IceRayPy.core.geometry.hfield.object.Flat(P_dll)
    objectV = IceRayPy.core.geometry.hfield.object.Vacuum(P_dll)
    objectT = IceRayPy.core.geometry.hfield.object.Triangle(P_dll)

    result.object( objectQ )
    result.generator( generator )
    return result

def Table3x3( P_dll,
        P_config = None,
        P_box = None
        ):

    result    = IceRayPy.core.geometry.hfield.System(P_dll)

    generator = IceRayPy.core.geometry.hfield.generator.Table(P_dll)
    generator.size( Size2D( 3, 3 ) )
    generator.value( Size2D(0,0), 0.25 )
    generator.value( Size2D(0,1), 0.25 )
    generator.value( Size2D(0,2), 0.25 )

    generator.value( Size2D(1,0), 0.25 )
    generator.value( Size2D(1,1), 0.5 )
    generator.value( Size2D(1,2), 0.25 )

    generator.value( Size2D(2,0), 0.25 )
    generator.value( Size2D(2,1), 0.25 )
    generator.value( Size2D(2,2), 0.25 )

    objectQ = IceRayPy.core.geometry.hfield.object.Quad(P_dll)
    objectF = IceRayPy.core.geometry.hfield.object.Flat(P_dll)
    objectV = IceRayPy.core.geometry.hfield.object.Vacuum(P_dll)
    objectT = IceRayPy.core.geometry.hfield.object.Triangle(P_dll)

    result.object( objectQ )
    result.generator( generator )
    return result

def Table4x4( P_dll,
        P_config = None,
        P_box = None
        ):

    result    = IceRayPy.core.geometry.hfield.System(P_dll)

    generator = IceRayPy.core.geometry.hfield.generator.Table(P_dll)
    generator.size( Size2D( 4, 4 ) )
    generator.value( Size2D(0,0), 0.25 )
    generator.value( Size2D(0,1), 0.25 )
    generator.value( Size2D(0,2), 0.25 )
    generator.value( Size2D(0,3), 0.25 )

    generator.value( Size2D(1,0), 0.25 )
    generator.value( Size2D(1,1), 0.5 )
    generator.value( Size2D(1,2), 0.5 )
    generator.value( Size2D(1,3), 0.25 )

    generator.value( Size2D(2,0), 0.25 )
    generator.value( Size2D(2,1), 0.5 )
    generator.value( Size2D(2,2), 0.5 )
    generator.value( Size2D(2,3), 0.25 )

    generator.value( Size2D(3,0), 0.25 )
    generator.value( Size2D(3,1), 0.25 )
    generator.value( Size2D(3,2), 0.25 )
    generator.value( Size2D(3,3), 0.25 )

    objectQ = IceRayPy.core.geometry.hfield.object.Quad(P_dll)
    objectF = IceRayPy.core.geometry.hfield.object.Flat(P_dll)
    objectV = IceRayPy.core.geometry.hfield.object.Vacuum(P_dll)
    objectT = IceRayPy.core.geometry.hfield.object.Triangle(P_dll)

    result.object( objectQ )
    result.generator( generator )
    return result

def Table5x5( P_dll,
        P_config = None,
        P_box = None
        ):

    result    = IceRayPy.core.geometry.hfield.System(P_dll)

    generator = IceRayPy.core.geometry.hfield.generator.Table(P_dll)

    I_size = 5
    if( 'frame' in P_config ):
        if( 'index' in P_config['frame'] ):
            I_size = int( P_config['frame']['index'] / 30 + 2 )

    generator.size( Size2D( I_size, I_size ) )

    objectQ = IceRayPy.core.geometry.hfield.object.Quad(P_dll)
    objectF = IceRayPy.core.geometry.hfield.object.Flat(P_dll)
    objectV = IceRayPy.core.geometry.hfield.object.Vacuum(P_dll)
    objectT = IceRayPy.core.geometry.hfield.object.Triangle(P_dll)

    result.object( objectQ )
    result.generator( generator )
    return result


#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
