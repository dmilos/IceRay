import IceRayCpp
import render
import render.engine



def make( P_object_cargo, P_camera_cargo ):

    engine_cargo={}
    engine_cargo['this'] = render.engine.Engine()

    engine_cargo['camera'] = P_camera_cargo
    engine_cargo['this'].camera( engine_cargo['camera']['this'] )

    engine_cargo['object'] = P_object_cargo
    engine_cargo['this'].object( engine_cargo['object']['this'] )

    #engine_cargo['scanner'] = IceRayCpp.RenderScannerBlock();
    #engine_cargo['this'].scanner( engine_cargo['scanner'] )

    return engine_cargo
