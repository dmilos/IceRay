import IceRayCpp

def make_HSPhong( light_cargo ):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( light_cargo['this'], 0 )
    #MaterialLightSpotSwarmA( [size]count, [light]light, [coord]point, [spot]start )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.9 ), 1 )
    cargo['4'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 1 )

    cargo['5'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.6, 0.7, 1 ), 1 )
    cargo['6'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 10.0, 10.0, 10.0 ), 2 )
    cargo['7'] = IceRayCpp.MaterialPatternCoord3DConstant( IceRayCpp.MathTypeCoord3D().load( 0, 0.0, 1.0 ), 2 )
    #MaterialIlluminationHSPhong( [Coord]point, [Coord]normal, [size]lightCount, [color]specular, [color]shiness, [coord]groovie, [color]result )
    cargo['8'] = IceRayCpp.MaterialIlluminationHSPhong( 0, 1, 0, 1, 2, 2, 0 )

    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )
    surface.append( cargo['7'] )
    surface.append( cargo['8'] )

    return { 'this' : surface, '0': cargo, '1': light_cargo  }

def make_HSLambert( light_cargo ):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( light_cargo['this'], 0 )
    #MaterialLightSpotSwarmA( [size]count, [light]light, [coord]point, [spot]start )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.9 ), 1 )
    cargo['4'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 1 )

    cargo['5'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.4, 0.5, 0.6 ), 1 )
    cargo['6'] = IceRayCpp.MaterialPatternCoord3DConstant( IceRayCpp.MathTypeCoord3D().load( 0, 0, 1 ), 2 )

    #MaterialIlluminationHSLambert( [Coord]point, [Coord]normal, [size]spotCount, [color]diffuse, [coord]groove, [color]result  )
    cargo['7'] = IceRayCpp.MaterialIlluminationHSLambert( 0, 1, 0, 1, 2, 0 )

    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )
    surface.append( cargo['7'] )

    return { 'this' : surface, 'list': cargo, 'light': light_cargo  }

def make_normal_gauss( light_cargo ):
    return
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( light_cargo['this'], 0 )
    #MaterialLightSpotSwarmA( [size]count, [light]light, [coord]point, [spot]start )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.9 ), 1 )
    cargo['4'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 1 )

    cargo['5'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.4, 0.5, 0.6 ), 1 )
    cargo['6'] = IceRayCpp.MaterialPatternCoord3DConstant( IceRayCpp.MathTypeCoord3D().load( 0, 0, 1), 2 )

    #MaterialIlluminationHSLambert( [Coord]point, [Coord]normal, [size]lightCount, [color]diffuse, [coord]groove, [color]result  )
    cargo['7'] = IceRayCpp.MaterialIlluminationHSLambert( 0, 1, 0, 1, 2, 0 )

    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )
    surface.append( cargo['7'] )

    return { 'this' : surface, 'list': a, 'light': light_cargo  }

