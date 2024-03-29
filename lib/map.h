#ifndef MAP_H
#define MAP_H

#include "abstract_point.h"
#include "dielectric_permittivity.h"
#include "elevation.h"
#include "vegetation.h"

namespace EL = Elevation;
namespace VG = Vegetation;
namespace DP = DielectricPermittivity;

class Map {
public:
  Map();
  Map(EL::Elevation *e, VG::Vegetation *v, DP::DielectricPermittivity *dp)
      : elevation{e}, vegetation{v}, dielectric_permittivity{dp} {}
  double h(const AbstractPoint &p) { return elevation->h(p); }
  double dielectricPermittivity(const AbstractPoint &p) {
    return dielectric_permittivity->dielectricPermittivity(p);
  }
  VG::VegetationType vegetation_type(const AbstractPoint &p) {
    return vegetation->vegetation_type(p);
  }

private:
  EL::Elevation *elevation;
  VG::Vegetation *vegetation;
  DP::DielectricPermittivity *dielectric_permittivity;
};

#endif // MAP_H
