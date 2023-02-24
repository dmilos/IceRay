#include <cstring>
#include <string>
#include <map>
#include "./system.h"

extern std::map<std::string,std::string> GI_info;


int  IceRayC_System_First( std::size_t P_capacity, char*P_key )
 {
  auto const & I_key = GI_info.begin()->first;

  if( P_capacity < I_key.size() + 1 )
   {
    return 0;
   }

  memcpy( P_key, I_key.c_str(), I_key.size() );
  P_key[ I_key.size() ] = 0;

  return I_key.size();
 }

int  IceRayC_System_Value( std::size_t P_length, char*P_key, std::size_t P_capacity, char* P_value )
 {
  auto iterator = GI_info.find( P_key );
  if( GI_info.end() == iterator )
   {
    return 0;
   }

  if( P_capacity < iterator->second.size() + 1 )
   {
    return 0;
   }

  memcpy( P_value, iterator->second.c_str(), iterator->second.size() );
  P_value[ iterator->second.size() ] = 0;

  return iterator->second.size();
 }

int  IceRayC_System_Next( std::size_t P_length, char*P_current, std::size_t P_capacity, char* P_next )
 {
  auto iterator = GI_info.find( P_current );
  if( GI_info.end() == iterator )
   {
    return 0;
   }
  ++iterator;
  if( GI_info.end() == iterator )
   {
    return 0;
   }

 if( P_capacity < iterator->first.size() + 1 )
  {
   return 0;
  }

  memcpy( P_next, iterator->first.c_str(), iterator->first.size() );
  P_next[ iterator->first.size() ] = 0;

  return iterator->first.size();
 }
