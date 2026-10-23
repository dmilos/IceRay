#ifndef ed34bf7e80b54156b5855f4daca28fe2
#define ed34bf7e80b54156b5855f4daca28fe2

#include <cstddef>

#if defined(__clang__)
    typedef std::size_t IceRayC_TypeSize, IceRayC_Type_Size;
#elif defined(_MSC_VER)
    typedef std::size_t IceRayC_TypeSize, IceRayC_Type_Size;
#elif defined(__GNUC__) || defined(__GNUG__)
    typedef std::size_t IceRayC_TypeSize, IceRayC_Type_Size;
#elif defined(__INTEL_COMPILER) || defined(__INTEL_LLVM_COMPILER)
    typedef std::size_t IceRayC_TypeSize, IceRayC_Type_Size;
#else
    typedef std::size_t IceRayC_TypeSize, IceRayC_Type_Size;
#endif

#endif

