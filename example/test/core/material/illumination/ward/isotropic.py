import sys
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

def print_string( P_string ):
    sys.stdout.write( P_string )

def print_coord(P_cord):
    sys.stdout.write( '(' + str( P_cord[0] ) + ', ' + str( P_cord[1] ) + ', ' +  str( P_cord[2] ) + ')' )

def print_interval(P_interval):
    sys.stdout.write('( ')
    print_coord( P_interval.lo() )
    print_coord( P_interval.hi() )
    sys.stdout.write(' )')

def print_WardIsotropic(P_WardIsotropic):
    print

def make_WardIsotropic( P_emission, P_result ):
    WardIsotropic1 = IceRayCpp.MaterialIlluminationWardIsotropic()

    # TODO WardIsotropic1.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationWardIsotropic.Input.emission, P_emission )

    WardIsotropic1.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationWardIsotropic.Output.result,   P_result )
    WardIsotropic1.output( IceRayCpp.MaterialSurface_Instruction.bool,  IceRayCpp.MaterialIlluminationWardIsotropic.Output.valid,    IceRayCpp.MaterialSurface_Instruction.ConstantBool.valid )

    return WardIsotropic1

print( '********************' )

WardIsotropic1 = make_WardIsotropic(0,0)

print( '------------' )
print_WardIsotropic( WardIsotropic1 )
print

