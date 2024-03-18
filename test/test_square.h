#include "../src/square.h"

TEST(CaseSquare, Creation) {
    Square s(10.0);
    ASSERT_NEAR(10, s.sideLength(), 0.0001);
}

TEST(CaseSquare, Area) {
    Square s(10.0);
    ASSERT_NEAR(100, s.area(), 0.0001);
}
