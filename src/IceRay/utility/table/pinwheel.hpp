#ifndef Dh_DDMRM_Iceray_utility_table_v_HPP_
 #define Dh_DDMRM_Iceray_utility_table_pinwheel_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_table::GC_pinwheel

#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/math/coord.hpp"

#include "./structure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_table
        {

         class GC_pinwheel
          { //https://en.wikipedia.org/wiki/Pinwheel_tiling
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_coord2D;

             typedef GS_DDMRM::S_IceRay::S_utility::S_table::GC_structure  T_structure;
           public:
             explicit GC_pinwheel( T_size const& P_size = 10 )
              {
               F_init( P_size );
              }
           public:
             bool F_init( T_size const& P_size )
              { // TODO
               M2_structure.F_clear();
               M2_structure.F_spot().reserve( P_size * P_size );

               T_size I_grid = P_size;
               T_scalar I_perimeter = I_grid/2 - 2;
               T_scalar I_offset = T_scalar(1)/T_scalar(2);
               T_scalar I_height = sqrt(T_scalar(3))/T_scalar(2);

               for( T_size I_v =0; I_v < I_grid; ++ I_v )
               for( T_size I_u =0; I_u < I_grid; ++ I_u )
                {
                 T_coord2D I_spot;
                 I_spot[0] = ( I_u - T_scalar(I_grid/2) ) + I_offset * abs( ( int(I_v) - int(I_grid/2) )%2 ) ;
                 I_spot[1] = ( I_v - T_scalar(I_grid/2) ) *I_height ;

                 if( I_perimeter < ::math::linear::vector::length( I_spot ) )
                  {
                   continue;
                  }
                 M2_structure.F_spot().push_back( I_spot );
                }

               M2_structure.F_compile();
               return true;
              }

           public:
             T_structure const& F_structure()const{ return M2_structure; }
             T_structure      & F_structure()     { return M2_structure; }
           private:
             T_structure    M2_structure;
          };

        }
      }
    }
  }
#endif
