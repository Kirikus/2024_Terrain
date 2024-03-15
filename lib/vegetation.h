#ifndef VEGETATION_H
#define VEGETATION_H

#include "abstract_point.h"

namespace Vegetation {

enum class VegetationType { Nothing, Grass, Forest };

class Vegetation {
public:
  virtual VegetationType vegetation_type(const AbstractPoint &p) = 0;
};

class None : public Vegetation {
  VegetationType vegetation_type(const AbstractPoint &p) final {
    return VegetationType::Nothing;
  }
};

class Constant : public Vegetation {
public:
  Constant(VegetationType type) : type{type} {}

  VegetationType vegetation_type(const AbstractPoint &p) final { return type; }

private:
  VegetationType type;
};

class GeoData : public Vegetation {
public:
  VegetationType vegetation_type(const AbstractPoint &p) final;
};
} // namespace Vegetation
#endif // VEGETATION_H
