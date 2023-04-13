#include "./ld.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_table
       {

         GC_LD::GC_LD( T_size const& P_size )
          {
           F_init( P_size );
          }

        bool GC_LD::F_init( T_size const& P_size )
         {
          M2_structure.F_clear();
          M2_structure.F_spot().reserve( P_size );

          T_scalar I_perimeter = 0;
          T_scalar I_torsion = ( T_scalar(3)-sqrt( T_scalar(5) ) ) * math::constants::PHI;

          T_coord2D I_spot;
          for( T_size I_index = 0; I_index < P_size; ++ I_index )
           {
            ::math::function::lebesgue2D( I_spot, I_index/T_scalar(P_size), 8 );
            I_spot[0] = 2*I_spot[0]-1;
            I_spot[1] = 2*I_spot[1]-1;
            T_scalar I_len = ::math::linear::vector::length( I_spot ) / std::max( fabs( I_spot[0] ), fabs( I_spot[1] ) );

            I_spot[0] /= I_len;
            I_spot[1] /= I_len;

            //auto I_r     = 1 * sqrt( I_index );
            //auto I_theta = I_index * I_torsion;
            //I_spot[0] = I_r * cos( I_theta );
            //I_spot[1] = I_r * sin( I_theta );

            M2_structure.F_spot().push_back( I_spot );
            I_perimeter = std::max( I_perimeter, ::math::linear::vector::length( I_spot ) );
           }

          for( auto & I_spot : M2_structure.F_spot() )
           {
            ::math::linear::vector::scale( I_spot, T_scalar(1)/I_perimeter );
           }

          return true;
         }

       }
     }
   }
 }