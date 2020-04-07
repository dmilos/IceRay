import math
import IceRayCpp

def make( P_camera,
          # default P_eye = IceRayCpp.MathTypeCoord3D().load( 2, 5, 3 )*0.6,
          P_eye = IceRayCpp.MathTypeCoord3D().load( 2, 5, 3 ) * 0.6 * 0.7,
          P_view = IceRayCpp.MathTypeCoord3D().fill( 0 ),
          ): # The default
    transform = IceRayCpp.CameraTransformAffine()

    transform.child(P_camera['this'])
    eye  = IceRayCpp.MathTypeCoord3D();  eye = P_eye
    view = IceRayCpp.MathTypeCoord3D(); view = P_view
    up   = IceRayCpp.MathTypeCoord3D();   up.load( 0, 0, 1 )

    affine = IceRayCpp.MathAffine3D_lookAt( eye, view, up )
    transform.world( affine )

    return { 'this' : transform, '0': P_camera }
