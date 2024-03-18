#ifndef SQUARE_H
#define SQUARE_H

#include "./iterator.h"
#include "./null_iterator.h"
#include "./shape.h"
#include "./shape_visitor.h"

#include <string>

class Square : public Shape {
   public:
    Square(double sideLength) : _sideLength(sideLength) {}
    ~Square(){}
    double sideLength() const { return _sideLength; }
    double area() const override { return _sideLength * _sideLength; }
    Iterator* createIterator() override {
        return new NullIterator();
    }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitSquare(this);
    }

   private:
    double _sideLength;
};

#endif