#include "./hexagon.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_table
       {

        bool GC_hexagon::F_init( T_size const& P_size )
         {
          M2_structure.F_clear();
          M2_structure.F_spot().reserve( P_size * P_size );

          T_size I_grid = P_size;
          T_scalar I_perimeter = T_scalar(I_grid);
          T_scalar I_offset = T_scalar(1)/T_scalar(2);
          T_scalar I_height = sqrt(T_scalar(3))/T_scalar(2);

          for( T_int I_v = 0; I_v < T_int(T_int( I_grid)/I_height + 0.5 ); ++ I_v )
           for( T_int I_u = 0; I_u < T_int(I_grid); ++ I_u )
            {
             T_coord2D I_spot;
             I_spot[0] = 2*(I_u+( (I_v)%2)) - (I_u+( (I_v)%2))/T_int(2) - 2*( (I_v)%2);
             I_spot[1] = I_v *I_height;
             I_spot[0] += T_scalar(0.5) * ( abs(I_v) % 2 );
             if( ::math::linear::vector::length( I_spot ) < I_perimeter )
              {
               M2_structure.F_spot().push_back( I_spot );
              }

             I_spot[0] = - I_spot[0] -1;
             if( ::math::linear::vector::length( I_spot ) < I_perimeter )
              {
               M2_structure.F_spot().push_back( I_spot );
              }

             I_spot[0] += 1.5;
             I_spot[1] = - I_spot[1] - I_height;
             if( ::math::linear::vector::length( I_spot ) < I_perimeter )
              {
               M2_structure.F_spot().push_back( I_spot );
              }

             I_spot[0] = -I_spot[0] + 2;
             if( ::math::linear::vector::length( I_spot ) < I_perimeter )
              {
               M2_structure.F_spot().push_back( I_spot );
              }

            }

          M2_structure.F_compile();
          return true;
         }

       }
     }
   }
 }