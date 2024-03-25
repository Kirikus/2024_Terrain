#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include "abstract_point.h"

namespace Elevation {

class Elevation {
public:
  virtual double h(const AbstractPoint &p) const = 0;
};

class Plain : public Elevation {
public:
  double h(const AbstractPoint &p) const final { return 0; }
};

class Mountain : public Elevation {
public:
  Mountain(double height, double angle) : height{height}, angle{angle} {}

  double h(const AbstractPoint &p) const final;

private:
  double height;
  double angle;
};

class GeoData : public Elevation {
public:
  double h(const AbstractPoint &p) const final;
};
} // namespace Elevation
#endif // HEIGHTMAP_H
