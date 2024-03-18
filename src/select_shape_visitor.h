#pragma once

#include "./shape_visitor.h"
#include "./circle.h"
#include "./square.h"
#include "./compound_shape.h"
#include "./iterator.h"

// typedef bool (*ShapeConstraint)(Shape*); // pointer to function
template<class ShapeConstraint>
class SelectShapeVisitor: public ShapeVisitor {
public:
    SelectShapeVisitor(): _result(nullptr), _constraint(nullptr) {}
    SelectShapeVisitor(ShapeConstraint constraint): _result(nullptr), _constraint(constraint) {}
    void visitCircle(Circle* c);
    void visitSquare(Square* s);
    void visitCompoundShape(CompoundShape* cs);
    Shape* getShape();

private:
    Shape* _result;
    ShapeConstraint _constraint;
};

template<typename ShapeConstraint>
void SelectShapeVisitor<ShapeConstraint>::visitCircle(Circle* c) {
    if (_constraint(c)) {
        _result = c; 
    }
}

template<typename ShapeConstraint>
void SelectShapeVisitor<ShapeConstraint>::visitSquare(Square* s) {
    if (_constraint(s)) {
        _result = s; 
    }
}

template<typename ShapeConstraint>
void SelectShapeVisitor<ShapeConstraint>::visitCompoundShape(CompoundShape* cs) {
    // TODO: check if the sought after shape is a compound shape
    Iterator* it = cs->createIterator();
    for (it->first(); !it->isDone(); it->next()) {
        it->currentItem()->accept(this);
    }
}

template<typename ShapeConstraint>
Shape* SelectShapeVisitor<ShapeConstraint>::getShape() {
    return _result;
}