#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy.utility.material.operation.mapping




def NOP(
    P_dll
    ,P_config = None
   ):

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.NOP( P_dll ) )

    return I_surface

def Expression(
    P_dll
    ,P_config = None
    ,P_expression = None
   ):

    scalar_memory = IceRayPy.core.material.instruction.label.scalar.dynamic._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    e = IceRayPy.core.material.instruction.Expression( P_dll, scalar_memory, scalar_memory );
    I_surface.append( e )
    e.string2index( 0, "x")
    e.string2index( 1, "y")
    e.string2index( 2, "z")

    e.index2index(0,0)
    e.index2index(1,1)
    e.index2index(2,2)
    e.expression("x+y+z")

    return I_surface

def Coord3D2Color(
    P_dll
    ,P_config = None
    ,P_function = None
    ,P_filename = None
   ):

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    normal = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.convert.Coord3D2Color( P_dll, result, normal ) )

    return I_surface

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
