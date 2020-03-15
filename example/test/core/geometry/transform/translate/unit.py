import IceRayCpp

def name( ):
    return "translate"

def identical():

    #child = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.5 )
    child = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().fill(-0.5), IceRayCpp.MathTypeCoord3D().fill( 0.5 ) )

    translate = IceRayCpp.GeometryTransformTranslate( child, IceRayCpp.MathTypeCoord3D().load(0,0,0) )

    return { 'this': translate, '1': child }

def make( move = IceRayCpp.MathTypeCoord3D().load( 0.61803398874989484820458683436564, 0.38196601125010515179541316563436, 0.23606797749978969640917366873128 )  ):

    #child = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.5 )
    child = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().fill(-0.5), IceRayCpp.MathTypeCoord3D().fill( 0.5 ) )

    translate = IceRayCpp.GeometryTransformTranslate( child, move )

    return { 'this': translate, '1': child }
