#include "./random.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_random
        {

         //GC_table1D::T_table GC_table1D::M2_table = {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
         //GC_table1D::T_table GC_table1D::M2_table = {  0, 6, 2, 8, 4, 10, 1, 7, 3, 9, 5, 11 };
         //GC_table1D::T_table GC_table1D::M2_table = { 0, 11, 5, 14, 2, 9, 6, 17, 3, 13, 7, 16, 1, 10, 4, 12, 8, 15,  };
         GC_table1D::T_table GC_table1D::M2_table = {
            0, 16,  8, 24,4, 20, 12, 28,2, 18, 10, 26,6, 22, 14, 30,
            1, 17,  9, 25,5, 21, 13, 29,3, 19, 11, 27,7, 23, 15, 31
         };

         // not tested 61=14+14+10+ 7+ 9+ 7+:{ 0, 16, 10, 5, 12, 2, 9, 15, 3, 6, 13, 1, 17, 8, 11, 4, 14, 7,  }
         // not tested 35=12+ 8+ 6+ 4+ 4+ 1+:{ 0, 6, 1, 8, 4, 10, 2, 7, 3, 9, 5, 11,  }

         void GC_table1D::Fs_next()
          {
           //std::next_permutation( M2_table.begin()+1, M2_table.end() );
           //std::random_shuffle( M2_table.begin() + 1, M2_table.end() );
          }

        }
      }
    }
  }
