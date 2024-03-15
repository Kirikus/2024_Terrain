#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include "abstract_point.h"

namespace Elevation {

class Elevation {
public:
  virtual double h(const AbstractPoint &p) = 0;
};

class Plain : public Elevation {
public:
  double h(const AbstractPoint &p) final { return 0; }
};

class Mountain : public Elevation {
public:
  Mountain(double height, double angle) : height{height}, angle{angle} {}

  double h(const AbstractPoint &p) final;

private:
  double height;
  double angle;
};

class GeoData : public Elevation {
public:
  double h(const AbstractPoint &p) final;
};
} // namespace Elevation
#endif // HEIGHTMAP_H
