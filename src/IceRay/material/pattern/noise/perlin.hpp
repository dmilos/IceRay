#ifndef Dh_IceRay_material_pattern_noise_perlin_hpp_
 #define Dh_IceRay_material_pattern_noise_perlin_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_PerlinNoise

#include "../_pure.hpp"

#include <iostream>
#include <iomanip>
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

         class GC_perlin
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
             typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;


             GC_perlin( T_size const& P_iteration=1, T_scalar const& P_scale=1.6, T_scalar const& P_coefficient = 0.6 )
              :M2_iteration( P_iteration )
              ,M2_scale( P_scale )
              ,M2_coefficient(P_coefficient)
              {
               static auto dummy = F2s_init();
              }

             ~GC_perlin()
              {
               //std::cout << std::endl;
               //std::cout << "Perlin: " << Ms_min<< ", ";
               //std::cout << Ms_max<< std::endl;
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

               tx =  tx * tx * tx * (tx * (tx * 6 - 15) + 10);  // tx*tx*(3-2*tx);
               ty =  ty * ty * ty * (ty * (ty * 6 - 15) + 10);  // ty*ty*(3-2*ty);
               tz =  tz * tz * tz * (tz * (tz * 6 - 15) + 10);  // tz*tz*(3-2*tz);

               T_scalar Ir_result =
                 +(1-tx)*(1-ty)*(1-tz)* Fs_value( x,   y  , z  , P_coord )
                 +(  tx)*(1-ty)*(1-tz)* Fs_value( x+1, y  , z  , P_coord )
                 +(1-tx)*(  ty)*(1-tz)* Fs_value( x,   y+1, z  , P_coord )
                 +(  tx)*(  ty)*(1-tz)* Fs_value( x+1, y+1, z  , P_coord )
                 +(1-tx)*(1-ty)*(  tz)* Fs_value( x,   y  , z+1, P_coord )
                 +(  tx)*(1-ty)*(  tz)* Fs_value( x+1, y  , z+1, P_coord )
                 +(1-tx)*(  ty)*(  tz)* Fs_value( x,   y+1, z+1, P_coord )
                 +(  tx)*(  ty)*(  tz)* Fs_value( x+1, y+1, z+1, P_coord );

               if( Ir_result < Ms_min )Ms_min = Ir_result;
               if( Ms_max < Ir_result )Ms_max = Ir_result;

               Ir_result = (Ir_result - ( -0.65661 ) )/( 0.626277 - (-0.65661 )  );
               //Ir_result = ((int)(Ir_result*5))/5.0;
               return Ir_result;
              }

             static T_scalar Fs_value( int x, int y, int z, T_coord const& P_coord  )
              {
               T_coord I_spike;
               ::math::linear::vector::subtraction( I_spike, P_coord, {T_scalar(x),T_scalar(y),T_scalar(z)} );

               T_coord const& I_lattice = Fs_table( x, y, z );
               return ::math::linear::vector::dot( I_spike, I_lattice );
             }

             static T_coord const& Fs_table( int x, int y, int z )
              {
               if( x < 0 ) { x = (int)(M2s_table.F_size()[0] - T_size(- x)%M2s_table.F_size()[0]); }
               if( y < 0 ) { y = (int)(M2s_table.F_size()[1] - T_size(- y)%M2s_table.F_size()[1]); }
               if( z < 0 ) { z = (int)(M2s_table.F_size()[2] - T_size(- z)%M2s_table.F_size()[2]); }
               return M2s_table[{ T_size(x)%M2s_table.F_size()[0], T_size(y) %M2s_table.F_size()[1], T_size(z) %M2s_table.F_size()[2] } ];
             }

             T_size   M2_iteration;
             T_scalar M2_scale;
             T_scalar M2_coefficient;
             static bool F2s_init();
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
