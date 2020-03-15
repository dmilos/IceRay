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

def print_WardApprox(P_WardApprox):
    print

def make_WardApprox( P_emission, P_result ):
    WardApprox1 = IceRayCpp.MaterialIlluminationWardApprox()

    # TODO WardApprox1.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationWardApprox.Input.emission, P_emission )

    WardApprox1.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationWardApprox.Output.result,   P_result )
    WardApprox1.output( IceRayCpp.MaterialSurface_Instruction.bool,  IceRayCpp.MaterialIlluminationWardApprox.Output.valid,    IceRayCpp.MaterialSurface_Instruction.ConstantBool.valid )

    return WardApprox1

print( '********************' )

WardApprox1 = make_WardApprox(0,0)

print( '------------' )
print_WardApprox( WardApprox1 )
print

