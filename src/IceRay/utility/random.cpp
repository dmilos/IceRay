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
         //GC_table1D::T_table GC_table1D::M2_table = {  0, 10, 1, 11, 2, 12, 3, 13, 4, 14, 5, 15, 6, 16, 7, 17, 8, 18, 9, 19 };

         GC_table1D::T_table GC_table1D::M2_table = { 
           0, 10, 20, 
           1, 11, 21, 
           2, 12, 22, 
           3, 13, 23, 
           4, 14, 24, 
           5, 15, 25, 
           6, 16, 26, 
           7, 17, 27, 
           8, 18, 28, 
           9, 19, 29
        }; 


          void GC_table1D::Fs_next()
           {
            std::next_permutation( M2_table.begin()+1, M2_table.end() );
            //std::random_shuffle( M2_table.begin() + 1, M2_table.end() );
           }

        }
      }
    }
  }
