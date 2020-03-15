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

def print_ONp44(P_ONp44):
    print

def make_ONp44( P_emission, P_result ):
    ONp441 = IceRayCpp.MaterialIlluminationONp44()

    # TODO ONp441.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationONp44.Input.emission, P_emission )

    ONp441.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationONp44.Output.result,   P_result )
    ONp441.output( IceRayCpp.MaterialSurface_Instruction.bool,  IceRayCpp.MaterialIlluminationONp44.Output.valid,    IceRayCpp.MaterialSurface_Instruction.ConstantBool.valid )

    return ONp441

print( '********************' )

ONp441 = make_ONp44(0,0)

print( '------------' )
print_ONp44( ONp441 )
print

