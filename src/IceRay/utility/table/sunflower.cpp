#include "./sunflower.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_table
       {

        bool GC_sunflower::F_init( T_size const& P_size )
         {
          M2_structure.F_clear();
          M2_structure.F_spot().reserve( P_size  );
          T_scalar I_torsion = ( T_scalar(3)-sqrt( T_scalar(5) ) ) * math::constants::PHI;
          T_scalar I_c = 1;

          for( T_size I_index=0; I_index < P_size; ++I_index )
           {
            auto I_r     = I_c * sqrt( I_index );
            auto I_theta = I_index * I_torsion;

            T_coord2D I_spot;
            I_spot[0] = I_r * cos( I_theta );
            I_spot[1] = I_r * sin( I_theta );

            M2_structure.F_spot().push_back( I_spot );
           }

          M2_structure.F_compile();
          return true;
         }

       }
     }
   }
 }