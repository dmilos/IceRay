#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import IceRayPy.library.geometry.lens
import IceRayPy.library.geometry.example
import IceRayPy.library.geometry.hfield
import IceRayPy.library.geometry.blobby


import math
Coord3D = IceRayPy.type.math.coord.Scalar3D
RGB = IceRayPy.type.color.RGB


def OneM( P_dll ):

    X = 40
    Y = 40
    Z = 40
    rtss = IceRayPy.core.geometry.rtss.Object( P_dll )

    rtss.rtss( IceRayPy.core.geometry.rtss.Uniform( P_dll, IceRayPy.type.math.coord.Size3D(X,Y,Z) ) )
    #rtss.rtss( IceRayPy.core.geometry.rtss.List( P_dll ) )

    radius = 1
    r = radius * ( 2/X )/2

    for i in range( 0, X ):
        for j in range( 0, Y ):
            for k in range( 0, Z ):
                x = i* 2/X + 1/X - 1
                y = j* 2/Y + 1/Y - 1
                z = k* 2/Z + 1/Z - 1

                rtss.push( IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( x , y, z ), r ) )

    rtss.optimize()

    return rtss

def MotionBlur( P_dll ):
    radius = 0.5
    center = Coord3D( -1+radius, 0, 0 )
    direction = Coord3D( -center[0]-center[0], -center[1]-center[1], -center[2]-center[2] )

    result = IceRayPy.core.geometry.transform.MotionBlur( P_dll )
    child = IceRayPy.core.geometry.simple.Sphere( P_dll, center, radius )

    result.direction( direction )
    result.child( child )

    return result

def Grid( P_dll, P_config = { 'shadow': False, 'pigment': None }, P_light = None, P_exponat = None ):

    radius = 0.01
    rtss = IceRayPy.core.geometry.rtss.Object( P_dll, IceRayPy.core.geometry.rtss.List( P_dll ) )

    epsilon = 0.1
    I_lo = Coord3D( -1 + epsilon,-1 + epsilon,-1 + epsilon )
    I_hi = Coord3D( +1 - epsilon,+1 - epsilon,+1 - epsilon )
    
    I_size=[2,2]

    for u in range(0,I_size[0]) :
        x = I_lo[0] + ( I_hi[0]- I_lo[0]) * u/(I_size[0]-1)
        for v in range(0,I_size[1]) :
            y = I_lo[1] + ( I_hi[1]- I_lo[1]) * v/(I_size[1]-1)

            bottom = Coord3D( x, y, I_lo[2] )
            top    = Coord3D( x, y, I_hi[2] )
            blue = IceRayPy.core.object.Wrapper( P_dll )
            blue.pigment( IceRayPy.utility.material.pattern.Gradient( P_dll, {}, bottom, top, { 0: RGB(0,0,0), 1: RGB(0,0,1)} ) )
            blue.geometrySet( IceRayPy.utility.geometry.simple.CylinderG( P_dll,  { 'top' : top, 'bottom' :  bottom, 'radius' : radius } ) )
            rtss.push( IceRayPy.core.geometry.Pretender( P_dll, blue.cast2Geometry(),  blue ) )

            bottom = Coord3D( x, I_lo[1], y )
            top    = Coord3D( x, I_hi[1], y )
            green = IceRayPy.core.object.Wrapper( P_dll )
            green.pigment( IceRayPy.utility.material.pattern.Gradient( P_dll, {}, bottom, top, { 0: RGB(0,0,0), 1: RGB(0,1,0)} ) )
            green.geometrySet( IceRayPy.utility.geometry.simple.CylinderG( P_dll,   { 'top' : top, 'bottom' : bottom , 'radius' : radius } ) )
            rtss.push( IceRayPy.core.geometry.Pretender( P_dll, green.cast2Geometry(),  green ) )

            bottom =  Coord3D( I_lo[0], x, y )
            top    =  Coord3D( I_hi[0], x, y )
            red = IceRayPy.core.object.Wrapper( P_dll )
            red.pigment( IceRayPy.utility.material.pattern.Gradient( P_dll, {}, bottom, top, { 0: RGB(0,0,0), 1: RGB(1,0,0)} ) )
            red.geometrySet( IceRayPy.utility.geometry.simple.CylinderG( P_dll, { 'top' : top, 'bottom' : bottom , 'radius' : radius } ) )
            rtss.push( IceRayPy.core.geometry.Pretender( P_dll, red.cast2Geometry(),  red ) )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( rtss )

    return wrapper



#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
