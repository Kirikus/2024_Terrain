#ifndef SPHERICALPOINT_H
#define SPHERICALPOINT_H

#include "abstract_point.h"
#include "cartesian_point.h"
#include <cmath>

class SphericalPoint : public AbstractPoint {
public:
  SphericalPoint(const AbstractPoint &center, const AbstractPoint &position);
  SphericalPoint(const SphericalPoint &other) = default;

  double get_x() const final;
  double get_y() const final;
  double get_h() const final;

  double get_R() const { return R; }
  double get_phi() const { return phi; }
  double get_d() const;

  const AbstractPoint &get_center() const { return center; }
  const AbstractPoint &get_target() const;

  void change_R(double new_R) { R = new_R; }
  void change_phi(double new_phi) { phi = new_phi; }
  void change_azimuth(double new_azimuth) { azimuth = new_azimuth; }
  void change_h(double new_h);
  void change_d(double new_d);

private:
  const AbstractPoint &center;
  double azimuth;
  double R;
  double phi;
};

#endif // SPHERICALPOINT_H
