import IceRayPy

def arange(  P_dll
            ,P_exponat
            ,P_room
            ,P_radiator = None
            ):

    rtss = IceRayPy.core.geometry.rtss.Object( P_dll )

    list = IceRayPy.core.geometry.rtss.List( P_dll )

    rtss.rtss( list )

    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, P_room.cast2Geometry(),    P_room ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, P_exponat.cast2Geometry(), P_exponat ) )

    if( None != P_radiator ):
        rtss.push( IceRayPy.core.geometry.Pretender( P_dll, P_radiator.cast2Geometry(), P_radiator ) )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( rtss )

    return wrapper


def camera( P_dll,
          P_camera,
          P_eye,  #= IceRayPy.type.math.coord.load3D( P_dll, 2, 5, 3 )*0.6,
          P_view #= IceRayPy.type.math.coord.fill3D( P_dll, 0 ),
          ):
    transform = IceRayPy.core.camera.transform.Affine( P_dll )

    transform.child( P_camera )

    I_up   = IceRayPy.type.math.coord.load3D( P_dll, 0, 0, 1 )

    transform.toWorldSet( IceRayPy.type.math.affine.lookAt( P_dll, P_eye, P_view, I_up ) )

    return transform


def object( P_dll, P_geometry, P_pigment, P_medium ):

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( P_geometry )
    wrapper.pigment( P_pigment )
    wrapper.medium( P_medium )

    return wrapper


def manager( P_config, P_camera, P_object ):
    sheaf_all = IceRayPy.core.render.sheaf.ALL( P_config['dll'] )

    pierce_projector = IceRayPy.core.render.pierce.Projector( P_config['dll'] )

    pierce_projector.camera( P_camera )

    pixel_basic = IceRayPy.core.render.pixel.Basic( P_config['dll'] )

    ray_trace    = IceRayPy.core.render.ray.Trace( P_config['dll'] )

    ray_trace.depth(20)
    ray_trace.trash( 0.001 )
    ray_trace.next( 18 )
    if( 'ray-trace' in P_config ):
        if( 'depth' in P_config['ray-trace'] ):
            ray_trace.depth( P_config['ray-trace']['depth'] )
        if( 'trash' in P_config['ray-trace'] ):
            ray_trace.trash( P_config['ray-trace']['trash'] )
        if( 'next' in P_config['ray-trace'] ):
            ray_trace.next( P_config['ray-trace']['next'] )

    ray_trace.object( P_object )

    scanner_all = IceRayPy.core.render.scanner.Block( P_config['dll'] )
    scanner_all.hot( IceRayPy.type.math.coord.Size2D( P_config['hot']['x'], P_config['hot']['y'] ) )

    scanner_all.window(  IceRayPy.type.math.coord.Size2D( P_config['window']['A']['x'], P_config['window']['A']['y'] )
                        ,IceRayPy.type.math.coord.Size2D( P_config['window']['B']['x'], P_config['window']['B']['y'] )
                      )

    manager = IceRayPy.core.render.manager.TheOne(  P_config['dll']  )

    manager.scanner( scanner_all )
    manager.pixel( pixel_basic )
    manager.pierce( pierce_projector )
    manager.sheaf( sheaf_all )
    manager.ray( ray_trace )

    return manager
