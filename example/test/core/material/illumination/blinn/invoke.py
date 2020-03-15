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

def print_blinn(P_blinn):
    print( P_blinn )

def make_blinn( P_emission, P_result ):
    blinn1 = IceRayCpp.MaterialIlluminationBlinn()

    # TODO blinn1.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationBlinn.Input.emission, P_emission )

    blinn1.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationBlinn.Output.result,   P_result )
    blinn1.output( IceRayCpp.MaterialSurface_Instruction.bool,  IceRayCpp.MaterialIlluminationBlinn.Output.valid,    IceRayCpp.MaterialSurface_Instruction.ConstantBool.valid )

    return blinn1


print( '********************' )

blinn1 = make_blinn(0,0)

print( '------------' )
print_blinn( blinn1 )
print()

