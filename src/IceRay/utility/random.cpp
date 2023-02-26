#include "./random.hpp"
#include <iostream>
#include <iomanip>

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
           bool Is_a = F2s_fill( );
           bool Is_b = F2s_init( M2_table.data(), M2_table.size() );
           M2_counter = 0;
           ++M2_size;
          }

         void GC_table1D::Fs_next()
          {
          }

         bool GC_table1D::F2s_fill()
          {
           std::cout << "0000000000" << __FILE__ << " - "<< __FUNCTION__ << " _ " << M2_size << std::endl; 
           M2_table.resize( M2_size );
           for( T_size i = 0; i < M2_table.size(); ++i )
            {
             M2_table[i] = i;
            }
            return true;
          }

         bool GC_table1D::F2s_init( T_scalar *P_begin, T_size const& P_size )
          {
           if( 0 == P_size ) return true;
           if( 1 == P_size ) return true;
           if( 2 == P_size ) return true;

           F2s_init( P_begin, P_size/2+ (P_size%2) );

           F2s_init(    P_begin + P_size/2+ (P_size%2), P_size/2 );
           Fs_reverse( P_begin + P_size/2+ (P_size%2), P_size/2 );

           Fs_riffle( P_begin , P_size  );
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

        }
      }
    }
  }
