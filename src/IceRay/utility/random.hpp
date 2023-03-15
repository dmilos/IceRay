#ifndef Dh_DDMRM_Iceray_utility_random_HPP_
 #define Dh_DDMRM_Iceray_utility_random_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D
 // GS_DDMRM::S_IceRay::S_utility::S_random::GC_standard1D
 // GS_DDMRM::S_IceRay::S_utility::S_random::GC_standard2D
 // GS_DDMRM::S_IceRay::S_utility::S_random::GT_vdc2
 // GS_DDMRM::S_IceRay::S_utility::S_random::GT_sobol1D
 // GS_DDMRM::S_IceRay::S_utility::S_random::GT_sobol2D
 // GS_DDMRM::S_IceRay::S_utility::S_random::GT_congurent1D
 // GS_DDMRM::S_IceRay::S_utility::S_random::GT_congurent2D
 // GS_DDMRM::S_IceRay::S_utility::S_random::GT_congurent3D


#include "math/math.hpp"
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


          template< typename N_random >
           void GF_polar2D
            (
              GS_DDMRM::S_IceRay::S_type::GT_scalar & P_x
             ,GS_DDMRM::S_IceRay::S_type::GT_scalar & P_y
             ,N_random & P_random = N_random()
            )
            {
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar  Tf_scalar;

             Tf_scalar I_r;
             Tf_scalar I_t;
             P_random( I_r, I_t );

             P_x = I_r * cos( I_t * 2 * ::math::constants::PHI );
             P_y = I_r * sin( I_t * 2 * ::math::constants::PHI );
            }

          class GC_standard1D
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
            public:
              T_scalar operator()()
               {
                return this->next();
               }

            public:
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

            public:
              void operator()( T_coord2D & P_coord )
               {
                this->operator()(P_coord[0], P_coord[1] );
               }

            public:
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

            public:
              GC_gold1D():M2_position(0){}

            public:
              void operator()( T_scalar & P_x )
               {
                P_x = this->next();
               }

            public:
              T_scalar next()
               {
                return fmod( ++M2_position * ( ::math::constants::GOLD_inv ), T_scalar(1) );
               }

            private:
              T_size M2_position;
           };

          class GC_table1D
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;
              typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
              typedef std::vector<T_scalar> T_table;

            public:
              GC_table1D();
              T_scalar operator()()
               {
                return this->next();
               }

            public:
              T_scalar next()
               {
                return M2_table[ ++M2_counter % M2_table.size() ] / T_scalar(M2_table.size() -1 );
               }

            public:
              static void Fs_size( T_size const& P_size );
            private:
              static bool F2s_fill( );
              static bool F2s_init(   T_scalar *P_begin, T_size const& P_size );
              static void Fs_reverse( T_scalar *P_begin, T_size const& P_size );
              static void Fs_riffle(  T_scalar *P_begin, T_size const& P_size );
              T_size M2_counter;
              static T_size  M2_size;
              static T_table M2_table;
           };

          class GC_table2D
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;
              typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
              typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D T_coord2D;
              typedef std::vector<T_coord2D> T_table;

            public:
              GC_table2D(){  M2_counter = 0; }
              T_coord2D const& operator()()
               {
                return this->next();
               }

            public:
              void operator()( T_coord2D & P_coord )
               {
                P_coord =  next();
               }

            public:
              T_coord2D const& next()
               {
                return M2_table[ ++M2_counter % M2_table.size() ];
               }

              T_table const& F_table()const
               {
                return M2_table;
               }

              T_table & F_table()
               {
                return M2_table;
               }

            private:
              T_size  M2_counter;
              T_table M2_table;
           };

          class GC_poisson1D
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;
              typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
              typedef std::vector<T_scalar> T_table;
            public:
              GC_poisson1D();
            public:
              T_scalar operator()()
               {
                return this->next();
               }

            public:
              T_scalar next()
               {
                return M2_table[ ++M2_counter % M2_table.size() ];
               }

            private:
              static bool F2s_init( T_size const& P_size );
              T_size  M2_counter;
              static T_table M2_table;
           };



          typedef ::math::random::vdc< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_size, 2 > GT_vdc2;
          typedef ::math::random::vdc< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_size, 3 >  GT_vdc3;
          typedef ::math::random::vdc< GS_DDMRM::S_IceRay::S_type::GT_scalar, GS_DDMRM::S_IceRay::S_type::GT_size, 10 > GT_vdc10;

        //typedef ::math::random::VaPND<GS_DDMRM::S_IceRay::S_type::GT_scalar,  GS_DDMRM::S_IceRay::S_type::GT_size, 2> GT_VaPND;
          typedef ::math::random::VaLND<GS_DDMRM::S_IceRay::S_type::GT_scalar,  GS_DDMRM::S_IceRay::S_type::GT_size, 2> GT_VaLND;

          typedef ::math::random::sobol1D< GS_DDMRM::S_IceRay::S_type::GT_scalar > GT_sobol1D;
          typedef ::math::random::sobol2D< GS_DDMRM::S_IceRay::S_type::GT_scalar > GT_sobol2D;

          typedef ::math::random::congruent< GS_DDMRM::S_IceRay::S_type::GT_scalar, 1 > GT_congruent1D;
          typedef ::math::random::congruent< GS_DDMRM::S_IceRay::S_type::GT_scalar, 2 > GT_congruent2D;
          typedef ::math::random::congruent< GS_DDMRM::S_IceRay::S_type::GT_scalar, 3 > GT_congruent3D;

        }
      }
    }
  }

#endif
