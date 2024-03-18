#include <string>

#include "../src/shape.h"
#include "../src/shape_builder.h"

class CaseBuilder : public ::testing::Test {
protected:
    const double delta = 0.001;

    void SetUp() override {

    }

    void TearDown() override {

    }
};

TEST_F(CaseBuilder, BuildCircle) {
    ShapeBuilder* builder = new ShapeBuilder();
    double radius = 1.0;
    builder->buildCircle(radius);
    Shape* result = builder->getShape();

    ASSERT_NEAR(1*1*M_PI, result->area(), delta);

    delete builder;
}

TEST_F(CaseBuilder, BuildCompound) {
    ShapeBuilder* builder = new ShapeBuilder();

    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildCircle(2.0);
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();

    ASSERT_NEAR(1*1*M_PI + 2*2*M_PI, result->area(), delta);

    delete builder;
}

TEST_F(CaseBuilder, BuildComplexCompound){
    ShapeBuilder* builder = new ShapeBuilder();

    builder->buildCompoundBegin();
    builder->buildCompoundBegin();
    builder->buildCircle(1.0);
    builder->buildCircle(2.0);
    builder->buildCompoundEnd();
    builder->buildSquare(3.0);
    builder->buildCompoundEnd();
    Shape* result = builder->getShape();

    ASSERT_NEAR(1*1*M_PI + 2*2*M_PI, result->createIterator()->currentItem()->area(), delta);

    delete builder;
}