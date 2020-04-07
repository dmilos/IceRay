import sys
import time
import math
import IceRayCpp

#from test.core import *
import engine
import image
import room
import surface
import light


def work( P_name, P_room, P_config, P_geometry, P_light, P_camera, P_surface, P_medium ):
    surface_global={}
    surface_global['room']={}

    surface_global['room'][  'background'] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.00,  0.50,  0.00 ) ) # green
    surface_global['room'][  'foreground'] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.00,  0.50,  0.00 ) ) # green
    surface_global['room'][  'floor'     ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.50,  0.50,  0.50 ) ) # gray
    surface_global['room'][  'right'     ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.00,  0.00,  0.75 ) ) # blue
    surface_global['room'][  'left'      ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.75,  0.00,  0.00 ) ) # red
    surface_global['room'][  'ceil'      ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.0,   0.5,   0.0 ) ) # gray
    surface_global['room'][  'bubble'    ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.10,  0.10,  0.10 ) ) # white
    surface_global['room'][  'fence'     ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.10,  0.10,  0.10 ) ) # white
    surface_global['room'][  'box'       ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.10,  0.10,  0.10 ) ) # white

    surface_global['room'][  'Side0'  ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side1'  ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side2'  ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side3'  ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side4'  ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side5'  ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side6'  ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side7'  ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side8'  ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side9'  ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side10' ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side11' ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side12' ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side13' ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side14' ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side15' ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side16' ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side17' ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side18' ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side19' ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white
    surface_global['room'][  'Side20' ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # white

    surface_global['room'][  'lambert-red'   ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 1.0,  0.0,  0.0 ) )
    surface_global['room'][  'lambert-green' ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.0,  1.0,  0.0 ) )
    surface_global['room'][  'lambert-blue'  ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.0,  0.0,  1.0 ) )
    surface_global['room'][  'lambert-white' ] = surface.make_lambert(P_light, IceRayCpp.GraphTypeColorRGB().load( 1.0,  1.0,  1.0 ) )

    #surface_global['room'][  'background'] = surface.make_ambient(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ) ) # green
    #surface_global['room'][  'foreground'] = surface.make_ambient(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.0, 0.5, 0.5 ) ) # green
    #surface_global['room'][  'floor'     ] = surface.make_ambient(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.0, 0.5, 0.5 ) )
    #surface_global['room'][  'right'     ] = surface.make_ambient(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.0, 0.0, 0.5 ) )
    #surface_global['room'][  'left'      ] = surface.make_ambient(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.0, 0.0 ) )
    #surface_global['room'][  'ceil'      ] = surface.make_ambient(P_light, IceRayCpp.GraphTypeColorRGB().load( 0.0, 0.5, 0.0 ) )

   #surface_global['room'][  'background'] = surface.make_radiosityHexagon( IceRayCpp.GraphTypeColorRGB().load( 0.4, 0.4, 0.4 ) )
    #c = IceRayCpp.GraphTypeColorRGB();
    #surface_global['room'][  'floor'     ] = surface.make_radiosityVDC( P_light, c.load( 0.01, 0.01, 0.01 ), 13.5*c.load( 0.1, 0.1, 0.1 ), math.radians(P_config['angle']), P_config['sample'] )
    #surface_global['room'][  'right'     ] = surface.make_radiosityHexagon( c.load( 0.00, 0.00, 0.04 ), 13.5*c.load( 0.0, 0.0, 0.4 ), math.radians(P_config['angle']), P_config['sample'] )
    #surface_global['room'][  'left'      ] = surface.make_radiosityVDC( c.load( 0.04, 0.00, 0.00 ), 13.5*c.load( 0.4, 0.0, 0.0 ), math.radians(P_config['angle']), P_config['sample'] )
    #surface_global['room'][  'ceil'      ] = surface.make_radiosityGrid( c.load( 0.00, 0.04, 0.00 ), 13.5*c.load( 0.0, 0.4, 0.0 ), math.radians(P_config['angle']), P_config['sample'] )

    surface_global['room'][  'background'] = surface.make_mirror( P_light )
    #surface_global['room'][  'foreground'] = surface.make_mirror( P_light )
    #surface_global['room'][  'floor'     ] = surface.make_mirror( P_light )
    #surface_global['room'][  'ceil'      ] = surface.make_mirror( P_light )
    #surface_global['room'][  'right'     ] = surface.make_mirror( P_light )
    #surface_global['room'][  'left'      ] = surface.make_mirror( P_light )
    #surface_global['room'][  'bubble'    ] = surface.make_mirror( P_light )
    #surface_global['room'][  'fence'     ] = surface.make_mirror( P_light )
    #surface_global['room'][  'box'       ] = surface.make_mirror( P_light )

    surface_global['room'][   'Side0' ] = surface.make_mirror( P_light )
    surface_global['room'][   'Side1' ] = surface.make_mirror( P_light )
    surface_global['room'][   'Side2' ] = surface.make_mirror( P_light )
    surface_global['room'][   'Side3' ] = surface.make_mirror( P_light )
    surface_global['room'][   'Side4' ] = surface.make_mirror( P_light )
    surface_global['room'][   'Side5' ] = surface.make_mirror( P_light )
    surface_global['room'][   'Side6' ] = surface.make_mirror( P_light )
    surface_global['room'][   'Side7' ] = surface.make_mirror( P_light )
    surface_global['room'][   'Side8' ] = surface.make_mirror( P_light )
    surface_global['room'][   'Side9' ] = surface.make_mirror( P_light )
    surface_global['room'][  'Side10' ] = surface.make_mirror( P_light )
    surface_global['room'][  'Side11' ] = surface.make_mirror( P_light )
    surface_global['room'][  'Side12' ] = surface.make_mirror( P_light )
    surface_global['room'][  'Side13' ] = surface.make_mirror( P_light )
    surface_global['room'][  'Side14' ] = surface.make_mirror( P_light )
    surface_global['room'][  'Side15' ] = surface.make_mirror( P_light )
    surface_global['room'][  'Side16' ] = surface.make_mirror( P_light )
    surface_global['room'][  'Side17' ] = surface.make_mirror( P_light )
    surface_global['room'][  'Side18' ] = surface.make_mirror( P_light )
    surface_global['room'][  'Side19' ] = surface.make_mirror( P_light )
    surface_global['room'][  'Side20' ] = surface.make_mirror( P_light )

    if( False ):
        surface_global['room'][  'light' ] = surface.make_ambient( P_light, IceRayCpp.GraphTypeColorRGB().load( 10.8, 10.8, 10.8 ) )

    surface_global['exponat'] = P_surface

    cargo_engine = engine.make( P_room( P_geometry, P_light, surface_global['exponat'], surface_global['room'], P_medium ), P_camera )
    cargo_engine['this'].depth( 16 )
    if( 'ray-trace-depth' in P_config ):
        cargo_engine['this'].depth( P_config['ray-trace-depth'] )

    if( 'pixelStrategyGridSize' in P_config ):
        cargo_engine['this'].pixelStrategy().size( P_config['pixelStrategyGridSize'] )
        pass # set grid pixel strategy instead of Center
    else:
        cargo_engine['this'].pixelStrategy().size( 1 )

    if( 'hot' in P_config ):
        cargo_engine['this'].scannerGet().hot( IceRayCpp.MathTypeSize2D( ).load( P_config['hot']['x'], P_config['hot']['y'] ) )

    sys.stdout.flush()

    scale = 123
    width  = int(scale*10)
    height = int(scale*10)

    if( 'image' in P_config ):
        scale  = P_config['image']['scale']
        width  = P_config['image']['width']
        height = P_config['image']['height']

    width  = int(width*scale)
    height = int(height*scale)

    cargo_image = image.make( width, height )
    print( 'Start rendering on: ' + str( width ) + " x "+ str( height ) )
    clock = time.perf_counter()
    #lo = IceRayCpp.MathTypeSize2D( ).load( int(width*0), int( height*0.48) )
    #hi = IceRayCpp.MathTypeSize2D( ).load( int(width*1), int( height*0.52) )
    #cargo_engine['this'].scannerGet().range( IceRayCpp.MathTypeRange2D( lo , hi ) )
    sys.stdout.flush()
    cargo_engine['this'].start( cargo_image['this'] )
    clock = time.perf_counter() - clock
    print( 'Rendering time: ' + str( clock ) )
    print( 'End rendering' )
    print( 'Save Image' )
    sys.stdout.flush()

    file_name = P_name
    file_name += '_'+ "{:04d}".format(P_config['index'])
    #file_name += '_'+ "{:03.3f}".format(P_config['extra-angle'])
    #file_name += '_'+ "{:04d}".format(P_config['extra-sample'])
    #if( 'pixelStrategyGridSize' in P_config ):
    #    file_name +=  '-' + "{:03d}".format(P_config['pixelStrategyGridSize'])

    #file_name += '-AAA.ppm'
    file_name += '.ppm'

    result = IceRayCpp.GraphPictureStorePNM( file_name, cargo_image['this'] )
    print( "File name: (" + str(  result ) + ") - " + file_name );

    print( 'All Done' )