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

def print_HSPhong(P_HSPhong):
    print

def make_HSPhong( P_emission, P_result ):
    HSPhong1 = IceRayCpp.MaterialIlluminationHSPhong()

    # TODO HSPhong1.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationHSPhong.Input.emission, P_emission )

    HSPhong1.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationHSPhong.Output.result,   P_result )
    HSPhong1.output( IceRayCpp.MaterialSurface_Instruction.bool,  IceRayCpp.MaterialIlluminationHSPhong.Output.valid,    IceRayCpp.MaterialSurface_Instruction.ConstantBool.valid )

    return HSPhong1

print( '********************' )

HSPhong1 = make_HSPhong(0,0)

print( '------------' )
print_HSPhong( HSPhong1 )
print

