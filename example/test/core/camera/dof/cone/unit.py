import IceRayCpp

def name( ):
    return "camera_dof_cone"

def make( P_child = IceRayCpp.CameraFlatPerspective() ):
    camera = IceRayCpp.CameraCone()
    camera.child( P_child )
    camera.aperture( 0.03 )
    camera.gauss( 0.1 )
    camera.sample( 3 )
    return { 'this': camera, 'child' : P_child }
