import IceRayCpp

def name( ):
    return "blobby"

def make():

    return make_affine_affine_sphere()

def make_USphere_solo():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbyUSphere( 0.5 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].rtss( cargo['rtss'] )
    return cargo

def make_UCylinderZ_solo():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbyUCylinderZ( 0.5 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].rtss( cargo['rtss'] )
    return cargo

def make_UWaterZ_solo():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbyUWaterZ( 0.5 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].rtss( cargo['rtss'] )
    return cargo

def  make_affine_solo():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['c1'] = IceRayCpp.GeometryBlobbyUSphere( 0.5 )

    cargo['1'] = IceRayCpp.GeometryBlobbyAffine( cargo['c1'] )
    cargo['1'].scale( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(1,1,0.3) )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo


def make_sphere_Usphere():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbyUSphere( 0.5 )
    cargo['2'] = IceRayCpp.GeometryBlobbySphere( IceRayCpp.MathTypeCoord3D().load(0.5,-0.5,0.5), 0.5, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].add( cargo['2'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo

def make_sphere_UCylinderZ():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbyUCylinderZ( 0.5 )
    cargo['2'] = IceRayCpp.GeometryBlobbySphere( IceRayCpp.MathTypeCoord3D().load(1,0.5,0.5), 0.5, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].add( cargo['2'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo

def make_sphere_UWaterZ():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['1'] = IceRayCpp.GeometryBlobbyUWaterZ( 0.5 )
    cargo['2'] = IceRayCpp.GeometryBlobbySphere( IceRayCpp.MathTypeCoord3D().load(1,0,1), 0.5, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].add( cargo['2'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo

def make_sphere_translate_sphere():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['c1'] = IceRayCpp.GeometryBlobbySphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.4, 1 )

    cargo['1'] = IceRayCpp.GeometryBlobbyTranslate( cargo['c1'], IceRayCpp.MathTypeCoord3D().load(-0.6,0,-0.1) )
    cargo['2'] = IceRayCpp.GeometryBlobbySphere(                 IceRayCpp.MathTypeCoord3D().load(+0.6,0,+0.1), 0.4, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].add( cargo['2'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo

def  make_sphere_translate_USphere():
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

def  make_sphere_translate_UCylinderZ():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['c1'] = IceRayCpp.GeometryBlobbyUCylinderZ( 0.5 )

    cargo['1'] = IceRayCpp.GeometryBlobbyTranslate( cargo['c1'], IceRayCpp.MathTypeCoord3D().load(-0.6,0,-0.1) )
    cargo['2'] = IceRayCpp.GeometryBlobbySphere(                 IceRayCpp.MathTypeCoord3D().load(+0.6,0,+0.1), 0.4, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].add( cargo['2'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo

def  make_sphere_translate_UWaterZ():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['c1'] = IceRayCpp.GeometryBlobbyUWaterZ( 0.5 )

    cargo['1'] = IceRayCpp.GeometryBlobbyTranslate( cargo['c1'], IceRayCpp.MathTypeCoord3D().load(-0.6,0,-0.1) )
    cargo['2'] = IceRayCpp.GeometryBlobbySphere(                 IceRayCpp.MathTypeCoord3D().load(+0.6,0,+0.1), 0.4, 1 )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].add( cargo['2'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo


def  make_affine_affine_sphere():
    cargo={}
    cargo['this']=IceRayCpp.GeometryBlobbySystem()

    cargo['c1'] = IceRayCpp.GeometryBlobbyUSphere( 0.5 )

    cargo['1'] = IceRayCpp.GeometryBlobbyAffine( cargo['c1'] )
    cargo['1'].scale( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(1,1,0.3)  )
    cargo['1'].rotate( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(1,0,0), 3.14159/2.0  )
    cargo['1'].translate( IceRayCpp.MathTypeCoord3D().load(0.4,0,0),   )

    cargo['c2'] = IceRayCpp.GeometryBlobbyUSphere( 0.5 )
    cargo['2'] = IceRayCpp.GeometryBlobbyAffine( cargo['c2'] )
    cargo['2'].scale( IceRayCpp.MathTypeCoord3D().fill(0), IceRayCpp.MathTypeCoord3D().load(1,1,0.3)  )
    cargo['2'].translate( IceRayCpp.MathTypeCoord3D().load(-0.4,0,0),   )

    cargo['rtss'] = IceRayCpp.GeometryRTSSList()

    cargo['this'].add( cargo['1'] )
    cargo['this'].add( cargo['2'] )
    cargo['this'].rtss( cargo['rtss'] )

    return cargo
