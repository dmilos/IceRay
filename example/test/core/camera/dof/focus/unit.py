import IceRayCpp

def name( ):
    return "camera_dof_focus"

def make( P_child = IceRayCpp.CameraFlatPerspective() ):
    camera = IceRayCpp.CameraFocus()
    camera.child( P_child )

    camera.gauss( 1 )
    camera.sample( 20 )

    camera.aperture( IceRayCpp.MathTypeInterval1D( 0.2, 0 ) )
    camera.focus(    IceRayCpp.MathTypeInterval1D ( 6, 6 ) )

    return { 'this': camera, 'child' : P_child }
