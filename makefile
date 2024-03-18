.PHONY: clean

TEST= test/test_square.h test/test_circle.h test/test_shape.h \
 	  test/test_compound_shape.h test/test_iterator.h \
	  test/test_utility.h test/test_visitor.h test/test_builder.h test/test_parser.h
SRC= src/shape.h src/square.h src/circle.h src/compound_shape.h src/iterator.h \
     src/utility.h src/null_iterator.h src/compound_iterator.h src/shape_visitor.h \
	 src/select_shape_visitor.h src/shape_builder.h src/scanner.h src/mock_scanner.h \
	 src/shape_parser.h

bin/test: test/test.cpp $(TEST) $(SRC)
	g++ -std=c++17 test/test.cpp -o bin/test -lgtest -lpthread

clean:
	rm -f bin/test