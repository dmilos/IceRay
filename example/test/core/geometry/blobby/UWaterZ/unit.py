import IceRayCpp

def name( ):
    return "blobby"

def make():

    return make_affine_affine_sphere()


def solo():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbyUWaterZ( 0.5 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].rtss( cargo['rtss'] )
    return cargo

