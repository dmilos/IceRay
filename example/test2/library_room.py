import math
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

    geometry = IceRayPy.core.geometry.flat.Box( P_dll )
    geometry.box(        Coord3D(  -size, -size, level - 0.1) , Coord3D( size,      size, level ) )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )

    I_scene = { 'light': P_light, 'barrier' : P_exponat   }
    if( 'shadow' in P_config ):
        if( False == P_config['shadow'] ):
            I_scene['barrier'] = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
    if( 'pigment' in P_config ):
        pigment = P_config['pigment'] #utility.material.pattern.Checker( P_dll, I_scene )

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

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.pigment( pigment )
    wrapper.geometrySet( geometry )

    return wrapper


def pigment_radiosity( P_dll, P_scene, P_config ):
    I_blossom = 'triangle'
    I_sample = 1
    I_angle = math.radians( 75 )
    I_jitter = math.radians( 15 )
    I_albedo = IceRayPy.type.color.RGB( 0.85, 0.85, 0.85 )

    if( None != P_config ):
        if( 'blossom' in P_config ):
            I_blossom = P_config['blossom']
        if( 'sample' in P_config ):
            I_sample = P_config['sample']
        if( 'angle' in P_config ):
            I_angle = P_config['angle']
        if( 'jitter' in P_config ):
            I_jitter = P_config['jitter']
        if( 'albedo' in P_config ):
            I_albedo = P_config['albedo']

    if 'one' == I_blossom :
        pigment = IceRayPy.utility.material.transmission.reflect.One(      P_dll, {}, I_albedo ) #OK
    if 'vdc' == I_blossom :
        pigment = IceRayPy.utility.material.transmission.blossom.VDC(      P_dll, P_config, I_albedo, I_sample, 0, I_angle )#OK
    if 'random' == I_blossom :
        pigment = IceRayPy.utility.material.transmission.blossom.Random(   P_dll, P_config, I_albedo, I_sample, 0, I_angle )#OK
    if 'sobol' == I_blossom :
        pigment = IceRayPy.utility.material.transmission.blossom.Sobol(    P_dll, P_config, I_albedo, I_sample, 0, I_angle )#OK
    if 'hexagon' == I_blossom :
        pigment = IceRayPy.utility.material.transmission.blossom.Hexagon(  P_dll, P_config, I_albedo, I_sample, 0, I_angle )#OK
    if 'grid' == I_blossom :
        pigment = IceRayPy.utility.material.transmission.blossom.Grid(     P_dll, P_config, I_albedo, I_sample, 0, I_angle )#OK
    if 'triangle' == I_blossom :
        pigment = IceRayPy.utility.material.transmission.blossom.Triangle( P_dll, P_config, I_albedo, I_sample, 0, I_angle )#OK
    if 'congruent' == I_blossom :
        pigment = IceRayPy.utility.material.transmission.blossom.Congruent( P_dll, P_config, I_albedo, I_sample, 0, I_angle )#OK

    return pigment

def radiosity_plane( P_dll, P_config = { 'level':  - 1.001, 'shadow': False, 'pigment': None }, P_light = None, P_exponat = None ):
    level = -1.0001;
    if( 'level' in P_config ):
        level = P_config['level']
    geometry = IceRayPy.core.geometry.simple.Plane( P_dll )
    geometry.origin( Coord3D(0,   0, level ) )

    I_scene = { 'light': P_light, 'barrier' : P_exponat }
    if( 'shadow' in P_config ):
        if( False == P_config['shadow'] ):
            I_scene['barrier'] = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )

    if( 'radiosity' in P_config ):
        pigment = pigment_radiosity( P_dll, I_scene, P_config['radiosity'] )
    else:
        pigment = pigment_radiosity( P_dll, I_scene, {} )

    wrapper.pigment( pigment )
    wrapper.geometrySet( geometry )

    return wrapper


