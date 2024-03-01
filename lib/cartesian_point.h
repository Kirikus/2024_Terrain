#ifndef CARTESIANPOINT_H
#define CARTESIANPOINT_H

#include "abstract_point.h"

class CartesianPoint : public AbstractPoint {
public:
  CartesianPoint(double x, double y, double h) : x{x}, y{y}, h{h} {}
  CartesianPoint(const CartesianPoint &other) = default;

  double get_x() const final { return x; }
  double get_y() const final { return y; }
  double get_h() const final { return h; }

private:
  double x;
  double y;
  double h;
};

#endif // CARTESIANPOINT_H
