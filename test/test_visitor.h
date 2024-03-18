#include "../src/circle.h"
#include "../src/square.h"
#include "../src/compound_shape.h"
#include "../src/shape_visitor.h"
#include "../src/select_shape_visitor.h"

#include <iostream>

typedef bool (*ShapeConstraint)(Shape*); // pointer to function

TEST(CaseVisitor, SelectShape) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);
    Shape* shapes[3] = {c1, c2, s};
    CompoundShape cs(shapes, 3);
    
    SelectShapeVisitor<ShapeConstraint>* visitor = new SelectShapeVisitor<ShapeConstraint>([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });
    cs.accept(visitor);
    Shape* result = visitor->getShape();

    ASSERT_EQ(s, result);

    delete visitor;
} 

TEST(CaseVisitor, SelectShapeOnCircleNotFound) {
    Circle* c1 = new Circle(1.0);
    
    SelectShapeVisitor<ShapeConstraint>* visitor = new SelectShapeVisitor<ShapeConstraint>([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });
    // c1->accept(visitor);
    visitor->visitCircle(c1);
    Shape* result = visitor->getShape();

    ASSERT_EQ(nullptr, result);
    delete c1;
    delete visitor;
} 

TEST(CaseVisitor, SelectShapeOnCircleThroughVisitor) {
    Circle* c1 = new Circle(3.0);
    
    SelectShapeVisitor<ShapeConstraint>* visitor = new SelectShapeVisitor<ShapeConstraint>([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });
    c1->accept(visitor);
    Shape* result = visitor->getShape();

    ASSERT_EQ(c1, result);

    delete c1;
    delete visitor;
} 

TEST(CaseVisitor, SelectShapeOnCircle) {
    Circle* c2 = new Circle(3.0);
    
    ShapeVisitor* visitor = new SelectShapeVisitor([](Shape* shape) {
        return shape->area() > 20.0 && shape->area() < 30.0;
    });

    visitor->visitCircle(c2);
    Shape* result = visitor->getShape();

    ASSERT_EQ(c2, result);

    delete c2;
    delete visitor;
} 

TEST(CaseVisitor, SelectShapeByInstance) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);
    Shape* shapes[3] = {c1, c2, s};
    CompoundShape cs(shapes, 3);
    
    ShapeVisitor* visitor = new SelectShapeVisitor([c2](Shape* shape) {
        return c2 == shape;
    });
    cs.accept(visitor);
    Shape* result = visitor->getShape();

    ASSERT_EQ(c2, result);

    delete visitor;
} 