def disc( P_dll, P_config = { 'level':  - 1.001, 'shadow': False, 'pigment': None }, P_light = None, P_exponat = None ):
    level = -1.0001;
    if( 'level' in P_config ):
        level = P_config['level']
    geometry = IceRayPy.core.geometry.simple.Disc( P_dll )
    geometry.radius( 3 )
    geometry.center( Coord3D( 0, 0, level ) )
    geometry.normal( Coord3D( 0, 0, 1 ) )

    I_scene = { 'light': P_light, 'barrier' : P_exponat }
    if( 'shadow' in P_config ):
        if( False == P_config['shadow'] ):
            I_scene['barrier'] = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
    if( 'pigment' in P_config ):
        pigment = P_config['pigment'] #utility.material.pattern.Checker( P_dll, I_scene )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.pigment( pigment )
    wrapper.geometrySet( geometry )

    return wrapper

def cornel_open( P_dll, P_config = {}, P_light = None, P_exponat = None ): # non-classic

    global G_dimesion
    I_room = [ 8, 8, 4 ] # [ 6, 6, 3.5 ]
    I_move = [ 0, 0, I_room[2]/2-1 ]
    wall = 0.1

    lo = Coord3D()
    lo[0] = -I_room[0]/2 + I_move[0]
    lo[1] = -I_room[1]/2 + I_move[1]
    lo[2] = -I_room[2]/2 + I_move[2]

    hi = Coord3D()
    hi[0] = +I_room[0]/2 + I_move[0]
    hi[1] = +I_room[1]/2 + I_move[1]
    hi[2] = +I_room[2]/2 + I_move[2]

    I_scene = { 'light': P_light, 'barrier' : P_exponat }
    if( 'shadow' in P_config ):
        if( False == P_config['shadow'] ):
            I_scene['barrier'] = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    leftG = IceRayPy.core.geometry.flat.Box( P_dll )
    leftG.box(        Coord3D(  lo[0]-wall, lo[1], lo[2]) , Coord3D(lo[0],      hi[1], hi[2]) )
    leftW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 1, 0.33, 0.33 ) )
    leftW.pigment( pigment )
    leftW.geometrySet( leftG )

    rightG = IceRayPy.core.geometry.flat.Box( P_dll )
    rightG.box(       Coord3D( hi[0],      lo[1], lo[2]) ,  Coord3D(hi[0]+ wall,hi[1], hi[2]) )
    rightW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.33, 1, 0.33 ) )
    rightW.pigment( pigment )
    rightW.geometrySet( rightG )

    backgroundG = IceRayPy.core.geometry.flat.Box( P_dll )
    backgroundG.box(  Coord3D( lo[0], lo[1]-wall, lo[2] ) , Coord3D( hi[0], lo[1], hi[2] ) )
    backgroundW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.33, 0.33, 1 ) )
    backgroundW.pigment( pigment )
    backgroundW.geometrySet( backgroundG )

    floorG = IceRayPy.core.geometry.flat.Box( P_dll )
    floorG.box(       Coord3D( lo[0], lo[1], lo[2]-wall ) , Coord3D( hi[0], hi[0], lo[2] ) )
    floorW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
    floorW.pigment( pigment )
    floorW.geometrySet( floorG )

    ceilG = IceRayPy.core.geometry.flat.Box( P_dll )
    ceilG.box(        Coord3D( lo[0], lo[1], hi[2] ),       Coord3D( hi[0], hi[1], hi[2] + wall ) )
    ceilW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
    ceilW.pigment( pigment )
    ceilW.geometrySet( ceilG )

    rtss = IceRayPy.core.geometry.rtss.Object( P_dll )

    list = IceRayPy.core.geometry.rtss.List( P_dll )
    rtss.rtss( list )

    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, leftW.cast2Geometry(),       leftW       ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, rightW.cast2Geometry(),      rightW      ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, backgroundW.cast2Geometry(), backgroundW ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, floorW.cast2Geometry(),      floorW      ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, ceilW.cast2Geometry(),       ceilW       ) )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( rtss )

    return wrapper




