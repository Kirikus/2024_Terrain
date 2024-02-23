#include "../lib/cartesian_point.h"
#include "../lib/spherical_point.h"

#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>

namespace tt = boost::test_tools;

BOOST_AUTO_TEST_SUITE(test_point)

BOOST_AUTO_TEST_CASE(SphericalPoint_tests) {
  CartesianPoint a(0, 0, 0);
  CartesianPoint b(2, 4, 5);
  SphericalPoint c(a, b);
  BOOST_TEST(c.get_x() == 2, tt::tolerance(1e-6));
  BOOST_TEST(c.get_y() == 4, tt::tolerance(1e-6));
  BOOST_TEST(c.get_h() == 5, tt::tolerance(1e-6));
}

BOOST_AUTO_TEST_SUITE_END()
