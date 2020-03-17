#ifndef Dh_DDMRM_Iceray_object__pure__pure_HPP_
 #define Dh_DDMRM_Iceray_object__pure__pure_HPP_

// GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure

 #include "../type/color.hpp"
 #include "../type/basic/size.hpp"
 #include "../type/math/coord.hpp"

 #include "../geometry/_type/state.hpp"
 #include "../geometry/_pure/_base.hpp"

 #include "../material/_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_object
      {
       namespace S__pure
        {
         // Common point of material and geometry
         class GC__pure
          : public virtual GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base
          , public         GS_DDMRM::S_IceRay::S_material::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                T_size;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar     T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     T_coord;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   T_geometry;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state   T_state;

             typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure    T_medium;
             typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure   T_pigment;
             typedef GS_DDMRM::S_IceRay::S_material::GC__pure              T_material;

           public:
                      GC__pure(){}
             virtual ~GC__pure(){}

           public:
             using T_geometry::Fv_reset;
             using T_geometry::Fv_weight;
           public:
             using T_material::Fv_color;
             using T_material::Fv_maxNextRays;

           public:
             T_geometry & F_geometry()
              {
               return *this;
              }

             T_material & F_material()
              {
               return *this;
              }

          };

        }
      }
    }
  }

#endif