def cornel_close( P_dll, P_config = {}, P_light = None, P_exponat = None ): # non-classic

    global G_dimesion
    I_room = [ 8, 8, 4 ] # [ 6, 6, 3.5 ]
    I_move = [ 0, 0, I_room[2]/2-1 ]
    wall = 0.1

    lo = Coord3D()
    lo[0] = -I_room[0]/2 + I_move[0]
    lo[1] = -I_room[1]/2 + I_move[1]
    lo[2] = -I_room[2]/2 + I_move[2]

    hi = Coord3D()
    hi[0] = +I_room[0]/2 + I_move[0]
    hi[1] = +I_room[1]/2 + I_move[1]
    hi[2] = +I_room[2]/2 + I_move[2]

    I_scene = { 'light': P_light, 'barrier' : P_exponat }
    if( 'shadow' in P_config ):
        if( False == P_config['shadow'] ):
            I_scene['barrier'] = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    leftG = IceRayPy.core.geometry.flat.Box( P_dll )
    leftG.box(        Coord3D(  lo[0]-wall, lo[1], lo[2]) , Coord3D(lo[0],      hi[1], hi[2]) )
    leftW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 1, 0.33, 0.33 ) )
    leftW.pigment( pigment )
    leftW.geometrySet( leftG )

    rightG = IceRayPy.core.geometry.flat.Box( P_dll )
    rightG.box(       Coord3D( hi[0],      lo[1], lo[2]) ,  Coord3D(hi[0]+ wall,hi[1], hi[2]) )
    rightW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.33, 1, 0.33 ) )
    rightW.pigment( pigment )
    rightW.geometrySet( rightG )

    backgroundG = IceRayPy.core.geometry.flat.Box( P_dll )
    backgroundG.box(  Coord3D( lo[0], lo[1]-wall, lo[2] ) , Coord3D( hi[0], lo[1], hi[2] ) )
    backgroundW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.33, 0.33, 1 ) )
    backgroundW.pigment( pigment )
    backgroundW.geometrySet( backgroundG )

    foregroundG = IceRayPy.core.geometry.flat.Box( P_dll )
    foregroundG.box(  Coord3D( lo[0], hi[1],  lo[2] ),      Coord3D( hi[0], hi[1] + wall, hi[2] ) )
    foregroundW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.transmission.reflect.One( P_dll, I_scene )
    foregroundW.pigment( pigment )
    foregroundW.geometrySet( foregroundG )

    floorG = IceRayPy.core.geometry.flat.Box( P_dll )
    floorG.box(       Coord3D( lo[0], lo[1], lo[2]-wall ) , Coord3D( hi[0], hi[0], lo[2] ) )
    floorW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
    floorW.pigment( pigment )
    floorW.geometrySet( floorG )

    ceilG = IceRayPy.core.geometry.flat.Box( P_dll )
    ceilG.box(        Coord3D( lo[0], lo[1], hi[2] ),       Coord3D( hi[0], hi[1], hi[2] + wall ) )
    ceilW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
    ceilW.pigment( pigment )
    ceilW.geometrySet( ceilG )

    rtss = IceRayPy.core.geometry.rtss.Object( P_dll )

    list = IceRayPy.core.geometry.rtss.List( P_dll )
    rtss.rtss( list )

    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, leftW.cast2Geometry(),       leftW       ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, rightW.cast2Geometry(),      rightW      ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, backgroundW.cast2Geometry(), backgroundW ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, foregroundW.cast2Geometry(), foregroundW ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, floorW.cast2Geometry(),      floorW      ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, ceilW.cast2Geometry(),       ceilW       ) )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( rtss )

    return wrapper


