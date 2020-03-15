import IceRayCpp

def make( surface_cargo, geometry_pure ):

    object_cargo = {}
    object_cargo['this'] = IceRayCpp.CoreObject()

    object_cargo['geometry'] = geometry_pure
    object_cargo['this'].geometry( geometry_pure )

    object_cargo['surface'] = surface_cargo
    object_cargo['this'].surface( surface_cargo['this'] )

    return object_cargo


