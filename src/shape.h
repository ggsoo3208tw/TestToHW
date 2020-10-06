#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual void add(Shape * shape) {
      throw (std::string)"Can't support this operation.";
    }
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    virtual ~Shape(){};
};
#endif
