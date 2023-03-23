#ifndef Dh_IceRay_material_pattern_noise_cells_hpp_
 #define Dh_IceRay_material_pattern_noise_cells_hpp_

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

         class GC_cells
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;


             GC_cells()
              {
               static auto dummy = F2s_init();
              }

           public:
             void  Fv_process( T_result &P_result, T_coord const& P_coord )const
              {
               int x = (int)floor( P_coord[0] );
               int y = (int)floor( P_coord[1] );
               int z = (int)floor( P_coord[2] );

               P_result = Fs_table( x, y, z );
              }

           private:
             static T_scalar Fs_table( int x, int y, int z )
               {
               if( x < 0 ) { x = (int)( M2s_table.F_size()[0] - T_size(-x)%M2s_table.F_size()[0] ); }
               if( y < 0 ) { y = (int)( M2s_table.F_size()[1] - T_size(-y)%M2s_table.F_size()[1] ); }
               if( z < 0 ) { z = (int)( M2s_table.F_size()[2] - T_size(-z)%M2s_table.F_size()[2] ); }
               return M2s_table[ { x%M2s_table.F_size()[0], y%M2s_table.F_size()[1], z%M2s_table.F_size()[2] } ][0];
              }

             static bool F2s_init()
              {
               M2s_table.F_size({10,10,10});
               return true;
              }
             static GS_DDMRM::S_IceRay::S_utility::S_table::GC_value<3,1>  M2s_table;
           };

          }
        }
      }
    }
  }

#endif
