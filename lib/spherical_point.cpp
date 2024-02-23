#include "spherical_point.h"
#include <iostream>

// TODO: This class does not take in mind Earth curvature
// aka R_earth >> R

SphericalPoint::SphericalPoint(const AbstractPoint &center,
                               const AbstractPoint &position)
    : center{center} {
  double dx = position.get_x() - center.get_x();
  double dy = position.get_y() - center.get_y();
  double dh = position.get_h() - center.get_h();
  R = sqrt(dx * dx + dy * dy + dh * dh);
  double d = sqrt(dx * dx + dy * dy);
  phi = atan(dh / d);
  if (dx > 0 && dy >= 0) // TODO: fix cases dx = 0 and dy = 0
    azimuth = atan(dy / dx);
  else if (dx < 0)
    azimuth = M_PI + atan(dy / dx);
  else if (dx > 0 && dy < 0)
    azimuth = 2 * M_PI + atan(dy / dx);
  else
    azimuth = (dy >= 0) ? M_PI_2 : -M_PI_2;
}

double SphericalPoint::get_x() const { return R * cos(azimuth) * cos(phi); }

double SphericalPoint::get_y() const { return R * sin(azimuth) * cos(phi); }

double SphericalPoint::get_h() const { return R * sin(phi); }

double SphericalPoint::get_d() const { return R * cos(phi); }

void SphericalPoint::change_h(double new_h) {
  double prev_d = get_d();
  phi = atan(new_h / prev_d);
  R = sqrt(new_h * new_h + prev_d * prev_d);
}

void SphericalPoint::change_d(double new_d) {
  double prev_h = get_h();
  phi = atan(prev_h / new_d);
  R = sqrt(prev_h * prev_h + new_d * new_d);
}
