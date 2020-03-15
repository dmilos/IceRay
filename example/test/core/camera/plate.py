import sys
import time
import IceRayCpp

import engine
import image
import object
import surface

import cylinder
import flat
import sphere
import scene

from cylinder.unit import make
from sphere.unit import make
from flat.orthogonal.unit import make
from flat.perspective.unit import make

def main( P_name, P_camera ):

    cargo_engine = engine.make( scene.make(), P_camera )

    print( 'Start rendering' )
    sys.stdout.flush()

    cargo_image = image.make( 600, 600 )
    clock = time.perf_counter()
    cargo_engine['this'].start( cargo_image['this'] )
    clock = time.perf_counter() - clock
    print( 'Rendering time: ' + str( clock ) )
    print( 'End rendering' )

    print( 'Save Image' )
    angle = 0

    file_name = P_name +"-plate"
    file_name += '.ppm'

    print( IceRayCpp.GraphPictureStorePNM( file_name, cargo_image['this'] ) );

    print( 'All Done' )

def light_make( P_light ):

    blocked = IceRayCpp.LightBlocked()

    blocked.light( P_light['this'] )

    return { 'this': blocked, '0': P_light }


camera_list = {
    'sphere'       : sphere.unit.make,
    'cylindric'    : cylinder.unit.make,
    'perspective'  : flat.perspective.unit.make,
    'orthogonal'   : flat.orthogonal.unit.make,
    #'cone'        : IceRayCpp.CameraFocus,
    #'focal'       : IceRayCpp.CameraFocus,
    }

for key_camera, data_camera in camera_list.items():
    print ( key_camera )
    main( key_camera, data_camera() )


