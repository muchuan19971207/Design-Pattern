#include "../src/circle.h"
#include "../src/square.h"

#include <algorithm>

class CaseShape: public ::testing::Test {
protected:
    Circle* c10;
    Square* s10;

    void SetUp() override {
        c10 = new Circle(10.0);
        s10 = new Square(10.0);
    }

    void TearDown() override {
        delete c10;
        delete s10;
    }
};

TEST_F(CaseShape, SortIncreasing) {
    Shape* shapes[2] = {c10, s10};
    std::sort(shapes, shapes + 2, [](Shape* s1, Shape* s2) {
        return s1->area() < s2->area();
    });
    ASSERT_NEAR(100, shapes[0]->area(), 0.001);
    ASSERT_NEAR(314.159, shapes[1]->area(), 0.001);
}

TEST_F(CaseShape, SortDecreasing) {
    Shape* shapes[2] = {s10, c10};
    std::sort(shapes, shapes + 2, [](Shape* s1, Shape* s2) {
        return s1->area() >= s2->area();
    });
    ASSERT_NEAR(314.159, shapes[0]->area(), 0.001);
    ASSERT_NEAR(100, shapes[1]->area(), 0.001);
}

TEST_F(CaseShape, SortDecreasingVector) {
    std::vector<Shape*> shapes;
    shapes.push_back(s10);
    shapes.push_back(c10);
    std::sort(shapes.begin(), shapes.end(), [](Shape* s1, Shape* s2) {
        return s1->area() >= s2->area();
    });
    std::vector<Shape*>::iterator it = shapes.begin();
    ASSERT_NEAR(314.159, (*it++)->area(), 0.001);
    ASSERT_NEAR(100, (*it)->area(), 0.001);
}