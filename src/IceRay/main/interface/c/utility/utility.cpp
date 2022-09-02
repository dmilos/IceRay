#include "./utility.h"

#include "IceRay/utility/random.hpp"

int IceRayC_Utility_Random_Table_Next( void )
 {
  GS_DDMRM::S_IceRay::S_utility::S_random::GC_table1D::Fs_next();
  return 1;
 }