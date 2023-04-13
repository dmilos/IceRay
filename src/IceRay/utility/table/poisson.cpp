#include "./poisson.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_table
       {

        bool GC_poisson::F_init( T_size const& P_size )
         {
          M2_structure.F_clear();
          M2_structure.F_spot().reserve( P_size );

          for( T_size I_index=0; I_index < P_size; ++I_index )
           {
            T_coord2D I_spot;
            I_spot[0] = rand() * T_scalar(2)/(T_scalar)(RAND_MAX) - T_scalar(1);
            I_spot[1] = rand() * T_scalar(2)/(T_scalar)(RAND_MAX) - T_scalar(1);

            M2_structure.F_spot().push_back( I_spot );
           }

          M2_structure.F_compile();
          return true;
         }

       }
     }
   }
 }