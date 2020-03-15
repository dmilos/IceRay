import IceRayCpp

def name( ):
    return "blobby"

def make():

    return make_affine_affine_sphere()


def solo(): #DONE
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbyUSphere( 0.5 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].rtss( cargo['rtss'] )
    return cargo

def  solo_affine(): #TODO
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['c1'] = IceRayCpp.GeometryBlobbyUSphere( 0.5 )

    cargo['1'] = IceRayCpp.GeometryBlobbyAffine( cargo['c1'] )
    cargo['1'].scale( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(1,1,0.3) )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo

def  solo_translate():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['c1'] = IceRayCpp.GeometryBlobbyUSphere( 0.5 )

    cargo['1'] = IceRayCpp.GeometryBlobbyTranslate( cargo['c1'], IceRayCpp.MathTypeCoord3D().load(-0.6,0,-0.1) )
    cargo['2'] = IceRayCpp.GeometryBlobbySphere(                 IceRayCpp.MathTypeCoord3D().load(+0.6,0,+0.1), 0.4, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].add( cargo['2'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo

