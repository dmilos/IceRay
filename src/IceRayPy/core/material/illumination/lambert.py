import IceRayCpp

#print( __name__ )

class Lambert:
    m_generator = None

    def __init__( self, P_light = None, P_result = 0 ):
        self.m_lambert = IceRayCpp.MaterialIlluminationLambert()

    def get_native( self ):
        return self.m_lambert

    def set_input(self, P_type, P_index):
        if( 'point' == P_type ):
            self.m_lambert.output(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationLambert.Output.point,      P_index )
        if( 'normal' == P_type ):
            self.m_lambert.output(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationLambert.Output.normal,     P_index )
        if( 'diffuse' == P_type ):
            self.m_lambert.output(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationLambert.Output.diffuse,    P_index )
        if( 'LightCount' == P_type ):
            self.m_lambert.output(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationLambert.Output.LightCount, P_index )

    def set_output(self, P_type, P_index):
        if( 'result' == P_type ):
            self.m_lambert.output(  IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialIlluminationLambert.Output.result, P_index )


def Print( P_generator ):
    pass
    print( P_generator.m_generator.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightGenerator.Output.result ) )

