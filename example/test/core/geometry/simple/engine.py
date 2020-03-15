import IceRayPy

import camera

def make( P_object_cargo  ):
    engine = IceRayPy.core.render.Engine()

    cargo_camera = camera.make()
    engine.camera( cargo_camera['this'] )

    cargo_object = P_object_cargo

    engine.object( cargo_object['this'] )

    return { 'this': engine, '0': cargo_camera, '1': cargo_object  }
