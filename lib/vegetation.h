#ifndef VEGETATION_H
#define VEGETATION_H

#include "abstract_point.h"

namespace Vegetation {

enum class VegetationType { Nothing, Grass, Shrub, Forest };

class Vegetation {
public:
  virtual VegetationType vegetationType(const AbstractPoint &p) const = 0;
};

class None : public Vegetation {
  VegetationType vegetationType(const AbstractPoint &p) const final {
    return VegetationType::Nothing;
  }
};

class Constant : public Vegetation {
public:
  Constant(VegetationType type) : type{type} {}

  VegetationType vegetationType(const AbstractPoint &p) const final {
    return type;
  }

private:
  VegetationType type;
};

class GeoData : public Vegetation {
public:
  VegetationType vegetationType(const AbstractPoint &p) const final;
};
} // namespace Vegetation
#endif // VEGETATION_H
