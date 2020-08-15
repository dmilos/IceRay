#ifndef Dh_DDMM_IceRay_type_integer_HPP_
 #define Dh_DDMM_IceRay_type_integer_HPP_
// GS_DDMRM::S_IceRay::S_type::GT_integer


 #include <cstddef>
 #include <cstdint>


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {

       typedef std::uint8_t   GT_uint8;
       typedef std::int8_t    GT_int8;

       typedef std::uint16_t   GT_uint16;
       typedef std::int16_t    GT_int16;

       typedef std::uint32_t   GT_uint32;
       typedef std::int32_t    GT_int32;

       typedef std::uint64_t   GT_uint64;
       typedef std::int64_t    GT_int64;

       typedef int            GT_integer;

      }
    }
  }

#endif

