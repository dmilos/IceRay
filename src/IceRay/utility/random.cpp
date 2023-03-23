#include "./random.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_random
        {

         GC_table1D::T_size  GC_table1D::M2_size = 1;
         GC_table1D::T_table GC_table1D::M2_table;

         GC_table1D::GC_table1D()
          {
           static bool Is_a = F2s_fill( );
           static bool Is_b = F2s_init( M2_table.data(), M2_table.size() );
           M2_counter = 0;
          }

         void GC_table1D::Fs_size( T_size const& P_size )
          {
           M2_size = P_size;
           F2s_fill( );
           F2s_init( M2_table.data(), M2_table.size() );
          }

         bool GC_table1D::F2s_fill()
          {
           std::cout << "0000000000" << __FILE__ << " - "<< __FUNCTION__<< "("<< __LINE__ << "): size: " << M2_size << std::endl;
           M2_table.resize( M2_size );
           for( T_size i = 0; i < M2_table.size(); ++i )
            {
             M2_table[i] = (T_scalar)i;
            }
            return true;
          }

         bool GC_table1D::F2s_init( T_scalar *P_begin, T_size const& P_size )
          {
           if( 0 == P_size ) return true;
           if( 1 == P_size ) return true;
           if( 2 == P_size ) return true;

           F2s_init(   P_begin, P_size/2  );
           F2s_init(   P_begin + P_size/2+ (P_size%2), P_size/2 );
           Fs_reverse( P_begin + P_size/2+ (P_size%2), P_size/2 );
           Fs_riffle(  P_begin , P_size  );
           return true;
          }

         void GC_table1D::Fs_reverse( T_scalar *P_begin, T_size const& P_size )
          {
           std::reverse( P_begin, P_begin + P_size );
          }
         void GC_table1D::Fs_riffle( T_scalar *P_begin, T_size const& P_size )
          {
           std::vector<T_scalar> I_left( P_begin, P_begin + P_size/2 + (P_size%2) );
           std::vector<T_scalar> I_right( P_begin + P_size/2 + (P_size%2),  P_begin + P_size );

           for( T_size i=0; i < I_left.size(); ++i )
            {
             P_begin[2*i] = I_left[i];
            }
           for( T_size i=0; i < I_right.size(); ++i )
            {
             P_begin[2*i+1] = I_right[i];
            }
          }


          GC_poisson1D::T_table GC_poisson1D::M2_table;

          GC_poisson1D::GC_poisson1D()
           {
            static bool i = F2s_init( 255 );
            M2_counter = 0;
           }

          bool GC_poisson1D::F2s_init( T_size const& P_size )
           {
            T_table I_tmp;
            I_tmp.resize( P_size );
            M2_table.clear();
            M2_table.reserve( P_size );
            M2_table.push_back( 0 );
            M2_table.push_back( 1 );

            while( M2_table.size() < P_size )
             {
              if( 0 == ( M2_table.size() %2 ) )
               {
                M2_table.push_back( rand()/(T_scalar)(RAND_MAX) );
                continue;
               }
              std::memcpy( I_tmp.data(), M2_table.data(), M2_table.size() * sizeof( T_scalar ) );
              std::sort( I_tmp.begin(), I_tmp.begin() + M2_table.size() );
              T_scalar I_max = I_tmp[0+1] - I_tmp[0];
              T_scalar I_new = (I_tmp[0]+I_tmp[1])/2;
              for( T_size I_index=0; I_index < M2_table.size() -1; ++I_index )
               {
                if( I_max < ( I_tmp[I_index+1] - I_tmp[I_index] ) )
                 {
                  I_max = I_tmp[I_index+1] - I_tmp[I_index];
                  I_new = (I_tmp[I_index+1] + I_tmp[I_index])/2;
                 }
               }
              M2_table.push_back( I_new );
             }
            return true;
           }


        }

      }
    }
  }
