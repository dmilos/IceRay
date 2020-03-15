import IceRayCpp

#print( __name__ )

class Generator:
    m_generator = None

    def __init__( self, P_light = None, P_result = 0 ):
        self.m_generator = IceRayCpp.MaterialLightGenerator( P_light, P_result )

    def get_instruction( self ):
        return self.m_generator

    def set_input(self, P_type, P_index):
        pass

    def set_output(self, P_type, P_index):
        if( 'result' == P_type ):
            self.m_generator.input(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightGenerator.Output.result, P_index )

    def set_light( self, P_light ):
        return self.m_generator.light( P_light )

def Print( P_generator ):
    print( P_generator.m_generator.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightGenerator.Output.result ) )

