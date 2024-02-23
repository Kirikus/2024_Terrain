#ifndef ABSTRACTPOINT_H
#define ABSTRACTPOINT_H

// Point in any coordinate system with common interface
class AbstractPoint {
public:
  // Return position in N-S coordinate, m
  virtual double get_x() const = 0;
  // Return position in W-E coordinate, m
  virtual double get_y() const = 0;
  // Return height above sea level, m
  virtual double get_h() const = 0;
};

#endif // ABSTRACTPOINT_H