def cornell_radiosity(
     P_dll
    ,P_config  = None
    ,P_light   = None
    ,P_exponat = None
    ): # non-classic

    I_room = [ 8, 8, 4 ] # [ 6, 6, 3.5 ]
    I_move = [ 0, 0, I_room[2]/2-1 ]
    wall = 0.1

    lo = Coord3D()
    lo[0] = -I_room[0]/2 + I_move[0]
    lo[1] = -I_room[1]/2 + I_move[1]
    lo[2] = -I_room[2]/2 + I_move[2]

    hi = Coord3D()
    hi[0] = +I_room[0]/2 + I_move[0]
    hi[1] = +I_room[1]/2 + I_move[1]
    hi[2] = +I_room[2]/2 + I_move[2]

    I_scene = { 'light': P_light, 'barrier' : P_exponat }
    if( 'shadow' in P_config ):
        if( False == P_config['shadow'] ):
            I_scene['barrier'] = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    leftG = IceRayPy.core.geometry.flat.Box( P_dll )
    leftG.box(        Coord3D(  lo[0]-wall, lo[1], lo[2]) , Coord3D(lo[0],      hi[1], hi[2]) )
    leftW = IceRayPy.core.object.Wrapper( P_dll )
    P_config['albedo'] = IceRayPy.type.color.RGB( 1, 0.33, 0.33 )
    pigment = pigment_radiosity( P_dll, I_scene, P_config['radiosity'] )
    leftW.pigment( pigment )
    leftW.geometrySet( leftG )

    rightG = IceRayPy.core.geometry.flat.Box( P_dll )
    rightG.box(       Coord3D( hi[0],      lo[1], lo[2]) ,  Coord3D(hi[0]+ wall,hi[1], hi[2]) )
    rightW = IceRayPy.core.object.Wrapper( P_dll )
    P_config['albedo'] = IceRayPy.type.color.RGB( 0.33, 1, 0.33 )
    pigment = pigment_radiosity( P_dll, I_scene, P_config['radiosity'] )
    rightW.pigment( pigment )
    rightW.geometrySet( rightG )

    backgroundG = IceRayPy.core.geometry.flat.Box( P_dll )
    backgroundG.box(  Coord3D( lo[0], lo[1]-wall, lo[2] ) , Coord3D( hi[0], lo[1], hi[2] ) )
    backgroundW = IceRayPy.core.object.Wrapper( P_dll )
    P_config['albedo'] = IceRayPy.type.color.RGB( 0.33, 0.33, 1 )
    pigment = pigment_radiosity( P_dll, I_scene, P_config['radiosity'] )
    backgroundW.pigment( pigment )
    backgroundW.geometrySet( backgroundG )

    foregroundG = IceRayPy.core.geometry.flat.Box( P_dll )
    foregroundG.box(  Coord3D( lo[0], hi[1],  lo[2] ),      Coord3D( hi[0], hi[1] + wall, hi[2] ) )
    foregroundW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.transmission.reflect.Mirror( P_dll, I_scene )
    foregroundW.pigment( pigment )
    foregroundW.geometrySet( foregroundG )

    floorG = IceRayPy.core.geometry.flat.Box( P_dll )
    floorG.box(       Coord3D( lo[0], lo[1], lo[2]-wall ) , Coord3D( hi[0], hi[0], lo[2] ) )
    floorW = IceRayPy.core.object.Wrapper( P_dll )
    P_config['albedo'] = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    pigment = pigment_radiosity( P_dll, I_scene, P_config['radiosity'] )
    floorW.pigment( pigment )
    floorW.geometrySet( floorG )

    ceilG = IceRayPy.core.geometry.flat.Box( P_dll )
    ceilG.box(        Coord3D( lo[0], lo[1], hi[2] ),       Coord3D( hi[0], hi[1], hi[2] + wall ) )
    ceilW = IceRayPy.core.object.Wrapper( P_dll )
    P_config['albedo'] = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    pigment = IceRayPy.utility.material.transmission.reflect.One( P_dll, I_scene )
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


