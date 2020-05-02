#ifndef Dh_DDMRM_Iceray_material_compute_light_generator_HPP_
 #define Dh_DDMRM_Iceray_material_compute_light_generator_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_generator

 #include "../../../light/_pure.hpp"
 #include "../../../light/point.hpp"

 #include "../instruction.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_light
          {

           class GC_generator //!< Put the light in memory.
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:

               typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;

               typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      T_spot;
               typedef GS_DDMRM::S_IceRay::S_light::GC__pure             T_light;

               typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state      T_state;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory      T_memory;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction T_instruction;

               enum Ee_input{  };
               enum Ee_output{ En_outLight_Result = 0 };

             public:

               GC_generator( )
                :GC_generator( nullptr, 0 )
                {
                }

               explicit GC_generator
                (
                  T_light * P_light
                 ,T_size const& P_result = 0
                )
               :M2_light( P_light )
                {
                 F_output<T_light>( En_outLight_Result, P_result );
                }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
                 M2_memoryLight->Fv_store( F_output<T_light>( En_outLight_Result ), M2_light );
                 return true;
                }

             public:  // property light  light
               T_light    const* F_light()const{ return M2_light; }
               bool              F_light( T_light* P_light )
                {
                 M2_light = P_light;
                 if( nullptr == M2_light )
                  {
                   M2_light = &F2s_light();
                  }
                 return true;
                }
             protected:
               T_light         * & F1_light(){ return M2_light; }
             private:
               T_light *M2_light;

             private:
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_light*>   T2_memoryLight;

             public:
               void    Fv_memory( T_memory * P_memory  )
                {
                 T_instruction::Fv_memory( P_memory );
                 M2_memoryLight  = dynamic_cast<T2_memoryLight * >( P_memory->F_get( T_memory::En_light ) );
                }
             private:
               T2_memoryLight    *M2_memoryLight;
             private:
               static T_light & F2s_light()
                {
                 static GS_DDMRM::S_IceRay::S_light::GC_point Is_light;
                 return Is_light;
                }
           };

          }
        }
      }
    }
  }

#endif
