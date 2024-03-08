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
  // Correctly compute azimuth for all quarters
  if (dx == 0) {
    azimuth = (dy >= 0) ? M_PI_2 : -M_PI_2;
    return;
  }
  azimuth = atan(dy / dx);
  azimuth += dx < 0 ? M_PI : 0;
  azimuth += (dx > 0 && dy < 0) ? 2 * M_PI : 0;
}

double SphericalPoint::get_x() const {
  double cos_azimuth =
      (cos(azimuth) <= 1e-10 && cos(azimuth) > 0) ? 0 : cos(azimuth);
  double cos_phi = (cos(phi) <= 1e-10 && cos(phi) > 0) ? 0 : cos(phi);
  return R * cos_azimuth * cos_phi;
}

double SphericalPoint::get_y() const {
  double sin_azimuth =
      (sin(azimuth) <= 1e-10 && sin(azimuth) > 0) ? 0 : sin(azimuth);
  double cos_phi = (cos(phi) <= 1e-10 && cos(phi) > 0) ? 0 : cos(phi);
  return R * sin_azimuth * cos_phi;
}

double SphericalPoint::get_h() const {
  double sin_phi = (sin(phi) <= 1e-10 && sin(phi) > 0) ? 0 : sin(phi);
  return R * sin_phi;
}

double SphericalPoint::get_d() const {
  double cos_phi = (cos(phi) <= 1e-10 && cos(phi) > 0) ? 0 : cos(phi);
  return R * cos_phi;
}

void SphericalPoint::change_h(double new_h) {
  double current_d = get_d();
  phi = atan(new_h / current_d);
  R = sqrt(new_h * new_h + current_d * current_d);
}

void SphericalPoint::change_d(double new_d) {
  double current_h = get_h();
  phi = atan(current_h / new_d);
  R = sqrt(current_h * current_h + new_d * new_d);
}
