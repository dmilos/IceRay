#include <cmath>
#include "./chandelier.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;




GC_chandelier::GC_chandelier( )
 {
 }

GC_chandelier::GC_chandelier( T_container const& P_container )
 : M2_container( P_container )
 {
 }

GC_chandelier::~GC_chandelier()
 {
 }

void GC_chandelier::F_add( T__pure* P_light )
 {
  M2_container.push_back( P_light );
  this->F1_max() += P_light->F_max();
 }

GC_chandelier::T_size
GC_chandelier::Fv_swarm
 (
  T_swarm      & P_swarm
 ,T_coord const& P_point
 )const
 {
  T_size Ir_size = 0;
  for( auto const & I_light : M2_container )
   {
    Ir_size += I_light->Fv_swarm( P_swarm, P_point );
   }
  return Ir_size;
 }



