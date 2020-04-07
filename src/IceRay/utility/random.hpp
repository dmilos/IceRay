#ifndef Dh_DDMRM_Iceray_utility_random_HPP_
 #define Dh_DDMRM_Iceray_utility_random_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D
 // GS_DDMRM::S_IceRay::S_utility::S_random::GC_standard1D
 // GS_DDMRM::S_IceRay::S_utility::S_random::GC_standard2D
 // GS_DDMRM::S_IceRay::S_utility::S_random::GT_vdc2
 // GS_DDMRM::S_IceRay::S_utility::S_random::GT_sobol1D
 // GS_DDMRM::S_IceRay::S_utility::S_random::GT_sobol2D


#include "math/random/random.hpp"
#include "IceRay/type/math/coord.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_random
        {

         template< typename N_random >
          void GF_disc2D
           (
             GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D & P_coord
            ,N_random & P_random = N_random() 
           )
           {
            typedef GS_DDMRM::S_IceRay::S_type::GT_scalar Tf_scalar;
            Tf_scalar & I_x = P_coord[0];
            Tf_scalar & I_y = P_coord[1];
            do
             {
              P_random( P_coord );
              I_x = Tf_scalar(2)*I_x - Tf_scalar(1);
              I_y = Tf_scalar(2)*I_y - Tf_scalar(1);
             }while( Tf_scalar(1)< ( I_x * I_x  +  I_y * I_y ) );
           }

          template< typename N_random >
           void GF_disc2D
            (
              GS_DDMRM::S_IceRay::S_type::GT_scalar & P_x
             ,GS_DDMRM::S_IceRay::S_type::GT_scalar & P_y
             ,N_random & P_random = N_random()
            )
            {
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar  Tf_scalar;
             do
              {
               P_random( P_x, P_y );
               P_x = Tf_scalar(2)*P_x - Tf_scalar(1);
               P_y = Tf_scalar(2)*P_y - Tf_scalar(1);
              }while( Tf_scalar(1)< ( P_x * P_x  +  P_y * P_y ) );
            }

          class GC_standard1D
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
              T_scalar operator()()
               {
                return this->next();
               }

              T_scalar next()
              {
                return rand()/(T_scalar)(RAND_MAX);
              }

           };

          class GC_standard2D
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
              typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D T_coord2D;

              void operator()( T_coord2D & P_coord )
               {
                this->operator()(P_coord[0], P_coord[1] );
               }

              void operator()( T_scalar & P_x, T_scalar & P_y )
               {
                P_x = rand()/(T_scalar)(RAND_MAX);
                P_y = rand()/(T_scalar)(RAND_MAX);
               }

           };

          class GC_gold1D
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;
              typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;

              GC_gold1D():M2_position(0){}

              void operator()( T_scalar & P_x )
               {
                P_x = this->next();
               }

              T_scalar next()
               {
                return fmod( ++M2_position * ::math::constants::GOLD_inv, T_scalar(1) );
               }

               T_size M2_position;
           };


          typedef ::math::random::vdc< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_size, 2 > GT_vdc2;

        //typedef ::math::random::VaPND<GS_DDMRM::S_IceRay::S_type::GT_scalar,  GS_DDMRM::S_IceRay::S_type::GT_size, 2> GT_VaPND;
          typedef ::math::random::VaLND<GS_DDMRM::S_IceRay::S_type::GT_scalar,  GS_DDMRM::S_IceRay::S_type::GT_size, 2> GT_VaLND;

          typedef ::math::random::sobol1D< GS_DDMRM::S_IceRay::S_type::GT_scalar > GT_sobol1D;
          typedef ::math::random::sobol2D< GS_DDMRM::S_IceRay::S_type::GT_scalar > GT_sobol2D;

        }
      }
    }
  }

#endif
