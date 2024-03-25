#include "../lib/map1d.h"
#include "../lib/spherical_point.h"

double Map1D::h(double d) {
  SphericalPoint p(rls, target);
  p.change_d(d);
  const AbstractPoint &aim = p.get_target();
  return data->h(aim);
}

VG::VegetationType Map1D::vegetationType(double d) {
  SphericalPoint p(rls, target);
  p.change_d(d);
  const AbstractPoint &aim = p.get_target();
  return data->vegetationType(aim);
}

double Map1D::dielectricPermittivity(double d) {
  SphericalPoint p(rls, target);
  p.change_d(d);
  const AbstractPoint &aim = p.get_target();
  return data->dielectricPermittivity(aim);
}
