import math
import IceRayCpp

def  USphere():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['c1'] = IceRayCpp.GeometryBlobbyUSphere( 0.5 )

    cargo['1'] = IceRayCpp.GeometryBlobbyAffine( cargo['c1'] )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo

def sphere( P_core = 0.5):
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['c1'] = IceRayCpp.GeometryBlobbySphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), P_core, 1 )


    cargo['1'] = IceRayCpp.GeometryBlobbyAffine( cargo['c1'] )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo

def  UWaterZ():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['c1'] = IceRayCpp.GeometryBlobbyUWaterZ( 0.5 )

    cargo['1'] = IceRayCpp.GeometryBlobbyAffine( cargo['c1'] )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo

def  UCylinderZ():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['c1'] = IceRayCpp.GeometryBlobbyUCylinderZ( 0.5 )

    cargo['1'] = IceRayCpp.GeometryBlobbyAffine( cargo['c1'] )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo
