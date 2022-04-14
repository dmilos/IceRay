#ifndef Dh_IceRay_material_pattern_noise_value_hpp_
 #define Dh_IceRay_material_pattern_noise_value_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_ValueNoise

#include "../_pure.hpp"
#include "IceRay/utility/table/value.hpp"







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

         class GC_value
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;


             GC_value( T_size const& P_iteration=1, T_scalar const& P_scale=1.6, T_scalar const& P_coefficient = 0.6 )
              :M2_iteration( P_iteration )
              ,M2_scale( P_scale )
              ,M2_coefficient(P_coefficient)
              {
               static auto dummy = F2s_init();
              }

           public:
            void  Fv_process( T_result &P_result, T_coord const& P_coord )const
             {
              P_result = 0;

              auto I_point = P_coord;
              auto I_iteration = M2_iteration;
              T_scalar I_coefficient = 1;
              T_scalar I_weight = 0;

              while( I_iteration-- )
               {
                //P_result += I_coefficient * (int)(5*this->Fs_f( I_point ))/T_scalar( 4 );
                P_result += I_coefficient * this->Fs_f( I_point );
                I_weight += I_coefficient;
                I_coefficient *= M2_coefficient;
                ::math::linear::vector::scale( I_point, M2_scale );
               }
              P_result /= I_weight;
             }

            private:
             static T_scalar Fs_f( T_coord const& P_coord )
              {
               int x = (int)floor( P_coord[0] );
               int y = (int)floor( P_coord[1] );
               int z = (int)floor( P_coord[2] );

               T_scalar tx = P_coord[0] - x;
               T_scalar ty = P_coord[1] - y;
               T_scalar tz = P_coord[2] - z;

              T_scalar Ir_result =
               +(1-tx)*(1-ty)*(1-tz)* Fs_table( x,   y  , z   )
               +(  tx)*(1-ty)*(1-tz)* Fs_table( x+1, y  , z   )
               +(1-tx)*(  ty)*(1-tz)* Fs_table( x,   y+1, z   )
               +(  tx)*(  ty)*(1-tz)* Fs_table( x+1, y+1, z   )
               +(1-tx)*(1-ty)*(  tz)* Fs_table( x,   y  , z+1 )
               +(  tx)*(1-ty)*(  tz)* Fs_table( x+1, y  , z+1 )
               +(1-tx)*(  ty)*(  tz)* Fs_table( x,   y+1, z+1 )
               +(  tx)*(  ty)*(  tz)* Fs_table( x+1, y+1, z+1 );

               return Ir_result;
              }

             static T_scalar Fs_table( int x, int y, int z )
              {
               if( x < 0 ) { x = M2s_table.F_size()[0] - (- x)%M2s_table.F_size()[0]; }
               if( y < 0 ) { y = M2s_table.F_size()[1] - (- y)%M2s_table.F_size()[1]; }
               if( z < 0 ) { z = M2s_table.F_size()[2] - (- z)%M2s_table.F_size()[2]; }
               return M2s_table[{ x%M2s_table.F_size()[0], y%M2s_table.F_size()[1], z%M2s_table.F_size()[2] } ][0];
              }

             T_size   M2_iteration;
             T_scalar M2_scale;
             T_scalar M2_coefficient;
             static bool F2s_init()
              {
               M2s_table.F_size({10,10,10});
               return true;
              }
             static GS_DDMRM::S_IceRay::S_utility::S_table::GC_value<3,1> M2s_table;
          };

          }
        }
      }
    }
  }

#endif
