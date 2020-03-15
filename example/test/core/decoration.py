import IceRayCpp

def coordinat_system( P_geometryCargo, P_surfaceRoom, P_distance = 2, P_height = 0.2, P_thickness = 0.1 ):

    P_geometryCargo['decoration'] = {}

    I_cooSysRadius = 0.1/4

    if( True  ): # smetalo plus X - sphere
        objectBallX_cargo = {}
        objectBallX_cargo['this'] = IceRayCpp.CoreObject()
        objectBallX_cargo['geometry'] = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load( 1, 0, 0 ), I_cooSysRadius )
        objectBallX_cargo['this'].geometry( objectBallX_cargo['geometry'] );
        objectBallX_cargo['this'].surface( P_surfaceRoom['lambert-red']['this'] );
        objectBallX_cargo['surface'] = P_surfaceRoom['lambert-red']
        P_geometryCargo['this'].push( objectBallX_cargo['this'] )
        P_geometryCargo['decoration']['BallX'] = objectBallX_cargo

    if( True  ): # smetalo plus Y - sphere
        objectBallY_cargo = {}
        objectBallY_cargo['this'] = IceRayCpp.CoreObject()
        objectBallY_cargo['geometry'] = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load( 0, 1, 0 ), I_cooSysRadius )
        objectBallY_cargo['this'].geometry( objectBallY_cargo['geometry'] );
        objectBallY_cargo['this'].surface( P_surfaceRoom['lambert-green']['this'] );
        objectBallY_cargo['surface'] = P_surfaceRoom['lambert-green']
        P_geometryCargo['this'].push( objectBallY_cargo['this'] )
        P_geometryCargo['decoration']['BallY'] = objectBallY_cargo

    if( True  ): # smetalo plus Z - sphere
        objectBallZ_cargo = {}
        objectBallZ_cargo['this'] = IceRayCpp.CoreObject()
        objectBallZ_cargo['geometry'] = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load( 0, 0, 1 ), I_cooSysRadius )
        objectBallZ_cargo['this'].geometry( objectBallZ_cargo['geometry'] );
        objectBallZ_cargo['this'].surface( P_surfaceRoom['lambert-blue']['this'] );
        objectBallZ_cargo['surface'] = P_surfaceRoom['lambert-blue']
        P_geometryCargo['this'].push( objectBallZ_cargo['this'] )
        P_geometryCargo['decoration']['BallZ'] = objectBallZ_cargo


    return

def coordinat_systemX( P_geometryCargo, P_surfaceRoom, P_distance = 2, P_height = 0.2, P_thickness = 0.1 ):

    if( True  ): # smetalo plus X
        objectPlusX_cargo = {}
        objectPlusX_cargo['this'] = IceRayCpp.CoreObject()
        objectPlusX_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( P_distance, -P_height,-P_height), IceRayCpp.MathTypeCoord3D().load(P_distance + P_thickness,P_height,P_height) )
        objectPlusX_cargo['this'].geometry( objectPlusX_cargo['geometry'] );
        objectPlusX_cargo['this'].surface( P_surfaceRoom['right']['this'] );
        objectPlusX_cargo['surface'] = P_surfaceRoom['right']
        P_geometryCargo['this'].push( objectPlusX_cargo['this'] )
        P_geometryCargo['decoration']['plusX'] = objectPlusX_cargo

    if( True   ): # smetalo minus X
        objectMinusX_cargo = {}
        objectMinusX_cargo['this'] = IceRayCpp.CoreObject()
        objectMinusX_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( -(P_distance + P_thickness),-P_height,-P_height), IceRayCpp.MathTypeCoord3D().load(-P_distance,P_height,P_height) )
        objectMinusX_cargo['this'].geometry( objectMinusX_cargo['geometry'] );
        objectMinusX_cargo['this'].surface( P_surfaceRoom['left']['this'] );
        objectMinusX_cargo['surface'] = P_surfaceRoom['left']
        P_geometryCargo['this'].push( objectMinusX_cargo['this'] )
        P_geometryCargo['decoration']['MinusX'] = objectMinusX_cargo

    if( True  ): # smetalo plus Y
        objectPlusY_cargo = {}
        objectPlusY_cargo['this'] = IceRayCpp.CoreObject()
        objectPlusY_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( -P_height,P_distance,-P_height), IceRayCpp.MathTypeCoord3D().load(P_height,P_distance + P_thickness,P_height) )
        objectPlusY_cargo['this'].geometry( objectPlusY_cargo['geometry'] );
        objectPlusY_cargo['this'].surface( P_surfaceRoom['foreground']['this'] );
        objectPlusY_cargo['surface'] = P_surfaceRoom['foreground']
        P_geometryCargo['this'].push( objectPlusY_cargo['this'] )
        P_geometryCargo['decoration']['plusY'] = objectPlusY_cargo

    if( True   ): # smetalo minus Y
        objectMinusY_cargo = {}
        objectMinusY_cargo['this'] = IceRayCpp.CoreObject()
        objectMinusY_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( -P_height,-(P_distance + P_thickness),-P_height), IceRayCpp.MathTypeCoord3D().load(P_height,-P_distance,P_height) )
        objectMinusY_cargo['this'].geometry( objectMinusY_cargo['geometry'] );
        objectMinusY_cargo['this'].surface( P_surfaceRoom['background']['this'] );
        objectMinusY_cargo['surface'] = P_surfaceRoom['background']
        P_geometryCargo['this'].push( objectMinusY_cargo['this'] )
        P_geometryCargo['decoration']['MinusY'] = objectMinusY_cargo

    if( True  ): # smetalo plus Z
        objectPlusZ_cargo = {}
        objectPlusZ_cargo['this'] = IceRayCpp.CoreObject()
        objectPlusZ_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( -P_height,-P_height,P_distance), IceRayCpp.MathTypeCoord3D().load(P_height,P_height,P_distance + P_thickness) )
        objectPlusZ_cargo['this'].geometry( objectPlusZ_cargo['geometry'] );
        objectPlusZ_cargo['this'].surface( P_surfaceRoom['ceil']['this'] );
        objectPlusZ_cargo['surface'] = P_surfaceRoom['ceil']
        P_geometryCargo['this'].push( objectPlusZ_cargo['this'] )
        P_geometryCargo['decoration']['plusZ'] = objectPlusZ_cargo

    if( True   ): # smetalo minus Z
        objectMinusZ_cargo = {}
        objectMinusZ_cargo['this'] = IceRayCpp.CoreObject()
        objectMinusZ_cargo['geometry'] = IceRayCpp.GeometrySimpleBox( IceRayCpp.MathTypeCoord3D().load( -P_height,-P_height,-(P_distance + P_thickness )), IceRayCpp.MathTypeCoord3D().load(P_height,P_height,-P_distance) )
        objectMinusZ_cargo['this'].geometry( objectMinusZ_cargo['geometry'] );
        objectMinusZ_cargo['this'].surface( P_surfaceRoom['floor']['this'] );
        objectMinusZ_cargo['surface'] = P_surfaceRoom['floor']
        P_geometryCargo['this'].push( objectMinusZ_cargo['this'] )
        P_geometryCargo['decoration']['MinusZ'] = objectMinusZ_cargo

    return


