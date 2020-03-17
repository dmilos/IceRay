import IceRayCpp

def name( ):
    return "identity"


def make(   ):

    #child = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.5 )
    child = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().fill(-0.5), IceRayCpp.MathTypeCoord3D().fill( 0.5 ) )

    identity = IceRayCpp.GeometryTransformIdentity( child )

    return { 'this': identity, '1': child }
