import IceRayCpp

def name( ):
    return "motion_blur"
    
def make():

    #sphere = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(-0.5,0,0), 0.5 )
    box = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load(-1,-1,-0.25), IceRayCpp.MathTypeCoord3D().load(-0.5,-0.5,0.25 ) )

    mblur = IceRayCpp.GeometryTransformMBlur(  box, IceRayCpp.MathTypeCoord3D().load(0,0,0) )

    return { 'this': mblur, '1': box }

def make():

    #sphere = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(-0.5,0,0), 0.5 )
    box = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load(-1,-1,-0.25), IceRayCpp.MathTypeCoord3D().load(-0.5,-0.5,0.25 ) )

    mblur = IceRayCpp.GeometryTransformMBlur(  box, IceRayCpp.MathTypeCoord3D().load(1,1,0) )

    return { 'this': mblur, '1': box }