def mirror_box(
     P_dll
    ,P_config = None
    ,P_light = None
    ,P_exponat = None
    ): # non-classic

    I_room = [ 8, 8, 4 ] # [ 6, 6, 3.5 ]
    I_move = [ 0, 0, I_room[2]/2-1 ]
    wall = 0.1

    lo = Coord3D()
    lo[0] = -I_room[0]/2 + I_move[0]
    lo[1] = -I_room[1]/2 + I_move[1]
    lo[2] = -I_room[2]/2 + I_move[2]

    hi = Coord3D()
    hi[0] = +I_room[0]/2 + I_move[0]
    hi[1] = +I_room[1]/2 + I_move[1]
    hi[2] = +I_room[2]/2 + I_move[2]

    I_scene = { 'light': P_light, 'barrier' : P_exponat }
    if( 'shadow' in P_config ):
        if( False == P_config['shadow'] ):
            I_scene['barrier'] = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    leftG = IceRayPy.core.geometry.flat.Box( P_dll )
    leftG.box(        Coord3D(  lo[0]-wall, lo[1], lo[2]) , Coord3D(lo[0],      hi[1], hi[2]) )
    leftW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.transmission.reflect.Mirror( P_dll, I_scene )
    leftW.pigment( pigment )
    leftW.geometrySet( leftG )

    rightG = IceRayPy.core.geometry.flat.Box( P_dll )
    rightG.box(       Coord3D( hi[0],      lo[1], lo[2]) ,  Coord3D(hi[0]+ wall,hi[1], hi[2]) )
    rightW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.transmission.reflect.Mirror( P_dll, I_scene )
    rightW.pigment( pigment )
    rightW.geometrySet( rightG )

    backgroundG = IceRayPy.core.geometry.flat.Box( P_dll )
    backgroundG.box(  Coord3D( lo[0], lo[1]-wall, lo[2] ) , Coord3D( hi[0], lo[1], hi[2] ) )
    backgroundW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.transmission.reflect.Mirror( P_dll, I_scene )
    backgroundW.pigment( pigment )
    backgroundW.geometrySet( backgroundG )

    foregroundG = IceRayPy.core.geometry.flat.Box( P_dll )
    foregroundG.box(  Coord3D( lo[0], hi[1],  lo[2] ),      Coord3D( hi[0], hi[1] + wall, hi[2] ) )
    foregroundW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.transmission.reflect.Mirror( P_dll, I_scene )
    foregroundW.pigment( pigment )
    foregroundW.geometrySet( foregroundG )

    floorG = IceRayPy.core.geometry.flat.Box( P_dll )
    floorG.box(       Coord3D( lo[0], lo[1], lo[2]-wall ) , Coord3D( hi[0], hi[0], lo[2] ) )
    floorW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.transmission.reflect.Mirror( P_dll, I_scene )
    #pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 1, 1, 1 ) )
    floorW.pigment( pigment )
    floorW.geometrySet( floorG )

    ceilG = IceRayPy.core.geometry.flat.Box( P_dll )
    ceilG.box(        Coord3D( lo[0], lo[1], hi[2] ),       Coord3D( hi[0], hi[1], hi[2] + wall ) )
    ceilW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.transmission.reflect.Mirror( P_dll, I_scene )
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


def mirror_sphere(
     P_dll
    ,P_config = None
    ,P_light = None
    ,P_exponat = None
    ): # non-classic

    global G_dimesion
    I_room = [ 8, 8, 4 ] # [ 6, 6, 3.5 ]
    I_move = [ 0, 0, I_room[2]/2-1 ]
    wall = 0.1

    center = Coord3D()
    center[0] = 0
    center[1] = 0
    center[2] = 0

    radius = 5
    I_scene = { 'light': P_light, 'barrier' : P_exponat }
    if( 'shadow' in P_config ):
        if( False == P_config['shadow'] ):
            I_scene['barrier'] = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    horizonG = IceRayPy.core.geometry.simple.Sphere( P_dll )
    horizonG.radius( radius )
    horizonG.center( center )
    horizonW = IceRayPy.core.object.Wrapper( P_dll )
    pigment = IceRayPy.utility.material.transmission.reflect.One( P_dll, I_scene )
    #pigment = IceRayPy.utility.material.illumination.Lambert( P_dll, I_scene, IceRayPy.type.color.RGB( 1, 1, 1 ) )
    horizonW.pigment( pigment )
    horizonW.geometrySet( horizonG )

    rtss = IceRayPy.core.geometry.rtss.Object( P_dll )
    list = IceRayPy.core.geometry.rtss.List( P_dll )
    rtss.rtss( list )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, horizonW.cast2Geometry(),       horizonW ) )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( rtss )

    return wrapper

list = {
      'vacuum'      : vacuum,
      'plane'       : plane,
      'plate'       : plate,
      'disc'        : disc,
      'R-M-box'     : mirror_box,
       'R-M-sphere' : mirror_sphere,
      'C-radiosity' : cornell_radiosity,
      'C-open'      : cornel_open,
      'C-close'     : cornel_close,
      'R-plane'     : radiosity_plane
    }
