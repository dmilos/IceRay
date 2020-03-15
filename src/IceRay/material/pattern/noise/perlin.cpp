#include "./perlin.hpp"


namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_material
     {
      namespace S_pattern
       {
        namespace S_noise
         {

          GS_DDMRM::S_IceRay::S_utility::S_table::GC_value<3,3> GC_perlin::M2s_table;
        GC_perlin::T_scalar GC_perlin::Ms_min;
        GC_perlin::T_scalar GC_perlin::Ms_max;

        bool GC_perlin::F2s_init( )
         {
          std::srand(0);
          M2s_table.F_size( {64,64,64} );

          Ms_min =+100;  //Perlin: -0.65661, 0.626277
          Ms_max =-100;

          for( T_size x=0;x<M2s_table.F_size()[0];++x )
           for( T_size y=0;y<M2s_table.F_size()[1];++y )
            for( T_size z=0;z<M2s_table.F_size()[2];++z )
             {
              auto & v = M2s_table[{x,y,z}];
              
              ::math::linear::vector::subtraction( v, {0.5,0.5,0.5} );
              ::math::linear::vector::length( v , T_scalar(1) );
             }
          return true;
         }

         }
       }
     }
   }
 }
