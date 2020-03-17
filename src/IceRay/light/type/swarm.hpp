#ifndef Dh_DDMRM_IceRay_light_type_swarm_HPP_
 #define Dh_DDMRM_IceRay_light_type_swarm_HPP_

// GS_DDMRM::S_IceRay::S_light::S_type::GT_swarm

 #include <vector>

#include "./spot.hpp"
#include "./size.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {
       namespace S_type
        {


         class GC_swarm
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_size T_size;

             typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot T_value, T_spot;

             typedef std::vector<GC_spot> T_container;

             GC_swarm( )
              {
               this->M_size=0; 
              }

             void F_push( T_spot const& P_spot )
              {
               if( this->F_capacity() == M_size ) 
                {
                   this->F_reserve( this->F_capacity() + 1 ); 
                }
               this->M2_container[M_size] = P_spot; 
               ++this->M_size;
              }

             void F_pop()
              {
               if( 0 != M_size )
                {
                 --M_size;
                } 
              }

             void F_clear(){ M_size = 0; }
             T_size const& F_size()const{ return M_size; }
             void F_size( T_size const& P_size )
              {
               T_size I_size = std::max( { P_size, M_size, M2_container.size() } );
               M2_container.resize( I_size ); 
               M_size = P_size; 
              }

             T_size const F_capacity( )const
              {
               return M2_container.size();
              }

             void F_reserve( T_size const& P_reserve )
              {
               if( M2_container.size() < P_reserve )
                {
                 M2_container.resize( P_reserve );
                }
              }

             T_spot const& operator[]( T_size const& P_index )const{ return M2_container[P_index]; }
             T_spot      & operator[]( T_size const& P_index )     { return M2_container[P_index]; }

             T_spot const& F_front()const{ return M2_container[0]; }
             T_spot      & F_front()     { return M2_container[0]; }

             T_spot const& F_back()const{ return M2_container[M_size-1]; }
             T_spot      & F_back()     { return M2_container[M_size-1]; }

           public:
            T_container const& F_container()const{ return M2_container; };

           private:
             T_container M2_container;
             T_size M_size;
          };

         typedef GC_swarm   GT_swarm;

         inline auto begin(  GS_DDMRM::S_IceRay::S_light::S_type::GC_swarm const& P_swarm ){ return P_swarm.F_container().begin(); }
         inline auto end(    GS_DDMRM::S_IceRay::S_light::S_type::GC_swarm const& P_swarm ){ return P_swarm.F_container().begin() + P_swarm.F_size(); }
  
        }
      }
    }
  }


#endif
