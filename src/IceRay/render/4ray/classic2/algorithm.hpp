#ifndef Dh_DDMRM_Iceray_render_ray_classic2_HPP_
 #define Dh_DDMRM_Iceray_render_ray_classic2_HPP_
//GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::GC_algorithm

 #include "../../../geometry/_type/state.hpp"
 #include "../../../type/basic/scalar.hpp"
 #include "../../../type/ray/simple.hpp"
 #include "../../../type/ray/trace.hpp"
 #include "../../../type/ray/state.hpp"


 #include "../../../object/_base.hpp"
 #include "../../../object/wrap.hpp"

 #include "../_pure.hpp"

 #include "./stack/implementation.hpp"
 
 #include "IceRay/material/compute/jurisdiction.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_ray
        {
         namespace S_classic2
          {

           class GC_algorithm
            :  public GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar T_coord;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GT_jurisdiction T_jurisdiction;

               typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state       T_state;
               typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__base         T_object;

               typedef GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC_implementation T_stack;

               GC_algorithm( );
               ~GC_algorithm( );

             public:
               void Fv_trace( T_color & P_color, T_ray const& P_incident );

             public:
               T_object const& F_object( )const{ return *M2_object; }
               bool            F_object( T_object * P_object );
             protected:
               T_object &      F1_object( ){ return *M2_object; }
             private:
               T_object *M2_object;

             private:
               typedef GS_DDMRM::S_IceRay::S_object::GC_wrap T2_wrap;
               static T2_wrap & Fs_vacuum();

             public:
               T_size const& F_depth( )const{ return M2_depth; }
               bool          F_depth( T_size const& P_depth );
             private:
               T_size M2_depth;

             public:
               T_scalar const& F_trash( )const{ return M2_trash; }
               bool            F_trash( T_scalar const& P_trash );
             private:
               T_scalar M2_trash;

             public:
               T_stack & F_stack(){ return M2_stack; }
             private:
               T_stack M2_stack;

             private:
               typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace        T2_ray;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar T2_gray;
               void F2_trace( T_color &P_color );

             private:
               typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GT_allocator   T_allocator;
               T_allocator M2_allocator;
             private:
               struct C_statistic
                {
                 T_size M_traced=0;
                 T_size M_discarded=0;
                 T_size M_light=0;
                 T_size M_eye=0;
                 T_size M_reflected=0;
                 T_size M_teleported=0;
                 T_size M_refracted=0;
                 T_size M_broken=0;
                 T_size M_2far=0;
                 T_size M_2deep=0;
                 T_size M_under=0;
                 T_size M_miss=0;
                 std::vector<T_size> M_depth;
                }M2_statistic;
            };
         }
       }
     }
   }
 }

#endif
