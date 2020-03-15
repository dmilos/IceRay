import IceRayPy
import IceRayCpp

generator_1 = IceRayCpp.MaterialLightGenerator()
#generator_1 = IceRayCpp.MaterialLightGenerator( 0 )
generator_1.output( IceRayCpp.MaterialSurface_Instruction.color, IceRayCpp.MaterialLightGenerator.Output.result,  0 )


generator = IceRayPy.core.material.light.generator.Generator()

generator.set_output( 'result', 0  );
generator.set_light( None );

IceRayPy.core.material.light.generator.Print( generator )






