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

def print_ambient(P_ambient):
    print( P_ambient )

class Ambient:
    m_ambient = None

    def __init__(self, P_result = IceRayCpp.MaterialIlluminationAmbient.Output.result, P_emission = 1 ):
        self.m_ambient = IceRayCpp.MaterialIlluminationAmbient(P_result, P_emission )

    def set_emission(self, P_emission ):
        self.m_ambient.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationAmbient.Input.emission, P_emission )

    def set_result( self, P_result ):
        self.m_ambient.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationAmbient.Output.result,   P_result )

    def get_instruction( self ):
        return self.m_ambient

print( '********************' )

print( '------------' )

ambient1 = IceRayCpp.MaterialIlluminationAmbient( 0, 0 )
ambient2 = IceRayCpp.MaterialIlluminationAmbient( 0, 0 )

a = Ambient()

a.set_emission( 10 );
a.set_result( 10 );

print_ambient( ambient1 )

