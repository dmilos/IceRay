import IceRayPy

def arange(  P_dll
            ,P_exponat
            ,P_room
            ,P_decoration = None
            ,P_radiator = None
            ):

    rtss = IceRayPy.core.geometry.rtss.Object( P_dll )
    rtss.rtss( IceRayPy.core.geometry.rtss.List( P_dll ) )

    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, P_room.cast2Geometry(),    P_room ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, P_exponat.cast2Geometry(), P_exponat ) )

    if( None != P_decoration ):
        rtss.push( IceRayPy.core.geometry.Pretender( P_dll, P_decoration.cast2Geometry(), P_decoration ) )
    if( None != P_radiator ):
        rtss.push( IceRayPy.core.geometry.Pretender( P_dll, P_radiator.cast2Geometry(), P_radiator ) )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( rtss )

    return wrapper


def camera( P_dll,
          P_camera, # camera object
          P_config,
          ):
    transform = IceRayPy.core.camera.transform.Affine( P_dll )

    if( 'sample' in P_config ):
        if( hasattr( P_camera, 'sample' ) ):
            P_camera.sample( P_config['sample'] )
    if( 'aspect' in P_config ):
        if( hasattr( P_camera, 'aspect' ) ):
            P_camera.aspect( P_config['aspect'] )

    #if( 'hfov' in P_config ):
    #    P_camera.sample( P_config['sample'] )
    #if( 'vfov' in P_config ):
    #    P_camera.sample( P_config['sample'] )

    transform.child( P_camera )

    I_up   = IceRayPy.type.math.coord.load3D( P_dll, 0, 0, 1 )

    transform.toWorldSet( IceRayPy.type.math.affine.lookAt( P_dll, P_config['eye'], P_config['view'], I_up ) )

    return transform

def object( P_dll, P_geometry, P_pigment, P_medium ):

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( P_geometry )
    wrapper.pigment( P_pigment )
    wrapper.medium( P_medium )

    return wrapper

def manager( P_dll, P_config, P_camera, P_object ):
    manager = IceRayPy.utility.render.Manager( P_dll )
    manager.camera( P_camera )
    manager.object( P_object )

    if( 'hot' in P_config ):
        manager.hot( IceRayPy.type.math.coord.Size2D( P_config['hot']['x'], P_config['hot']['y'] ) )

    if( 'window' in P_config ):
        manager.window(  IceRayPy.type.math.coord.Size2D( P_config['window']['A']['x'], P_config['window']['A']['y'] )
                        ,IceRayPy.type.math.coord.Size2D( P_config['window']['B']['x'], P_config['window']['B']['y'] )
                      )

    if( 'ray-trace' in P_config ):
        if( 'depth' in P_config['ray-trace'] ):
            manager.tracer().depth( P_config['ray-trace']['depth'] )
        if( 'trash' in P_config['ray-trace'] ):
            manager.tracer().trash( P_config['ray-trace']['trash'] )
        if( 'next' in P_config['ray-trace'] ):
            manager.tracer().next( P_config['ray-trace']['next'] )

    return manager

