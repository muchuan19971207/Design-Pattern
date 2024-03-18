#include "../src/shape_parser.h"
#include "../src/shape_scanner.h"
#include "../src/mock_scanner.h"

TEST(CaseParser, ParseCompound){
    std::string input = "compound {\n circle 1.0\n circle 2.0\n }";
    ShapeParser* parser = new ShapeParser(new MockScanner(), new ShapeBuilder());
    Shape* result = parser->parse(input);

    ASSERT_NEAR(1*1*M_PI + 2*2*M_PI, result->area(), 0.01);
}

TEST(CaseParser, ParseComplexCompound){
    std::string input = "compound {\n compound {\n circle 1.0\n circle 2.0\n }\n square 3.0\n }";
    ShapeParser* parser = new ShapeParser(new ShapeScanner(input), new ShapeBuilder());
    Shape* result = parser->parse(input);

    ASSERT_NEAR(1*1*M_PI + 2*2*M_PI + 9, result->area(), 0.01);
}