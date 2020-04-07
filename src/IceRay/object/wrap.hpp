#ifndef Dh_DDMRM_Iceray_object_wrap_HPP_
 #define Dh_DDMRM_Iceray_object_wrap_HPP_

// GS_DDMRM::S_IceRay::S_object::GC_wrap

#include "./_base.hpp"

 #include "../geometry/_pure/inside.hpp"
 #include "../geometry/_pure/distance.hpp"
 #include "../geometry/_pure/uvw.hpp"
 #include "../geometry/_pure/cluster.hpp"

#include "../material/medium/_pure.hpp"
#include "../material/pigment/_base.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_object
      {

       // implement next ray logic and stops inheriting
       class GC_wrap
        : public GS_DDMRM::S_IceRay::S_object::S__pure::GC__base
        , public GS_DDMRM::S_IceRay::S_material::S_pigment::GC__base
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance
        , public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_size                T_size;
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     T_coord;
           typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar     T_color;

           typedef GS_DDMRM::S_IceRay::S_material::GT_beam            T_beam;

           typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state   T_state;

           typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure           T_object;
           typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base         T_geometry;
           typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_cluster       T_cluster;

           typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__base T_pigmentBase;

           typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect     T_intersect;
           typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal        T_normal   ;
           typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside        T_inside   ;
           typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance      T_distance ;
           typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw           T_uvw      ;

           typedef GS_DDMRM::S_IceRay::S_object::GC_wrap     T_wrap;

         public:
                    GC_wrap();
           explicit GC_wrap( T_geometry * P_geometry );
           explicit GC_wrap( T_geometry * P_geometry,  T_pigment * P_pigment );
           explicit GC_wrap( T_geometry * P_geometry,  T_pigment * P_pigment, T_medium * P_medium );

           ~GC_wrap();

         public:
           bool           Fv_color( T_color & P_color, T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const;
           using T_pigmentBase::Fv_maxNextRays;
           using T_pigmentBase::F_maxRayPerHit;
         protected:
           using T_pigmentBase::F1_maxRayPerHit;

         public:
            bool Fv_attenuate( T_color & P_result, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )const;

         public:
           void               Fv_reset( T_state &P_intersect )const;
           T_size             Fv_weight( )const;
         public:
           bool        Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_intersect::T_ray  const& P_ray )const;
           void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point,  T_state const& P_state )const;
           T_location  Fv_inside(    T_coord const& P_point/*, T_state &P_state */ )const;
           T_scalar    Fv_distance(  T_coord const& P_point )const;
           bool        Fv_uvw(       T_coord & P_uvw, T_coord const& P_point, T_state const& P_state)const;

         public:
           T_pigment *  F_pigment()const{ return M2_pigment; }
           bool         F_pigment( T_pigment * P_pigment );
         private:
           T_pigment *   M2_pigment;
         protected:
           static T_pigment & F1s_pigment();

         public:
           T_medium *  F_medium()const{ return M2_medium; }
           bool        F_medium( T_medium * P_medium );
         private:
           T_medium *   M2_medium;
         private:
           static T_medium & F1s_medium();

         public:
           T_geometry * F_geometry(){ return M2_geometry; }
           bool         F_geometry( T_geometry * P_geometry );
         private:
           T_geometry *M2_geometry; //!< dumb_ptr;
         private:
           static T_geometry  & F1s_geometry();

         private:
           struct C2_geometry //!< child geometry
            {
             T_geometry  *M2_geometry ;
             T_intersect *M2_intersect;
             T_normal    *M2_normal   ;
             T_inside    *M2_inside   ;
             T_distance  *M2_distance ;
             T_uvw       *M2_uvw      ;
             T_cluster   *M2_cluster  ;
            };

           T_intersect *M2_intersect;
           T_normal    *M2_normal   ;
           T_inside    *M2_inside   ;
           T_distance  *M2_distance ;
           T_uvw       *M2_uvw      ;
           T_cluster   *M2_cluster  ;  //!< dumb_ptr;

          C2_geometry M2_whatever;
         private:
           struct C2_marble
            {
             T_pigment *M_pigment;
             T_medium  *M_medium;
            };
           typedef  std::vector< C2_marble > T2_marbles;
           T2_marbles M2_marbles;

        };

      }
    }
  }

#endif
