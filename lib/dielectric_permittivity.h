#ifndef DIELECTRIC_PERMITTIVITY_H
#define DIELECTRIC_PERMITTIVITY_H

#include "abstract_point.h"

namespace DielectricPermittivity {

class DielectricPermittivity {
public:
  virtual double dielectricPermittivity(const AbstractPoint &p) const = 0;
};

class Constant : public DielectricPermittivity {
public:
  Constant(double coefficient) : coefficient{coefficient} {}

  double dielectricPermittivity(const AbstractPoint &p) const final {
    return coefficient;
  }

private:
  double coefficient;
};

class GeoData : public DielectricPermittivity {
public:
  double dielectricPermittivity(const AbstractPoint &p) const final;
};
} // namespace DielectricPermittivity
#endif // DIELECTRIC_PERMITTIVITY_H
