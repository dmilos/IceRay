import IceRayCpp
#from test.core import *

import light
import material

from material.transmission.blossom.grid.unit             import *
from material.transmission.blossom.hexagon.unit          import *
from material.transmission.blossom.random.unit           import *
from material.transmission.blossom.vdc.unit              import *

def make_nothing( P_light ):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0 ), 0 )
    #MaterialIlluminationAmbient( [color]result, [color]emission )
    cargo['2'] = IceRayCpp.MaterialIlluminationAmbient( 0, 0 )

    surface.append( cargo['1'] )
    surface.append( cargo['2'] )

    return { 'this' : surface, 'light': P_light, 'cargo': cargo  }

def make_mirror(
     P_light
    ,P_ambient = IceRayCpp.GraphTypeColorRGB().fill( 0.0 ) 
    ,P_albedo = IceRayCpp.GraphTypeColorRGB().fill( 1.0 ) 
    
    ):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}

    cargo['0'] = IceRayCpp.MaterialPatternColorConstant( P_ambient, 0 )
    cargo['1'] = IceRayCpp.MaterialPatternColorConstant( P_albedo, 1 ) #Albedo
    #MaterialTransmissionReflectOne( [coord]point, [coord]normal, [color]albedo )
    cargo['2'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 1 )

    surface.append( cargo['0'] )
    surface.append( cargo['1'] )
    surface.append( cargo['2'] )

    return { 'this' : surface, 'cargo': cargo, ';': P_light  }

def make_ambient( P_light, P_color = IceRayCpp.GraphTypeColorRGB().fill( 0.5 ) ):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialPatternColorConstant( P_color, 0 )
    #MaterialIlluminationAmbient( [color]result, [color]emission )
    cargo['2'] = IceRayCpp.MaterialIlluminationAmbient( 0, 0 )

    surface.append( cargo['1'] )
    surface.append( cargo['2'] )

    return { 'this' : surface, 'light': P_light, 'cargo': cargo  }

def make_radiositySplit(
     P_ambient,
     P_albedo =IceRayCpp.GraphTypeColorRGB().fill( 0.8 ),
     P_angle  = 0.2,
     P_sample = 8,
     P_gauss  = 1
):

    surface = IceRayCpp.MaterialSurface()

    cargo = {}

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( P_albedo, 1 )
    #MaterialTransmissionReflectOne( [coord]point, [coord]normal, [color]albedo )
    cargo['4'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 1 )
    I_laeder  = 0
    cargo['5'] = IceRayCpp.MaterialPatternSizeConstant(   I_laeder,1 ) # leader
    cargo['6'] = IceRayCpp.MaterialPatternSizeConstant(   P_sample, 2 ) # sample
    cargo['7'] = IceRayCpp.MaterialPatternScalarConstant( P_angle, 2 ) # angle
    cargo['8'] = IceRayCpp.MaterialPatternScalarConstant( P_gauss, 3 ) # gauss

    #MaterialTransmissionBlossom( [coord]normal, [scalar]leader, [size]size, [scalar]angle, [scalar]gauss )
    cargo['8'] = IceRayCpp.MaterialTransmissionBlossomGrid( 1, 1, 2, 2, 3 )

    cargo['F'] = IceRayCpp.MaterialPatternColorConstant( P_ambient, 0 )

    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )
    surface.append( cargo['7'] )
    surface.append( cargo['8'] )
    surface.append( cargo['F'] )

    return { 'this' : surface, 'cargo': cargo }


def make_radiosityHexagon( P_light, P_color, P_albedo=IceRayCpp.GraphTypeColorRGB().fill( 0.8 ), P_angle = 0.2, P_sample = 8 ):
    return material.transmission.blossom.hexagon.unit.make( P_light = P_light,P_ambient = P_color, P_angle = P_angle, P_sample = P_sample )

def make_radiosityGrid( P_light, P_color, P_albedo=IceRayCpp.GraphTypeColorRGB().fill( 0.8 ), P_angle = 0.2, P_sample = 8 ):
    return material.transmission.blossom.grid.unit.make( P_light = P_light,P_ambient = P_color, P_angle = P_angle, P_sample = P_sample )

def make_radiosityVDC( P_light, P_color, P_albedo=IceRayCpp.GraphTypeColorRGB().fill( 0.8 ), P_angle = 0.2, P_sample = 8 ):
    return material.transmission.blossom.vdc.unit.make( P_light = P_light,P_ambient = P_color, P_angle = P_angle, P_sample = P_sample )

def make_radiosityRandom( P_light, P_color, P_albedo=IceRayCpp.GraphTypeColorRGB().fill( 0.8 ), P_angle = 0.2, P_sample = 8 ):
    return material.transmission.blossom.random.unit.make( P_light = P_light,P_ambient = P_color, P_angle = P_angle, P_sample = P_sample )

def make_lambert( P_light, P_color = IceRayCpp.GraphTypeColorRGB().fill( 0.5 ) ):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['3'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarm( [coord]point, [light]light, [spot]start, [size]count  )
    cargo['4A'] = IceRayCpp.MaterialLightSpotSwarm( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['4B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['5'] = IceRayCpp.MaterialPatternColorConstant( P_color, 1 )
    #MaterialIlluminationLambert( [color]result, [coord]point, [coord]normal, [size]spotCount, [color]diffuse )
    cargo['6'] = IceRayCpp.MaterialIlluminationLambert( 0, 0, 1, 0, 1 )

    surface.append( cargo['3'] )
    surface.append( cargo['4A'] )
    surface.append( cargo['4B'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )

    return { 'this' : surface, 'light': P_light, 'cargo': cargo  }
