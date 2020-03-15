#ifndef Dh_DDMM_IceRay_type_math_spline_bezier_HPP_
 #define Dh_DDMM_IceRay_type_math_spline_bezier_HPP_



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_math
        {
         namespace S_spline
          {

           //template< unsigned N_dimension, unsigned N_order >
           class GC_bezier
             {
              typedef T_coord;
              typedef T_uv;

              public:
                GC_bezier(){}

              public:
                bool splitU( T_this & left, T_right, T_uv const& P_center )
                 {

                  return false;
                 }

              bool splitV( T_this & left, T_right, T_uv const& P_center )
               {

                return false;
               }

              public:
                T_interval const& F_box()const{ return M_box; }
                T_uv const& F_lo()const{ return M_lo; }
                T_uv const& F_hi()const{ return M_hi; }

              public:
                T_interval M_box;
                T_uv M_lo, M_hi;
                T_coord M_coefficinet[4][4];


             };

          }
        }
      }
    }
  }

#endif

