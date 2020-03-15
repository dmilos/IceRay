#ifndef Dh_DDMRM_Iceray_material_medium_pattern_HPP_
 #define Dh_DDMRM_Iceray_material_medium_pattern_HPP_

 #include "./_pure.hpp"
 #include "../pattern/_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_medium
        {

         class GC_pattern
          : public GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__coord4D T_function;

                      GC_pattern()
                       {
                       }

             explicit GC_pattern( T_function *P_function )
                       : M2_function( P_function )
                       {
                       }

             virtual ~GC_pattern(){ ; }

             virtual bool Fv_attenuate( T_color & P_color, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )const
              {
               T_coord3D I_direction; ::math::linear::vector::subtraction( I_direction, P_end, P_start );

               auto I_length = ::math::linear::vector::length( I_direction );
               auto I_stepS = I_length / M2_sample;

               if( I_stepS < M2_minStep )
                {
                 I_stepS = M2_minStep;
                }

               if( M2_maxStep < I_stepS )
                {
                 I_stepS = M2_maxStep;
                }
               T_coord3D I_stepV;
               ::math::linear::vector::scale( I_stepV, I_stepS, I_direction );

               T_size I_sample = I_length / I_stepS;
               if( M2_sample < I_sample )
                {
                 I_sample = M2_sample;
                }

               T_coord4D I_summae; ::math::linear::vector::fill( I_summae, 0 );
               T_coord4D I_value;
               T_coord3D I_position;
               for( T_size I_index=0; I_index < I_sample; ++ I_index )
                {
                 M2_function->Fv_process( I_value, I_position );
                 ::math::linear::vector::addition( I_summae, I_value );
                 ::math::linear::vector::addition( I_position, I_stepV );
                }

               P_deplete = T_gray({I_summae[3]});
               P_color[0]=I_summae[0];
               P_color[1]=I_summae[1];
               P_color[2]=I_summae[2];
               return true;
             }

           public:
             bool              F_function( T_function * P_function ){ M2_function = P_function; return true; }
           protected:
           private:
             T_function* M2_function;

             //trash
             T_scalar M2_sample;
             T_size M2_minStep;
             T_size M2_maxStep;

          };

        }
      }
    }
  }

#endif
