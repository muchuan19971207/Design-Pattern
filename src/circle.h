#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>

#include "./iterator.h"
#include "./null_iterator.h"
#include "./shape.h"
#include "./shape_visitor.h"

class Circle : public Shape {
   public:
    Circle(double radius) : _radius(radius) {}

    ~Circle(){}

    double area() const override { return pow(_radius, 2) * M_PI; }

    Iterator* createIterator() override {
        return new NullIterator();
    }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitCircle(this);
    }

   private:
    double _radius;
};

#endif