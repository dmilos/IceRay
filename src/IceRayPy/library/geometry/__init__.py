print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy

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


print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
