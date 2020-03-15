import IceRayCpp

def name( ):
    return "affine"

def identical(  ):
    child = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.5 )
    #child = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load(-0.25,-0.25,-0.25), IceRayCpp.MathTypeCoord3D().load(0.25,0.25,0.25 ) )

    affine = IceRayCpp.GeometryTransformAffine( child )

    return { 'this': affine, '1': child }

def uniform( scale = 0.61803398874989484820458683436564 ):
    child = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.5 )
    #child = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load(-0.25,-0.25,-0.25), IceRayCpp.MathTypeCoord3D().load(0.25,0.25,0.25 ) )

    affine = IceRayCpp.GeometryTransformAffine( child )

    affine.scale( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().fill(scale) )

    return { 'this': affine, '1': child }

def translate( move = IceRayCpp.MathTypeCoord3D().load( 0.61803398874989484820458683436564, 0.38196601125010515179541316563436, 0.23606797749978969640917366873128 )  ):
    child = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.5 )
    #child = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load(-0.25,-0.25,-0.25), IceRayCpp.MathTypeCoord3D().load(0.25,0.25,0.25 ) )

    affine = IceRayCpp.GeometryTransformAffine( child )

    affine.translate( move )

    return { 'this': affine, '1': child }


def make( scale = IceRayCpp.MathTypeCoord3D().load( 1, 2, 0.1 ) ): # 1, 1, 0.2
    child = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.5 )
    #child = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load(-0.25,-0.25,-0.25), IceRayCpp.MathTypeCoord3D().load(0.25,0.25,0.25 ) )

    affine = IceRayCpp.GeometryTransformAffine( child )

    affine.scale( IceRayCpp.MathTypeCoord3D().fill(0), scale )
    #affine.rotate( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(1,0,0), -0.7 )
    #affine.rotate( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(0,0,1), -0.7 )

    return { 'this': affine, '1': child }
