import IceRayCpp

def make(
   P_light
  ,P_emission  = IceRayCpp.GraphTypeColorRGB().fill( 0.1 )
  ,P_diffuse   = IceRayCpp.GraphTypeColorRGB().fill( 0.6 )
  ,P_albedo    = IceRayCpp.GraphTypeColorRGB().fill( 0.7 )
  ,P_specular  = IceRayCpp.GraphTypeColorRGB().load( 1.0, 1.1, 1.2 )
  ,P_shininess = IceRayCpp.GraphTypeColorRGB().load( 8, 16, 32 )
 ):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialPatternColorConstant( P_emission,  1 )
    cargo['2'] = IceRayCpp.MaterialPatternColorConstant( P_diffuse,   2 )
    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( P_specular,  3 )
    cargo['4'] = IceRayCpp.MaterialPatternColorConstant( P_shininess, 4 )

    cargo['5'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarm( [coord]point, [light]light, [spot]start, [size]count  )
    cargo['6'] = IceRayCpp.MaterialLightSpotSwarm( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['7'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['8'] = IceRayCpp.MaterialPatternColorConstant( P_albedo, 5 )
    #MaterialTransmissionReflectOne( [coord]point, [coord]normal, [color]transmittance )
    cargo['9'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 5 )

    #MaterialIlluminationALP( [color]result, [coord]point ,[coord]normal, [color]emission,[color]diffuse,[color]specular,[color]shininess, [size]spotCount,[spot]begin )
    cargo['a'] = IceRayCpp.MaterialIlluminationALP( 0, 0,1, 1,2,3,4, 0,0 )

    surface.append( cargo['1'] )
    surface.append( cargo['2'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )
    surface.append( cargo['7'] )
    surface.append( cargo['8'] )
    surface.append( cargo['9'] )
    surface.append( cargo['a'] )

    return { 'this' : surface, 'light': P_light, 'cargo': cargo  }

def makeOF(
   P_light
  ,P_emission   = IceRayCpp.GraphTypeColorRGB().fill( 0.5 )
  ,P_diffuse    = IceRayCpp.GraphTypeColorRGB().fill( 0.5 )
  ,P_albedo     = IceRayCpp.GraphTypeColorRGB().fill( 0.5 )
  ,P_specular   = IceRayCpp.GraphTypeColorRGB().load( 1.0, 1.0, 1.0 )
  ,P_shininess  = IceRayCpp.GraphTypeColorRGB().load( 8, 16, 32 )
 ):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialPatternColorConstant( P_emission, 0 )
    #MaterialIlluminationAmbient( [color]result, [color]emission )
    cargo['2'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 ) # first result

    cargo['3'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarm( [coord]point, [light]light, [spot]start, [size]count  )
    cargo['3A'] = IceRayCpp.MaterialLightSpotSwarm( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['3B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['5'] = IceRayCpp.MaterialPatternColorConstant( P_diffuse, 10 )
    #MaterialIlluminationLambert( [color]result, [coord]point, [coord]normal, [size]spotCount, [color]diffuse )
    cargo['6'] = IceRayCpp.MaterialIlluminationLambert( 2, 0, 1, 0, 10 ) # second result


    cargo['7'] = IceRayCpp.MaterialPatternColorConstant( P_albedo, 10 )
    #MaterialTransmissionReflectOne( [coord]point, [coord]normal, [color]transmittance )
    cargo['8'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 10 )

    cargo['9'] = IceRayCpp.MaterialPatternColorConstant( P_specular, 10 )
    cargo['a'] = IceRayCpp.MaterialPatternColorConstant( P_shininess, 11 )
    #MaterialIlluminationPhong( [color]result, [color]specular, [color]shininess, [size]spotCount )
    cargo['b'] = IceRayCpp.MaterialIlluminationPhong( 3, 10, 10, 0 ) # third result

    cargo['c'] = IceRayCpp.MaterialColorArithmeticPlus( 0, 1, 2 )
    cargo['d'] = IceRayCpp.MaterialColorArithmeticPlus( 0, 0, 3 )


    surface.append( cargo['1'] )
    surface.append( cargo['2'] )
    surface.append( cargo['3'] )
    surface.append( cargo['3A'] )
    surface.append( cargo['3B'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )
    surface.append( cargo['7'] )
    surface.append( cargo['8'] )
    surface.append( cargo['9'] )
    surface.append( cargo['a'] )
    surface.append( cargo['b'] )
    surface.append( cargo['c'] )
    surface.append( cargo['d'] )

    return { 'this' : surface, 'light': P_light, 'cargo': cargo  }