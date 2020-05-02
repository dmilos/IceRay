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
             GC_surface
              (
                T_size const& P_result = 0
               ,T_size const& P_lambda = 0
               ,T_size const& P_inCoord_Point  = 0
               ,T_size const& P_inCoord_Normal = 1
              )
              {
               M2_scalar = dynamic_cast< T2_scalar*> (  M2_pocessor.F_memory().F_get( T_memory::En_scalar  ) );
               M2_color  = dynamic_cast< T2_color *> (  M2_pocessor.F_memory().F_get( T_memory::En_color   ) );
               M2_coord  = dynamic_cast< T2_coord *> (  M2_pocessor.F_memory().F_get( T_memory::En_coord   ) );
             //M2_ray    = dynamic_cast< T2_ray   *> (  M2_pocessor.F_memory().F_get( T_memory::En_ray     ) );

               M2_result = P_result;
               M2_lambda = P_lambda;
               M2_point  = P_inCoord_Point;
               M2_normal = P_inCoord_Normal;
              }

           public:
             bool Fv_color( T_color & P_color, T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
             {
              M2_scalar->Fv_store( M2_lambda,   P_intersect.M_intersection.M_lambda );
              M2_coord->Fv_store(  M2_point,    P_intersect.M_intersection.M_point  );
              M2_coord->Fv_store(  M2_normal,   P_intersect.M_intersection.M_normal );
            //M2_color->Fv_store(  M2_incoming, P_intersect.M_ray    );
            //M2_color->Fv_store(  M2_result, ::color:constant::black_t{} );
            //M2_color->Fv_store(  M2_result, P_color );

              if( false == M2_pocessor.Fv_execute( P_next, P_intersect, P_state ) )
               {
                return false;
               }

              P_color = M2_color->Fv_load( M2_result );
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
             T_size  const& F_result()const{ return M2_result; }
             bool           F_result( T_size const& P_result )
              {
               M2_result = P_result;
               return true;
              }

           protected:
             T_size       & F1_result()    { return M2_result; }
           private:
             T_size M2_result;

           public:
             T_size  const& F_lambda()const{ return M2_lambda; }
             bool           F_lambda( T_size const& P_lambda )
              {
               M2_lambda = P_lambda;
               return true;
              }
           protected:
             T_size       & F1_lambda()    { return M2_lambda; }
           private:
             T_size M2_lambda;

           public:
             T_size  const& F_point()const{ return M2_point; }
             bool           F_point( T_size const& P_point )
              {
               M2_point = P_point;
               return true;
              }
           protected:
             T_size       & F1_point()    { return M2_point; }
           private:
             T_size M2_point;

           public:
             T_size  const& F_normal()const{ return M2_normal; }
             bool           F_normal( T_size const& P_normal )
              {
               M2_normal = P_normal;
               return true;
              }
           protected:
             T_size       & F1_normal()    { return M2_normal; }
           private:
             T_size M2_normal;

           public:
             T_processor  const& F_pocessor()const{ return M2_pocessor; }
             T_processor       & F_pocessor()     { return M2_pocessor; }
           protected:
             T_processor      & F1_pocessor()     { return M2_pocessor; }
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