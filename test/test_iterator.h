#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/null_iterator.h"

TEST(CaseNullIterator, NullIterator){
    Iterator* it = new NullIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}