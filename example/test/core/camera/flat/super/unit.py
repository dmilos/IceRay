import IceRayCpp

def name( ):
    return "camera_flat_super"

def perspective( ):
    eye  = IceRayCpp.MathTypeCoord2D().load(0,0)
    view = IceRayCpp.MathTypeCoord2D().load(2,2)
    camera = IceRayCpp.CameraFlatSuper( eye, view )
    return { 'this': camera }

def orthogonal( ):
    eye  = IceRayCpp.MathTypeCoord2D().load( 2,2 )
    view = IceRayCpp.MathTypeCoord2D().load( 2,2 )
    camera = IceRayCpp.CameraFlatSuper( eye, view )
    return { 'this': camera }

def X( ): #TODO
    eye  = IceRayCpp.MathTypeCoord2D().load(2,0)
    view = IceRayCpp.MathTypeCoord2D().load(2,2)
    camera = IceRayCpp.CameraFlatSuper( eye, view )
    return { 'this': camera }

def Y( ):#TODO
    eye  = IceRayCpp.MathTypeCoord2D().load(0,2)
    view = IceRayCpp.MathTypeCoord2D().load(2,2)
    camera = IceRayCpp.CameraFlatSuper( eye, view )
    return { 'this': camera }
