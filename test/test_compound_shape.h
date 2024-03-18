#include "../src/circle.h"
#include "../src/square.h"
#include "../src/utility.h"
#include "../src/compound_shape.h"

TEST(CaseCompoundShape, Creation) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);
    Shape* shapes[3] = {c1, c2, s};
    CompoundShape cs(shapes, 3);

    EXPECT_EQ(3, cs.count());
    EXPECT_NEAR(6.283+25, cs.area(), 0.001);
}

TEST(CaseCompoundShape, CreationWithCompoundShape) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* shapes[2] = {c1, c2};
    CompoundShape* cs1 = new CompoundShape(shapes, 2);

    Shape* s = new Square(5.0);
    Shape* shapes2[2] = {cs1, s};
    CompoundShape cs2(shapes2, 2);

    EXPECT_EQ(2, cs2.count());
    EXPECT_NEAR(6.283+25, cs2.area(), 0.001);
}

TEST(CaseCompoundShape, SelectFirstByAreaFunctionOnShape) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);
    Shape* shapes[3] = {c1, c2, s};
    Shape* cs = new CompoundShape(shapes, 3);

    Shape* t = selectFirstByArea(cs, 20.0, 30.0);
    EXPECT_EQ(s, t);
}

TEST(CaseCompoundShape, SelectFirstByAreaIterator){
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);
    Shape* shapes[3] = {c1, c2, s};
    CompoundShape cs(shapes, 3);

    Shape* t = selectFirstByArea(cs.createIterator(), 20.0, 30.0);
    EXPECT_EQ(s, t);
}

TEST(CaseCompoundShape, Iterator) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* s = new Square(5.0);
    Shape* shapes[3] = {c1, c2, s};
    CompoundShape cs(shapes, 3);

    Iterator* it = cs.createIterator();

    it->first();
    EXPECT_EQ(c1, it->currentItem());

    it->next();
    EXPECT_EQ(c2, it->currentItem());

    it->next();
    EXPECT_EQ(s, it->currentItem());

    it->next();
    EXPECT_TRUE(it->isDone());
}

TEST(CaseCompoundShape, Remove){
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* shapes[2] = {c1, c2};
    Shape* cs1 = new CompoundShape(shapes, 2);

    Shape* s = new Square(5.0);
    Shape* shapes2[2] = {cs1, s};
    Shape* cs2 = new CompoundShape(shapes2, 2);

    cs2->remove(c2);

    EXPECT_NEAR(6.283/2+25, cs2->area(), 0.001);
}