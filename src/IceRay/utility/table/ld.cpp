#include "./ld.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_table
       {

         GC_LD::GC_LD( )
          {
           F_init( 10 );
            M2_number={1,2,3,4,5,6};
          }

        bool GC_LD::F_init( T_size const& P_size )
         {
          M2_container.clear();
          M2_container.reserve( P_size * P_size );

          T_size I_grid = P_size;
          T_scalar I_perimeter = I_grid;
          T_scalar I_offset = T_scalar(1)/T_scalar(2);
          T_scalar I_height = sqrt(T_scalar(3))/T_scalar(2);

          for( T_size I_index = 0; I_index < P_size*P_size; ++ I_index )
            {
             T_scalar I_parameter = (I_index+0.5)/(P_size*P_size);
             T_coord2D I_spot;
             ::math::function::lebesgue2D( I_spot, I_parameter, 8 );
             I_spot[0] = 2*I_spot[0]-1;
             I_spot[1] = 2*I_spot[1]-1;
             T_scalar I_len = sqrt( I_spot[0]*I_spot[0] + I_spot[1] * I_spot[1] ) / std::max( fabs( I_spot[0] ), fabs( I_spot[1] ) );

             I_spot[0] /= I_len;
             I_spot[1] /= I_len;

             M2_container.push_back( I_spot );
            }

          return true;
         }

       }
     }
   }
 }