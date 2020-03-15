#ifndef Dh_DDMRM_Iceray_material_compute_surface_HPP_
 #define Dh_DDMRM_Iceray_material_compute_surface_HPP_

 //GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface

 #include "../../type/basic/size.hpp"
 #include "../_pure.hpp"
 #include "./processor.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {

         class GC_surface
          : public GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                     T_size;

             typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure            T_pigment;

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction T_instruction;
             typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_processor   T_processor;
             typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory      T_memory;

             enum Ee_input
              {
               En_inCoord_Point=0, En_inCoord_Normal=1,
               En_inScalar_Lambda  = 0,
               En_inRay_Incoming=0
              };
             enum Ee_output
             {
               En_outColor_Result=0
             };

           public:
             GC_surface()
              {
               M2_scalar = dynamic_cast< T2_scalar*> (  M2_pocessor.F_memory().F_get( T_memory::En_scalar  ) );
               M2_color  = dynamic_cast< T2_color *> (  M2_pocessor.F_memory().F_get( T_memory::En_color   ) );
               M2_coord  = dynamic_cast< T2_coord *> (  M2_pocessor.F_memory().F_get( T_memory::En_coord   ) );
             //M2_ray    = dynamic_cast< T2_ray   *> (  M2_pocessor.F_memory().F_get( T_memory::En_ray     ) );
              }

           public:
             bool Fv_color( T_color & P_color, T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
             {
              M2_scalar->Fv_store( En_inScalar_Lambda, P_intersect.M_intersection.M_lambda );
              M2_coord->Fv_store(  En_inCoord_Point,   P_intersect.M_intersection.M_point  );
              M2_coord->Fv_store(  En_inCoord_Normal,  P_intersect.M_intersection.M_normal );
            //M2_color->Fv_store(  En_inRay_Incoming,  P_intersect.M_ray    );
            //M2_color->Fv_store(  En_outColor_Result, ::color:constant::black_t{} );

              if( false == M2_pocessor.Fv_execute( P_next, P_intersect, P_state ) )
               {
                return false;
               }

              P_color = M2_color->Fv_load( En_outColor_Result );
              return true;
             }

            T_size const& Fv_maxNextRays()const
             {
              return M2_pocessor.F_memory().F_get( T_memory::En_ray )->Fv_size();
             }

           public:

             void F_insert( T_size const& P_index, T_instruction * P_instruction  )
              {
               F_pocessor().F_insert( P_index, P_instruction );
              }

             void F_set( T_size const& P_index, T_instruction * P_instruction)
              {
               F_pocessor().F_set( P_index, P_instruction );
              }

             void F_append( T_instruction * P_instruction )
              {
                F_pocessor().F_append( P_instruction );
              }

           public:
             T_processor  const& F_pocessor()const{ return M2_pocessor; }
             T_processor       & F_pocessor()     { return M2_pocessor; }
           protected:
             T_processor        & F1_pocessor(){ return M2_pocessor; }
           private:
             T_processor M2_pocessor;

           private:
             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_scalar> T2_scalar;
             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_color>  T2_color;
             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord > T2_coord;
             T2_scalar *M2_scalar;
             T2_color  *M2_color;
             T2_coord  *M2_coord;
          };


        }
      }
    }
  }

#endif