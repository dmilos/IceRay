print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy

Coord3D = IceRayPy.type.math.coord.Scalar3D

def Symetric( P_dll,
        P_center = Coord3D( 0, 0,0 ), #!< TODO
        P_normal = Coord3D( 0, 1,0 ), #!< TODO
        P_radius = 2,
        P_thick = 0.3
        ):

    radius = ( (P_radius/2)*(P_radius/2) + (P_thick/2)*(P_thick/2) ) / P_thick
    center = radius - P_thick / 2
    #print(__file__ + " center: " + str(center), flush = True );
    #print(__file__ + " radius: " + str(radius), flush = True );

    left  = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( -center , 0, 0 ), radius )
    right = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( +center , 0, 0 ), radius )
    result = IceRayPy.core.geometry.complex.Intersect( P_dll )

    result.left( left )
    result.right( right )

    return result

def Plano( P_dll,
        P_center = Coord3D( 0, 0,0 ), #!< TODO
        P_normal = Coord3D( 0, 1,0 ), #!< TODO
        P_radius = 2,
        P_thick = 0.3/2
        ):

    radius = ( (P_radius/2)*(P_radius/2) + (P_thick)*(P_thick) ) / (2*P_thick)
    center = radius - P_thick
    #print(__file__ + " center: " + str(center), flush = True );
    #print(__file__ + " radius: " + str(radius), flush = True );

    left  = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( -center , 0, 0 ), radius )
    right = IceRayPy.core.geometry.simple.Plane( P_dll, IceRayPy.type.math.coord.Scalar3D( 0 , 0, 0 ), IceRayPy.type.math.coord.Scalar3D( -1, 0, 0 ) )
    intersect = IceRayPy.core.geometry.complex.Intersect( P_dll )

    intersect.left( left )
    intersect.right( right )
    intersect.box()

    affine = IceRayPy.core.geometry.transform.Affine( P_dll )
    affine.child( intersect )

    return affine

print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
