import IceRayCpp
import light

def make( ):
    global IceRayCpp
    surface = IceRayCpp.MaterialSurface()

    light_cargo = light.make( )

    a = {}
    a['1'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.1 ), 0 )
    a['2'] = IceRayCpp.MaterialIlluminationAmbient( 0, 0 )
    a['3'] = IceRayCpp.MaterialLightGenerator( light_cargo['this'], 0 )
    a['4'] = IceRayCpp.MaterialLightSwarm0( 0, 0 )
    a['5'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.5 ), 1 )
    #MaterialIlluminationLambert( [color]result, [coord]point, [coord]normal, [size]spotCount, [color]diffuse )
    a['6'] = IceRayCpp.MaterialIlluminationLambert( 0, 0, 1, 0, 1 )

    surface.append( a['1'] )
    surface.append( a['2'] )
    surface.append( a['3'] )
    surface.append( a['4'] )
    surface.append( a['5'] )
    surface.append( a['6'] )

    return { 'this' : surface, 'light': light_cargo, '0': a  }
