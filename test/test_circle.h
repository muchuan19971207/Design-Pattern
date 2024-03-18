#include "../src/circle.h"

TEST(CaseCircle, Area) {
    Circle c(10.0);
    ASSERT_NEAR(314.159, c.area(), 0.001);
}

TEST(CaseCircle, NullIterator) {
    Circle c(10.0);
    ASSERT_TRUE(c.createIterator()->isDone());
}
