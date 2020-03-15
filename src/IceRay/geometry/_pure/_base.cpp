#include "./_base.hpp"


using namespace GS_DDMRM::S_IceRay::S_geometry::S__pure;

GC__base::T_size GC__base::M2s_counter=0; //!< Zero is reserved for NO object.


GC__base::GC__base()
 {
  M2s_counter++;
  M2_ID = M2s_counter;
  F_box( ::math::linear::vector::fill( T_coord{}, 0 ), ::math::linear::vector::fill( T_coord{}, 0 ) );
 }

GC__base::GC__base( T_box const& P_box )
 :M2_box( P_box )
 {
 }

GC__base::~GC__base()
 {
 }

