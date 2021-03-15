import IceRayPy

Coord3D = IceRayPy.type.math.coord.Scalar3D


def vacuum( P_dll, P_config = None, P_light = None, P_exponat = None ):
    geometry = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( geometry )
    return wrapper

def plate( P_dll, P_config = { 'level':  - 1.01, 'size' : 3, 'shadow': False, 'pigment': None }, P_light = None, P_exponat = None ):

    level = -1.00001;
    if( 'level' in P_config ):
        level = P_config['level']
    size = 3;
    if( 'size' in P_config ):
        size = P_config['size']

    geometry = IceRayPy.core.geometry.simple.Box( P_dll )
    geometry.box(        Coord3D(  -size, -size, level - 0.1) , Coord3D( size,      size, level ) )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )

    I_scene = { 'light': P_light, 'barrier' : P_exponat   }
    if( 'shadow' in P_config ):
        if( False == P_config['shadow'] ):
            I_scene['barrier'] = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
    if( 'pigment' in P_config ):
        pigment = P_config['pigment'] #utility.material.pattern.Checker( P_dll, I_scene )

    #pigment = IceRayPy.utility.material.pattern.Checker( P_dll, I_scene )

    wrapper.pigment( pigment )

    wrapper.geometrySet( geometry )

    return wrapper


def plane( P_dll, P_config = { 'level':  - 1.001, 'shadow': False, 'pigment': None }, P_light = None, P_exponat = None ):

    level = -1.0001;
    if( 'level' in P_config ):
        level = P_config['level']
    geometry = IceRayPy.core.geometry.simple.Plane( P_dll )
    geometry.origin( Coord3D(0,   0, level ) )


    I_scene = { 'light': P_light, 'barrier' : P_exponat }
    if( 'shadow' in P_config ):
        if( False == P_config['shadow'] ):
            I_scene['barrier'] = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
    if( 'pigment' in P_config ):
        pigment = P_config['pigment'] #utility.material.pattern.Checker( P_dll, I_scene )

    pigment = IceRayPy.utility.material.pattern.Checker( P_dll, I_scene )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.pigment( pigment )
    wrapper.geometrySet( geometry )

    return wrapper

def cornel( P_dll, P_config = None, P_light = None, P_exponat = None ):
    move = [ 0, 0, 0 ]
    I_dimension = [ 36, 36, 36 ]
    wall = 0.1

    lo = Coord3D()
    lo[0] = -I_dimension[0]/2 + move[0]
    lo[1] = -I_dimension[1]/2 + move[1]
    lo[2] = -I_dimension[2]/2 + move[2]

    hi = Coord3D()
    hi[0] = +I_dimension[0]/2 + move[0]
    hi[1] = +I_dimension[1]/2 + move[1]
    hi[2] = +I_dimension[2]/2 + move[2]

    I_scene = { 'light': P_light, 'barrier' : P_exponat }
    if( 'shadow' in P_config ):
        if( False == P_config['shadow'] ):
            I_scene['barrier'] = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    leftG = IceRayPy.core.geometry.simple.Box( P_dll )
    leftG.box(        Coord3D(  lo[0]-wall, lo[1], lo[2]) , Coord3D(lo[0],      hi[1], hi[2]) )
    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.5 , 0.5, 0.5 ) )
    leftW = IceRayPy.core.object.Wrapper( P_dll )
    leftW.pigment( pigment )
    leftW.geometrySet( leftG )

    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
    rightG = IceRayPy.core.geometry.simple.Box( P_dll )
    rightG.box(       Coord3D( hi[0],      lo[1], lo[2]) ,  Coord3D(hi[0]+ wall,hi[1], hi[2]) )
    rightW = IceRayPy.core.object.Wrapper( P_dll )
    rightW.pigment( pigment )
    rightW.geometrySet( rightG )

    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 1, 0.33, 0.33 ) )
    backgroundG = IceRayPy.core.geometry.simple.Box( P_dll )
    backgroundG.box(  Coord3D( lo[0], lo[1]-wall, lo[2] ) , Coord3D( hi[0], lo[1], hi[2] ) )
    backgroundW = IceRayPy.core.object.Wrapper( P_dll )
    backgroundW.pigment( pigment )
    backgroundW.geometrySet( backgroundG )

    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.33, 1, 0.33 ) )
    foregroundG = IceRayPy.core.geometry.simple.Box( P_dll )
    foregroundG.box(  Coord3D( lo[0], hi[1],  lo[2] ),      Coord3D( hi[0], hi[1] + wall, hi[2] ) )
    foregroundW = IceRayPy.core.object.Wrapper( P_dll )
    foregroundW.pigment( pigment )
    foregroundW.geometrySet( foregroundG )

    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
    floorG = IceRayPy.core.geometry.simple.Box( P_dll )
    floorG.box(       Coord3D( lo[0], lo[1], lo[2]-wall ) , Coord3D( hi[0], hi[0], lo[2] ) )
    floorW = IceRayPy.core.object.Wrapper( P_dll )
    floorW.pigment( pigment )
    floorW.geometrySet( floorG )

    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
    ceilG = IceRayPy.core.geometry.simple.Box( P_dll )
    ceilG.box(        Coord3D( lo[0], lo[1], hi[2] ),       Coord3D( hi[0], hi[1], hi[2] + wall ) )
    ceilW = IceRayPy.core.object.Wrapper( P_dll )
    ceilW.pigment( pigment )
    ceilW.geometrySet( ceilG )
    
    rtss = IceRayPy.core.geometry.rtss.Object( P_dll )

    list = IceRayPy.core.geometry.rtss.List( P_dll )
    rtss.rtss( list )

    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, leftW.cast2Geometry(),       leftW ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, rightW.cast2Geometry(),      rightW ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, backgroundW.cast2Geometry(), backgroundW ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, foregroundW.cast2Geometry(), foregroundW ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, floorW.cast2Geometry(),      floorW ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, ceilW.cast2Geometry(),       ceilW ) )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( rtss )

    return wrapper
