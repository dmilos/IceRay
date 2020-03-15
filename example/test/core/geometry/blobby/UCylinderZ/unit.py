import math
import IceRayCpp

def name( ):
    return "blobby"


def solo( P_core = 0.6 ):
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbyUCylinderZ( IceRayCpp.MathTypeCoord3D().load(0,0,0), P_core, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].rtss( cargo['rtss'] )
    return cargo
