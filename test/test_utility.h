#include "../src/circle.h"
#include "../src/square.h"
#include "../src/utility.h"
#include "../src/compound_shape.h"

TEST(CaseUtility, SelectShape) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);
    Shape* shapes[3] = {c1, c2, s};
    CompoundShape cs(shapes, 3);
    
    Shape* result = selectShape(&cs, [](Shape* shape){
        return shape->area() > 20.0 && shape->area() < 30.0;
    });

    ASSERT_EQ(s, result);
}