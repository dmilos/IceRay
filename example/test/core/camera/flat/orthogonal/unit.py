import IceRayCpp

def name( ):
    return "camera_flat_orthogonal"

def make( P_width=2, P_height=2 ):
    camera = IceRayCpp.CameraFlatOrthogonal(P_width,P_height)
    #camera.width(P_width)
    #camera.height(P_height)
    return { 'this': camera }
