import IceRayCpp

def name( ):
    return "homography"

def identical( scale = IceRayCpp.MathTypeCoord3D().load( 1, 2, 0.5 ) ): # 1, 1, 0.2

    child = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.5 )
    #child = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load(-0.25,-0.25,-0.25), IceRayCpp.MathTypeCoord3D().load(0.25,0.25,0.25 ) )

    homography = IceRayCpp.GeometryTransformPomography( child )

    return { 'this': homography, '1': child }

def uniform( scale = 0.61803398874989484820458683436564 ):
    child = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.75 )
    #child = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load(-0.25,-0.25,-0.25), IceRayCpp.MathTypeCoord3D().load(0.25,0.25,0.25 ) )

    homography = IceRayCpp.GeometryTransformHomography( child )

    #homography.scale( IceRayCpp.MathTypeCoord3D().fill(0), scale )
    #homography.rotate( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(1,0,0), -0.7 )
    #homography.rotate( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(0,0,1), -0.7 )
    #homography.rotate( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(0,0,1), -0.7 )

    return { 'this': homography, '1': child }

def translate( move = IceRayCpp.MathTypeCoord3D().load( 0.61803398874989484820458683436564, 0.38196601125010515179541316563436, 0.23606797749978969640917366873128 )  ):
    child = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.75 )
    #child = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load(-0.25,-0.25,-0.25), IceRayCpp.MathTypeCoord3D().load(0.25,0.25,0.25 ) )

    homography = IceRayCpp.GeometryTransformHomography( child )

    #homography.scale( IceRayCpp.MathTypeCoord3D().fill(0), scale )
    #homography.rotate( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(1,0,0), -0.7 )
    #homography.rotate( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(0,0,1), -0.7 )
    #homography.rotate( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(0,0,1), -0.7 )

    return { 'this': homography, '1': child }

def make(  ):

    child = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.75 )
    #child = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load(-0.25,-0.25,-0.25), IceRayCpp.MathTypeCoord3D().load(0.25,0.25,0.25 ) )

    homography = IceRayCpp.GeometryTransformHomography( child )

    #homography.scale( IceRayCpp.MathTypeCoord3D().fill(0), scale )
    #homography.rotate( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(1,0,0), -0.7 )
    #homography.rotate( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(0,0,1), -0.7 )
    #homography.rotate( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(0,0,1), -0.7 )

    return { 'this': homography, '1': child }
