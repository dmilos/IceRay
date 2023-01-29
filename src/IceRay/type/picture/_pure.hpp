#ifndef Dh_DDMM_IceRay_type_picture__pure_HPP_
 #define Dh_DDMM_IceRay_type_picture__pure_HPP_

 //GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure

 #include "../math/coord.hpp"
 #include "../color.hpp"
 #include "../basic/report.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_picture
        {

         class GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_report          T_report;
             typedef GS_DDMRM::S_IceRay::S_type::GT_size            T_size;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_char   T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D T_coord;

             virtual T_report Fv_pixel( T_color      & color, T_coord const& coord )const=0;
             virtual T_report Fv_pixel( T_coord const& coord, T_color const& color )=0;

             virtual T_coord const& F_size(  )const{ return M2_size; }
             virtual T_report Fv_size( T_coord const& P_size )=0;

             virtual T_color const* Fv_data()const=0;

           public:
                      GC__pure():M2_size{1,1}{ }
             virtual ~GC__pure(){ }

           protected:
             T_coord & F1_size()
              {
               return M2_size;
              }

           private:
             T_coord M2_size;
          };

        }
      }
    }
  }

#endif
