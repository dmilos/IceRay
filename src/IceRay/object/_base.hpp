#ifndef Dh_DDMRM_Iceray_object__pure__base_HPP_
 #define Dh_DDMRM_Iceray_object__pure__base_HPP_

// GS_DDMRM::S_IceRay::S_object::S__pure::GC__base

 #include "../type/ray/state.hpp"

 #include "../geometry/_type/state.hpp"

 #include "../geometry/_pure/intersect.hpp"
 #include "../geometry/_pure/normal.hpp"

 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_object
      {
       namespace S__pure
        {

         class GC__base
          : public GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect
          , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                T_size;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar     T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     T_coord;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base      T_geometry;
             typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure     T_medium;
             typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure    T_pigment;
             typedef GS_DDMRM::S_IceRay::S_material::GC__pure               T_material;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state    T_state;
             typedef GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC__beam T_beam;

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect     T_intersect;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal        T_normal   ;

           public:
                      GC__base(){}
             virtual ~GC__base(){}
          };

        }
      }
    }
  }

#endif