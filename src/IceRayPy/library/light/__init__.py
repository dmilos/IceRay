#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )


import IceRayPy
 

def Area( P_dll, P_config = {} ):
    result = IceRayPy.core.light.Area( P_dll )

    if( None != P_config ):
       if( 'spot' in P_config ) :
           result.spot( P_config['spot'] )
       if( 'sample' in P_config ) :
           result.sample( P_config['sample'] )
       if( 'origin' in P_config ) :
           result.origin( P_config['origin'] )

    return result

def Circle( P_dll, P_config = {} ):
    result = IceRayPy.core.light.Circle( P_dll )

    if( None != P_config ):
        if( 'spot' in P_config ) :
            result.spot( P_config['spot'] )
        if( 'sample' in P_config ) :
            result.sample( P_config['sample'] )
        if( 'center' in P_config ) :
            result.center( P_config['center'] )

    return result

def Dark( P_dll,  P_config = {}  ):
    result = IceRayPy.core.light.Dark( P_dll )

    return result


def Disc( P_dll,  P_config = {}  ):
    result = IceRayPy.core.light.Disc( P_dll )

    if( None != P_config ):
        if( 'spot' in P_config ) :
            result.spot( P_config['spot'] )
        if( 'sample' in P_config ) :
            result.sample( P_config['sample'] )
        if( 'center' in P_config ) :
            result.center( P_config['center'] )
    return result

def Line( P_dll,  P_config = {}  ):
    result = IceRayPy.core.light.Line( P_dll )

    if( None != P_config ):
        if( 'spot' in P_config ) :
            result.spot( P_config['spot'] )
        if( 'sample' in P_config ) :
            result.sample( P_config['sample'] )
        if( 'start' in P_config ) :
            result.start( P_config['start'] )
        if( 'end' in P_config ) :
            result.end( P_config['end'] )

    return result

def Point( P_dll,  P_config = {}  ):
    result = IceRayPy.core.light.Point( P_dll )

    if( None != P_config ):
       if( 'spot' in P_config ):
           result.sample( P_config['spot'] )
       if( 'center' in P_config ) :
           result.center( P_config['center'] )
    return result

def Reflector( P_dll,  P_config = {}  ):
    result = IceRayPy.core.light.Reflector( P_dll )

    if( None != P_config ):
       if( 'spot' in P_config ) :
           result.sample( P_config['spot'] )
       if( 'center' in P_config ) :
           result.center( P_config['center'] )
    return result

def Sphere( P_dll,  P_config = {}  ):
    result = IceRayPy.core.light.Sphere( P_dll )

    if( None != P_config ):
        if( 'spot' in P_config ) :
            result.spot( P_config['spot'] )
        if( 'center' in P_config ) :
            result.center( P_config['center'] )
        if( 'sample' in P_config ) :
            result.sample( P_config['sample'] )
    return result

def Spline( P_dll,  P_config = {}  ):
    result = IceRayPy.core.light.Spline( P_dll )

    if( None != P_config ):
       if( 'spot' in P_config ) :
           result.spot( P_config['spot'] )
       if( 'sample' in P_config ) :
           result.sample( P_config['sample'] )
    return result



#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
