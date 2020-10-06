#ifndef MIXED_SHAPE_H
#define MIXED_SHAPE_H

#include "shape.h"
#include <vector>

class MixedShape : public Shape{
public:
  MixedShape(){}
  double area() const {
    double totalArea = 0.0;
    for(auto shape : _shapes){
      totalArea += shape->area();
    }
    return totalArea;
  }
  int getNumberOfComponents(){
    return _shapes.size();
  }
  void add(Shape * shape){
    _shapes.push_back(shape);
  }
private:
  std::vector<Shape *> _shapes;
};
#endif
