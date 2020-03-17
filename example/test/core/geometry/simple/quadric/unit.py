import IceRayCpp

def name( ):
    return "quadric"

def planeZ( ):
    geometry = IceRayCpp.GeometrySimpleQuadric()

    matrix = IceRayCpp.MathTypeMatrix3D()
    matrix.zero()
    coord = IceRayCpp.MathTypeCoord3D().load( 0, 0, 1 )
    scalar = 0

    geometry.matrix( matrix );
    geometry.coord( coord );
    geometry.scalar( scalar );

    return{ 'this' : geometry }

def sphere( ):
    geometry = IceRayCpp.GeometrySimpleQuadric()

    matrix = IceRayCpp.MathTypeMatrix3D()
    matrix.identity()
    coord = IceRayCpp.MathTypeCoord3D().load( 0, 0, 0 )
    scalar = -1

    geometry.matrix( matrix );
    geometry.coord( coord );
    geometry.scalar( scalar );

    return{ 'this' : geometry }

def paraboloid( ):
    geometry = IceRayCpp.GeometrySimpleQuadric()

    matrix = IceRayCpp.MathTypeMatrix3D()
    matrix.identity()
    matrix.element( 2, 2, 0 )

    coord = IceRayCpp.MathTypeCoord3D().load( 0, 0, -1 )
    scalar = 0

    geometry.matrix( matrix );
    geometry.coord( coord );
    geometry.scalar( scalar );

    return{ 'this' : geometry }

def hyperboloid( ): # TODO
    geometry = IceRayCpp.GeometrySimpleQuadric()

    matrix = IceRayCpp.MathTypeMatrix3D()
    matrix.identity()
    matrix.element(0,0,0)
    matrix.element(1,1,0)
    matrix.element(2,2,0)

    matrix.element( 0, 1, 0.5 )
    matrix.element( 1, 0, 0.5 )

    coord = IceRayCpp.MathTypeCoord3D().load( 0, 0, -1 )
    scalar = 0

    geometry.matrix( matrix );
    geometry.coord( coord );
    geometry.scalar( scalar );

    return{ 'this' : geometry }

def cone( ):
    geometry = IceRayCpp.GeometrySimpleQuadric()

    matrix = IceRayCpp.MathTypeMatrix3D()
    matrix.identity()
    matrix.element( 2, 2, -1 )

    coord = IceRayCpp.MathTypeCoord3D().load( 0, 0, 0 )
    scalar = 0

    geometry.matrix( matrix );
    #geometry.coord( coord );
    geometry.scalar( scalar );

    return{ 'this' : geometry }

def cylinder( ):
    geometry = IceRayCpp.GeometrySimpleQuadric()

    matrix = IceRayCpp.MathTypeMatrix3D()
    matrix.identity()
    matrix.element( 2, 2, 0 )
    #coord = IceRayCpp.MathTypeCoord3D().load( 0, 0, 0 )
    scalar = -1

    geometry.matrix( matrix );
    #geometry.coord( coord );
    geometry.scalar( scalar );

    return{ 'this' : geometry }

