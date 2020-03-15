#ifndef Dh_IceRay_material_pattern_crackle_hpp_
 #define Dh_IceRay_material_pattern_crackle_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_crackle

#include "../_pure.hpp"
#include "IceRay/utility/table/value.hpp"


#include <iostream>
#include <iomanip>




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

         class GC_crackle
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
          {
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                 T_size;
           public:

             GC_crackle()
              {
               static auto dummy = F2s_init();
              }

             ~GC_crackle()
              {
               //std::cout << std::endl;
               //std::cout << "crackle: " << Ms_min<< ", ";
               //std::cout << Ms_max<< std::endl;
              }
           public:
            void  Fv_process( T_result &P_result, T_coord const& P_coord )const
             {
              static const T_size Ics_size = 64;
              T_coord I_coord = P_coord;

              int x = floor( I_coord[0] );
              int y = floor( I_coord[1] );
              int z = floor( I_coord[2] );

              T_coord  I_fract{ I_coord[0] - x, I_coord[1] - y, I_coord[2] - z };

              int x_min = x-2, x_max = x+2;
              int y_min = y-2, y_max = y+2;
              int z_min = z-2, z_max = z+2;

              P_result=100;
              for( x = x_min; x < x_max; ++x )
              for( y = y_min; y < y_max; ++y )
              for( z = z_min; z < z_max; ++z )
              {
                auto const& I_beee = Fs_table(x,y,z);
                T_coord I_point{ I_beee[0] + x, I_beee[1] + y, I_beee[2] + z };
                auto d = ::math::linear::vector::distance( I_coord, I_point );
                if( d < P_result )
                 {
                  P_result = d;
                 }
              }
              P_result /= sqrt(3);//1.07391;
              //if( P_result < Ms_min )   Ms_min = P_result;
              //if( Ms_max < P_result )   Ms_max = P_result;
             }

             static T_coord const& Fs_table( int  x, int y, int z )
              {
               if( x < 0 ) { x = M2s_table.F_size()[0] - (- x)%M2s_table.F_size()[0]; }
               if( y < 0 ) { y = M2s_table.F_size()[1] - (- y)%M2s_table.F_size()[1]; }
               if( z < 0 ) { z = M2s_table.F_size()[2] - (- z)%M2s_table.F_size()[2]; }
               return M2s_table[{ x%M2s_table.F_size()[0], y%M2s_table.F_size()[1], z%M2s_table.F_size()[2] } ];
              }

             static bool F2s_init()
              {
               M2s_table.F_size( {10, 10, 10 } );
               return true;
              }
             static T_scalar Ms_min;
             static T_scalar Ms_max;
             static GS_DDMRM::S_IceRay::S_utility::S_table::GC_value<3,3> M2s_table;
          };

          }
        }
      }
    }
  }

#endif
