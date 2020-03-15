import IceRayCpp

def name( ):
    return "intersect"

#"nowhere"
#"in"
#"out"
#"symmetric"
#"surface"
#"closure"
#"complement"
#"everywhere"

def make( left = IceRayCpp.Geometry_Inside.inside, right = IceRayCpp.Geometry_Inside.outside  ): # P_center, P_radius

    sphere = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().fill(0), 1 )
    #sphere1 = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0.2,0), 0.5 )
    box    = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().fill(-0.8),
                                          IceRayCpp.MathTypeCoord3D().fill(0.8) )

    intersect = IceRayCpp.GeometryComplexIntersect()
    intersect.right( sphere, IceRayCpp.Geometry_Inside.where( left )  )
    intersect.left(  box,    IceRayCpp.Geometry_Inside.where( right ) )

    return { 'this': intersect, '0' : sphere, '1' : box }


def intersect(): # P_center, P_radius
    return make( IceRayCpp.Geometry_Inside.inside, IceRayCpp.Geometry_Inside.inside )