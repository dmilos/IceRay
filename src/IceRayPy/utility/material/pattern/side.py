#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )


def Cube( P_dll
        #, P_color =[  ]
    ):
    I_pattern = IceRayPy.core.material.pattern.side.Cube( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    switch = IceRayPy.core.material.instruction.label.size.temp._BEGIN

    temp = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Size( P_dll, I_pattern, switch, point ) )
    #TODO I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_red,   temp + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.switch.Color( P_dll, result, switch,  temp + 0 ) )

    return I_surface


def Dodecahedron( P_dll

    ):
    I_pattern = IceRayPy.core.material.pattern.side.Dodecahedron( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    switch = IceRayPy.core.material.instruction.label.size.temp._BEGIN

    temp = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Size( P_dll, I_pattern, switch, point ) )
    #TODO I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_red,   temp + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.switch.Color( P_dll, result, switch,  temp + 0 ) )

    return I_surface


def Icosahedron( P_dll

    ):
    I_pattern = IceRayPy.core.material.pattern.side.Icosahedron( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    switch = IceRayPy.core.material.instruction.label.size.temp._BEGIN

    temp = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Size( P_dll, I_pattern, switch, point ) )
    #TODO I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_red,   temp + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.switch.Color( P_dll, result, switch,  temp + 0 ) )

    return I_surface


def Octahedron( P_dll

    ):
    I_pattern = IceRayPy.core.material.pattern.side.Octahedron( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    switch = IceRayPy.core.material.instruction.label.size.temp._BEGIN

    temp = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Size( P_dll, I_pattern, switch, point ) )
    #TODO I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_red,   temp + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.switch.Color( P_dll, result, switch,  temp + 0 ) )

    return I_surface


def Tetrahedron( P_dll

    ):
    I_pattern = IceRayPy.core.material.pattern.side.Tetrahedron( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    switch = IceRayPy.core.material.instruction.label.size.temp._BEGIN

    temp = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Size( P_dll, I_pattern, switch, point ) )
    #TODO I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_red,   temp + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.switch.Color( P_dll, result, switch,  temp + 0 ) )

    return I_surface


#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )