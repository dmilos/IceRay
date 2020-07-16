#ifndef Dh_DDMRM_Iceray_utilityt_tile_HPP_
 #define Dh_DDMRM_Iceray_utilityt_tile_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_tile::GC_tile

#include "IceRay/type/math/coord.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_mapping
        {

         template < unsigned N_dimesion, unsigned N_type >
          class GC_tile
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
              typedef typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< T_scalar,N_dimesion >::T_typedef T_coord;

              T_coord   operator()( T_scalar const&P_value )const
               {
                for( decltype(N_type) I_coord=0; I_coord < N_dimesion; ++I_coord )
                 {
                  switch( (  N_type >> ( 2*I_coord ) ) & 3 )
                   {
                    case( 0 ): ::math::function::ramp(     P_value ); break;
                    case( 1 ): ::math::function::saw(      P_value ); break;
                    case( 2 ): ::math::function::wave(     P_value ); break;
                    case( 3 ): ::math::function::sinkhole( P_value ); break;
                   }
                 }
               }
           };

        }
      }
    }
  }

#endif
