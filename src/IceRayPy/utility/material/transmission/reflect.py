#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import math
import IceRayPy


def Mirror(
     P_dll
    ,P_config
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_albedo = tempColor + 0
    I_leader = tempSize + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 1, 1, 1 ), I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    return I_surface

def One(
     P_dll
    ,P_config
    ,P_albedo : IceRayPy.type.color.RGB = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_albedo = tempColor + 0
    I_leader = tempSize + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    return I_surface

def Diffusive(
     P_dll
    ,P_config
    ,P_albedo : IceRayPy.type.color.RGB = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    ,P_coefficient = 0.5
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_albedo = tempColor + 0
    I_leader = tempSize + 0
    I_coefficient = tempScalar + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, P_coefficient, I_coefficient ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.Diffusive( P_dll, point, normal, I_albedo, I_coefficient, I_leader ) )

    return I_surface

def Schlick(
     P_dll
    ,P_config
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_leader = tempSize + 0
    I_ior = tempScalar + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(               P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(              P_dll, P_ior, I_ior ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.Schlick( P_dll, point, normal, I_ior, I_leader ) )

    return I_surface


def Blossom(
     P_dll
    ,P_config
    ):

    I_albedoValue = IceRayPy.type.color.RGB( 1, 1, 0.8 )
    if( 'albedo' in P_config ):
        I_albedoValue = P_config['albedo']

    I_countValue = 10
    if( 'sample' in P_config ):
        I_countValue = P_config['sample']

    I_angleValue = math.radians(30)
    if( 'angle' in P_config ):
        I_angleValue = P_config['angle']

    I_gaussValue = 0.5
    if( 'gauss' in P_config ):
        I_gaussValue = P_config['gauss']
        
    I_iorValue = 1.20
    if( 'ior' in P_config ):
        I_iorValue = P_config['ior']

    I_coefficientValue = 0.5
    if( 'coefficient' in P_config ):
        I_coefficientValue = P_config['coefficient']

    I_leaderValue = 0
    if( 'leader' in P_config ):
        I_leaderValue = P_config['leader']

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    incident   = IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_count  = tempSize + 0
    I_leader = tempSize + 1
    I_total  = tempSize + 2
    I_start  = tempSize + 3
    I_angle  = tempScalar + 0
    I_gauss  = tempScalar + 1
    I_jitter = tempScalar + 2
    I_ior    = tempScalar + 3
    I_coefficient = tempScalar + 4
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, I_countValue,        I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, I_leaderValue,       I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, I_countValue,        I_total  ) )   #!< defualt value for total is count
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_angleValue,        I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_gaussValue,        I_gauss  ) )

    if( 'jitter' in P_config ):
        if( 'angle' in P_config['jitter'] ):
            I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter']['angle'], I_jitter ) )

    if( 'reflect' in P_config ):
        if( 'one' == P_config['reflect'] ):
            I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, I_albedoValue,       I_albedo ) )
            I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One(       P_dll, point, normal, I_albedo, I_leader ) )
        if( 'diffusive' == P_config['reflect'] ):
            I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, I_albedoValue,       I_albedo ) )
            I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_coefficientValue,        I_coefficient  ) )
            I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.Diffusive( P_dll, point, normal, I_albedo, I_coefficient, I_leader ) )
        if( 'schlick' == P_config['reflect'] ):
            I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_iorValue,        I_ior  ) )
            I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.Schlick(   P_dll, point, normal, I_albedo, I_ior,         I_leader ) )

    if( 'correction' in P_config ):
        if( 'leader' in P_config['correction'] ):
            if( True == P_config['correction']['leader'] ):
                I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_leader ) )
        if( 'cone' in P_config['correction'] ):
            if( True == P_config['correction']['cone'] ):
                I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    if( 'type' in P_config ):
        if( 'grid' == P_config['type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Grid( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_total, I_start ) )
        if( 'hexagon' == P_config['type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Hexagon( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_total, I_start ) )
        if( 'kmeans' == P_config['type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.KMeans( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_total, I_start ) )
        if( 'pinwheel' == P_config['type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Pinwheel( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_total ) )
        if( 'poisson' == P_config['type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Poisson( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_total, I_start ) )
        if( 'sunflower' == P_config['type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Sunflower( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_total, I_start ) )
        if( 'ld' == P_config['type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.LD(        P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_start ) )
        if( 'random' == P_config['type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Random( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_start ) )
        if( 'sobol' == P_config['type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Sobol( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_start ) )
        if( 'congruent' == P_config['type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Congruent( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_start ) )
        if( 'triangle' == P_config['type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Triangle( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_total, I_start ) )
        if( 'vdc' == P_config['type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.VDC( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_start ) )

    if( 'jitter' in P_config ):
        if( 'type' in P_config['jitter'] ):
            if( 'random' == P_config['jitter']['type'] ):
                I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
            if( 'sobol'  == P_config['jitter']['type'] ):
                I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
            if( 'vdc'    == P_config['jitter']['type'] ):
                I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
            if( 'congruent' == P_config['jitter']['type'] ):
                I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent( P_dll, normal, I_total, I_start, I_jitter ) )
            if( 'none'    == P_config['jitter']['type'] ):
                pass

    if( 'correction' in P_config ):
        if( 'claim' == P_config['correction']['rays'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
        if( 'trim' == P_config['correction']['rays'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )

    return I_surface



#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )