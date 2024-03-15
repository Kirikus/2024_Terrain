#include "../lib/cartesian_point.h"
#include "../lib/spherical_point.h"

#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>

namespace tt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(test_points)

BOOST_AUTO_TEST_CASE(CartesianPoint_initialization) {
  CartesianPoint c(32.9, -13, 80.999);
  BOOST_TEST(c.get_x() == 32.9, tt::tolerance(1e-6));
  BOOST_TEST(c.get_y() == -13, tt::tolerance(1e-6));
  BOOST_TEST(c.get_h() == 80.999, tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_CASE(SphericalPoint_initialization) {
  CartesianPoint a(0, 0, 0);
  CartesianPoint b(3, 4, 5);
  SphericalPoint c(a, b);
  BOOST_TEST(c.get_x() == 3, tt::tolerance(1e-6));
  BOOST_TEST(c.get_y() == 4, tt::tolerance(1e-6));
  BOOST_TEST(c.get_h() == 5, tt::tolerance(1e-6));
  BOOST_TEST(c.get_d() == 5, tt::tolerance(1e-6));
  BOOST_TEST(c.get_phi() == 0.785398, tt::tolerance(1e-6));
  BOOST_TEST(c.get_R() == 5 * sqrt(2), tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_CASE(CartesianPoint_copy_constructor) {
  CartesianPoint c = CartesianPoint(32.9, -13, 80.999);
  BOOST_TEST(c.get_x() == 32.9, tt::tolerance(1e-6));
  BOOST_TEST(c.get_y() == -13, tt::tolerance(1e-6));
  BOOST_TEST(c.get_h() == 80.999, tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_CASE(SphericalPoint_copy_constructor) {
  CartesianPoint a(0, 0, 0);
  CartesianPoint b(3, 4, 5);
  SphericalPoint c = SphericalPoint(a, b);
  BOOST_TEST(c.get_x() == 3, tt::tolerance(1e-6));
  BOOST_TEST(c.get_y() == 4, tt::tolerance(1e-6));
  BOOST_TEST(c.get_h() == 5, tt::tolerance(1e-6));
  BOOST_TEST(c.get_d() == 5, tt::tolerance(1e-6));
  BOOST_TEST(c.get_phi() == 0.785398, tt::tolerance(1e-6));
  BOOST_TEST(c.get_R() == 5 * sqrt(2), tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_CASE(SphericalPoint_negative_and_zero_coords) {
  CartesianPoint a(0, 0, 0);
  CartesianPoint b(0, 0, 5);
  SphericalPoint c(a, b);
  BOOST_TEST(c.get_x() == 0, tt::tolerance(1e-6));
  BOOST_TEST(c.get_y() == 0, tt::tolerance(1e-6));
  BOOST_TEST(c.get_h() == 5, tt::tolerance(1e-6));

  CartesianPoint a1(0, 0, 0);
  CartesianPoint b1(-3, 0, 5);
  SphericalPoint c1(a1, b1);
  BOOST_TEST(c1.get_x() == -3, tt::tolerance(1e-6));
  BOOST_TEST(c1.get_y() == 0, tt::tolerance(1e-6));
  BOOST_TEST(c1.get_h() == 5, tt::tolerance(1e-6));

  CartesianPoint a2(0, 0, 0);
  CartesianPoint b2(0, -6.2, -5);
  SphericalPoint c2(a2, b2);
  BOOST_TEST(c2.get_x() == 0, tt::tolerance(1e-6));
  BOOST_TEST(c2.get_y() == -6.2, tt::tolerance(1e-6));
  BOOST_TEST(c2.get_h() == -5, tt::tolerance(1e-6));

  CartesianPoint a3(0, 0, 0);
  CartesianPoint b3(-3, -2, 5);
  SphericalPoint c3(a3, b3);
  BOOST_TEST(c3.get_x() == -3, tt::tolerance(1e-6));
  BOOST_TEST(c3.get_y() == -2, tt::tolerance(1e-6));
  BOOST_TEST(c3.get_h() == 5, tt::tolerance(1e-6));

  CartesianPoint a4(0, 0, 0);
  CartesianPoint b4(-3, -1, -5);
  SphericalPoint c4(a4, b4);
  BOOST_TEST(c4.get_x() == -3, tt::tolerance(1e-6));
  BOOST_TEST(c4.get_y() == -1, tt::tolerance(1e-6));
  BOOST_TEST(c4.get_h() == -5, tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_CASE(SphericalPoint_change_R) {
  CartesianPoint center(0, 0, 0);
  CartesianPoint target(1, 1, 1);
  SphericalPoint sp(center, target);

  sp.change_R(3 * sqrt(3));
  BOOST_TEST(sp.get_x() == 3, tt::tolerance(1e-6));
  BOOST_TEST(sp.get_y() == 3, tt::tolerance(1e-6));
  BOOST_TEST(sp.get_h() == 3, tt::tolerance(1e-6));

  sp.change_R(5 * sqrt(3));
  BOOST_TEST(sp.get_x() == 5, tt::tolerance(1e-6));
  BOOST_TEST(sp.get_y() == 5, tt::tolerance(1e-6));
  BOOST_TEST(sp.get_h() == 5, tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_CASE(SphericalPoint_change_azimuth) {
  CartesianPoint center(0, 0, 0);
  CartesianPoint target(3, 4, 5);
  SphericalPoint sp(center, target);

  sp.change_azimuth(M_PI / 2);
  BOOST_TEST(sp.get_x() == 0, tt::tolerance(1e-6));
  BOOST_TEST(sp.get_y() == 5, tt::tolerance(1e-6));
  BOOST_TEST(sp.get_h() == 5, tt::tolerance(1e-6));

  sp.change_azimuth(M_PI);
  BOOST_TEST(sp.get_x() == -5, tt::tolerance(1e-6));
  BOOST_TEST(sp.get_y() == 0, tt::tolerance(1e-6));
  BOOST_TEST(sp.get_h() == 5, tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_CASE(SphericalPoint_change_phi) {
  CartesianPoint center(0, 0, 0);
  CartesianPoint target(3, 4, 5);
  SphericalPoint sp(center, target);

  sp.change_phi(M_PI / 2);
  BOOST_TEST(sp.get_x() == 0, tt::tolerance(1e-6));
  BOOST_TEST(sp.get_y() == 0, tt::tolerance(1e-6));
  BOOST_TEST(sp.get_h() == 5 * sqrt(2), tt::tolerance(1e-6));

  sp.change_phi(M_PI / 4);
  BOOST_TEST(sp.get_x() == 3, tt::tolerance(1e-6));
  BOOST_TEST(sp.get_y() == 4, tt::tolerance(1e-6));
  BOOST_TEST(sp.get_h() == 5, tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_CASE(SphericalPoint_change_d) {
  CartesianPoint center(0, 0, 0);
  CartesianPoint target(1, 1, 4);
  SphericalPoint sp(center, target);

  sp.change_d(4);
  BOOST_TEST(sp.get_x() == 2 * sqrt(2), tt::tolerance(1e-6));
  BOOST_TEST(sp.get_y() == 2 * sqrt(2), tt::tolerance(1e-6));
  BOOST_TEST(sp.get_h() == 4, tt::tolerance(1e-6));

  sp.change_d(8);
  BOOST_TEST(sp.get_x() == 4 * sqrt(2), tt::tolerance(1e-6));
  BOOST_TEST(sp.get_y() == 4 * sqrt(2), tt::tolerance(1e-6));
  BOOST_TEST(sp.get_h() == 4, tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_SUITE_END()
