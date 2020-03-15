#ifndef Dh_IceRay_material_pattern_hexagon_hpp_
 #define Dh_IceRay_material_pattern_hexagon_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::S_typeN::GC__pure<N_number>

#include "./_pure.hpp"

#include "../../type/basic/scalar.hpp"
#include "../../type/color.hpp"
#include "../../type/math/coord.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {

         class GC_hexagon
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size
          {// DONE
           public:
             GC_hexagon()
              {
              }

           public:
             void  Fv_process( T_result &P_result, T_coord const& P_coord )const
              {
               static T_scalar Is_height = sqrt(3)/2;
               T_scalar I_x = P_coord[0];
               T_scalar I_y = P_coord[1];
             
               P_result = 0;
               I_x /= 0.5;
               I_y /= Is_height;
             
               if( I_x < 0 ) { I_x = 10 - I_x; } I_x = fmod( I_x, 6 );
               if( I_y < 0 ) { I_y = 6 - fmod(6 - I_y,6); } else{ I_y = fmod( I_y, 6 ); }
             
               if( I_x < 1 )
                { // DONE
                 if( I_y < 1 ) { P_result = 0; if(   I_x < ( I_y-0) ) P_result = 2; goto L_end; }
                 if( I_y < 2 ) { P_result = 2; if( 1-I_x < ( I_y-1) ) P_result = 1; goto L_end; }
                 if( I_y < 3 ) { P_result = 1; if(   I_x < ( I_y-2) ) P_result = 0; goto L_end; }
                 if( I_y < 4 ) { P_result = 0; if( 1-I_x < ( I_y-3) ) P_result = 2; goto L_end; }
                 if( I_y < 5 ) { P_result = 2; if(   I_x < ( I_y-4) ) P_result = 1; goto L_end; }
                 if( I_y < 6 ) { P_result = 1; if( 1-I_x < ( I_y-5) ) P_result = 0; goto L_end; }
                 goto L_end;
                }
             
               if( I_x < 3 )
                { // DONE
                 if( I_y < 1 ) { P_result = 0; goto L_end; }
                 if( I_y < 3 ) { P_result = 1; goto L_end; }
                 if( I_y < 5 ) { P_result = 2; goto L_end; }
                 if( I_y < 6 ) { P_result = 0; goto L_end; }
                 goto L_end;
                }
             
               if( I_x < 4 )
                {
                 if( I_y < 1 ) { P_result = 0; if( 1-  (I_x-3) < ( I_y-0) ) P_result = 2; goto L_end; }
                 if( I_y < 2 ) { P_result = 2; if(     (I_x-3) < ( I_y-1) ) P_result = 1; goto L_end; }
                 if( I_y < 3 ) { P_result = 1; if( 1-  (I_x-3) < ( I_y-2) ) P_result = 0; goto L_end; }
                 if( I_y < 4 ) { P_result = 0; if(     (I_x-3) < ( I_y-3) ) P_result = 2; goto L_end; }
                 if( I_y < 5 ) { P_result = 2; if( 1-  (I_x-3) < ( I_y-4) ) P_result = 1; goto L_end; }
                 if( I_y < 6 ) { P_result = 1; if(     (I_x-3) < ( I_y-5) ) P_result = 0; goto L_end; }
                 goto L_end;
                }
             
               if( I_x < 6 )
                { // DONE
                 if( I_y < 2 ) { P_result = 2; goto L_end; }
                 if( I_y < 4 ) { P_result = 0; goto L_end; }
                 if( I_y < 6 ) { P_result = 1; goto L_end; }
             
                 goto L_end;
                }
              L_end:;
            }

          };

        }
      }
    }
  }

#endif
