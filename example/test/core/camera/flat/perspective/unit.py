import IceRayCpp

def name( ):
    return "camera_flat_perspective"

def make( P_width = 1, P_height = 1 ):
    camera = IceRayCpp.CameraFlatPerspective( P_width, P_height )
    return { 'this': camera }
