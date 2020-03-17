#ifndef Dh_DDMRM_Iceray_material__pure_HPP_
 #define Dh_DDMRM_Iceray_material__pure_HPP_
// GS_DDMRM::S_IceRay::S_material::GC__pure

 #include "./medium/_pure.hpp"
 #include "./pigment/_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {

       class GC__pure
        : public virtual GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure
        , public virtual GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure
        {
         public:
           // Just to resolve ambiguousness
           typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar     T_color;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     T_coord;

           typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure          T_medium;
           typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure         T_pigment;

           typedef GS_DDMRM::S_IceRay::S_material::GC_intersect        T_intersect, T_incident;
           typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state   T_state;

         public:
                    GC__pure(){}
           virtual ~GC__pure(){}

         public:
           using T_medium::Fv_attenuate;
           using T_pigment::Fv_color;

           T_medium  const& F_medium()const
            {
             return *this;
            }

           T_pigment const& F_pigment()const
            {
             return *this;
            }

        };

      }
    }
  }

#endif