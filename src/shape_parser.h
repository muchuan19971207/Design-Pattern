#pragma once

#include "./scanner.h"
#include "./shape_builder.h"
#include "./shape.h"

#include <string>

class ShapeParser{
public:
    ShapeParser(Scanner* scanner, ShapeBuilder* builder): _scanner(scanner), _builder(builder){
    }

    ~ShapeParser(){
        delete _builder;
        delete _scanner;
    }

    Shape* parse(std::string input){
        while(!_scanner->isDone()){
            std::string token = _scanner->nextToken();
            if(token == "circle"){
                _builder->buildCircle(_scanner->nextDouble());
            }else if(token == "square"){
                _builder->buildSquare(_scanner->nextDouble());
            }else if(token == "compound"){
                _scanner->nextToken(); // ignore {
                _builder->buildCompoundBegin();
            }else if(token == "}"){
                _builder->buildCompoundEnd();
            }
        }
        return _builder->getShape();
    }

private:
    ShapeBuilder* _builder;
    Scanner* _scanner;
};