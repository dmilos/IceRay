#ifndef Dh_DDMRM_Iceray_utility_table_penrose_HPP_
 #define Dh_DDMRM_Iceray_utility_table_penrose_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_table::GC_penrose

#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/math/coord.hpp"

#include "./structure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_table
        {

         class GC_penrose
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_coord2D;

             typedef GS_DDMRM::S_IceRay::S_utility::S_table::GC_structure  T_structure;
           public:
             explicit GC_penrose( T_size const& P_size = 10 )
              {
               F_init( P_size );
              }
           public:
             bool F_init( T_size const& P_size )
              { // TODO
               T_scalar I_epsilon = 0.000001;
               M2_size.clear();
               M2_radius.clear();
               M2_point.clear();

               // TODO

 /*
 WARNING AI generated
typedef double ScalarType;
using PointType = std::complex<ScalarType>;
typedef std::vector<PointType> CloudType;

void penrose( CloudType& result, ScalarType const& radius )
     constexpr ScalarType epsilon = 1e-9;
    constexpr ScalarType pi = 3.14159265358979323846;

    result.clear();
    if (radius <= 0.0)
        return;

    const PointType z0(1.0, 0.0);
    const PointType z1(std::cos(2.0 * pi / 5.0), std::sin(2.0 * pi / 5.0));
    const PointType z2(std::cos(4.0 * pi / 5.0), std::sin(4.0 * pi / 5.0));
    const PointType z3(std::cos(6.0 * pi / 5.0), std::sin(6.0 * pi / 5.0));
    const PointType z4(std::cos(8.0 * pi / 5.0), std::sin(8.0 * pi / 5.0));

    const std::array<PointType, 5> zeta = {z0, z1, z2, z3, z4};
    constexpr std::array<ScalarType, 5> gamma = {
        0.13, 0.37, 0.61, 0.79, 0.91
    };

    const int limit = static_cast<int>(std::ceil(radius)) + 3;
    const ScalarType radiusSquared = radius * radius;

    result.reserve(static_cast<std::size_t>(
        radius * radius * 5.0 + 32.0));

    for (int r = 0; r < 5; ++r) {
        for (int s = r + 1; s < 5; ++s) {
            const ScalarType denom = std::imag(zeta[s - r]);
            if (std::abs(denom) < epsilon)
                continue;

            const PointType zr = zeta[r];
            const PointType zs = zeta[s];

            for (int kr = -limit; kr <= limit; ++kr) {
                const ScalarType ar = ScalarType(kr) - gamma[r];

                for (int ks = -limit; ks <= limit; ++ks) {
                    const ScalarType as = ScalarType(ks) - gamma[s];

                    const PointType z = PointType(0.0, 1.0) *
                        (zr * as - zs * ar) / denom;

                    const int k0 = static_cast<int>(
                        std::ceil(std::real(z / z0) + gamma[0] - epsilon));
                    const int k1 = static_cast<int>(
                        std::ceil(std::real(z / z1) + gamma[1] - epsilon));
                    const int k2 = static_cast<int>(
                        std::ceil(std::real(z / z2) + gamma[2] - epsilon));
                    const int k3 = static_cast<int>(
                        std::ceil(std::real(z / z3) + gamma[3] - epsilon));
                    const int k4 = static_cast<int>(
                        std::ceil(std::real(z / z4) + gamma[4] - epsilon));

                    const int a0 = r == 0 ? kr : s == 0 ? ks : k0;
                    const int a1 = r == 1 ? kr : s == 1 ? ks : k1;
                    const int a2 = r == 2 ? kr : s == 2 ? ks : k2;
                    const int a3 = r == 3 ? kr : s == 3 ? ks : k3;
                    const int a4 = r == 4 ? kr : s == 4 ? ks : k4;

                    const PointType base =
                        ScalarType(a0) * z0 + ScalarType(a1) * z1 +
                        ScalarType(a2) * z2 + ScalarType(a3) * z3 +
                        ScalarType(a4) * z4;

                    const PointType baseR = base + zr;
                    const PointType baseS = base + zs;

                    const PointType p0 = base;
                    const PointType p1 = baseR;
                    const PointType p2 = baseR + zs;
                    const PointType p3 = baseS;

                    if (std::norm(p0) <= radiusSquared + epsilon)
                        result.push_back(p0);
                    if (std::norm(p1) <= radiusSquared + epsilon)
                        result.push_back(p1);
                    if (std::norm(p2) <= radiusSquared + epsilon)
                        result.push_back(p2);
                    if (std::norm(p3) <= radiusSquared + epsilon)
                        result.push_back(p3);
                }
            }
        }
    }

    std::sort(result.begin(), result.end(),
              [](const PointType& a, const PointType& b) {
                  if (a.real() != b.real())
                      return a.real() < b.real();
                  return a.imag() < b.imag();
              });

    result.erase(std::unique(result.begin(), result.end()), result.end());
 */
               // TODO epsilon

               M2_size.push_back( 0 );
               M2_radius.push_back( 0 );
               for( auto const& I_spot: M2_point )
                {
                 auto I_radius = ::math::linear::vector::length( I_spot );
                 if( I_radius < M2_radius.back() + I_epsilon )
                  {
                   ++M2_size.back();
                   continue;
                  }
                 M2_size.push_back( 1+M2_size.back() );
                 M2_radius.push_back( I_radius );
                 //std::cout<< M2_size[ M2_size.size() -2 ] << ", ";
                }
               //std::cout<< std::endl << "Max penrose size: " << M2_size.size() << std::endl;
               return true;
              }

           public:
             std::vector<T_size> const& F_size()const{ return M2_size; }
           private:
             std::vector<T_size>    M2_size;
           public:
             std::vector<T_scalar> const& F_radius()const{ return M2_radius; }
           private:
             std::vector<T_scalar>  M2_radius;
           public:
             std::vector<T_coord2D> const& F_spot()const{ return M2_point; }
           private:
             std::vector<T_coord2D> M2_point;
          };

        }
      }
    }
  }
#endif
