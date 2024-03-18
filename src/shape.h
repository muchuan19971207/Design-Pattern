#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Iterator;
class ShapeVisitor;

class Shape {
   public:
    virtual ~Shape(){}
    virtual double area() const { return 0.0; }
    virtual Iterator* createIterator() = 0;
    virtual void accept(ShapeVisitor* visitor) = 0;
    virtual void add(Shape* shape){throw std::string("method not allowed");}
    virtual void remove(Shape* shape){throw std::string("method not allowed");}
};

#endif