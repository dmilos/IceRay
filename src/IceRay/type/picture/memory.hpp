#ifndef Dh_DDMM_IceRay_type_picture_memory_HPP_
 #define Dh_DDMM_IceRay_type_picture_memory_HPP_

 //GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory

 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_picture
        {

         class GC_memory
          : public GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_report          T_report;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_char   T_color;
             typedef GS_DDMRM::S_IceRay::S_type::GT_size            T_size;

             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D T_coord;

             GC_memory(){ this-> Fv_size({1,1}); }
             GC_memory( T_size const& P_width, T_size const& P_height ){ this-> Fv_size( T_coord{ P_width, P_height } ); }
             GC_memory( T_coord const& P_size ){ this-> Fv_size(P_size); }

             virtual T_report Fv_pixel( T_color & P_color, T_coord const& P_coord )const
              {
               P_color = M2_data[ P_coord[1] * F_size()[0] + P_coord[0] ];
               return true;
              }

             virtual T_report Fv_pixel( T_coord const& P_coord, T_color const& P_color )
              {
               M2_data[ P_coord[1] * F_size()[0] + P_coord[0] ] = P_color;
               return true;
              }

             virtual T_report Fv_size( T_coord const& P_size )
              {
               this->F1_size() = P_size;
               M2_data.resize( P_size[0] * P_size[1]);
               return true;
              }

             virtual T_color const* Fv_data(  )const
              {
               return M2_data.data();
              }

           private:
             std::vector<T_color> M2_data;
          };

        }
      }
    }
  }

#endif
