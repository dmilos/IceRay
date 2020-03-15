#include "./table.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;

S_hfield::S_generator::GC_table::GC_table( )
 {

 }

S_hfield::S_generator::GC_table::GC_table( T_field const& P_field )
 :T__pure( P_field.size(), P_field[0].size()  )
 ,M2_field(P_field)
 {
 }

S_hfield::S_generator::GC_table::T_scalar S_hfield::S_generator::GC_table::Fv_value( T_size const& P_y, T_size const& P_x )const
 {
  return M2_field[P_y][P_x];
 }

S_hfield::S_generator::GC_table::T_scalar S_hfield::S_generator::GC_table::Fv_value( T_coord const& P_position )const
 {
  return M2_field[P_position[1]][P_position[0]];
 }
