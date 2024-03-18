#pragma once

#include "./scanner.h"

#include <list>

class MockScanner : public Scanner{
public: 
    MockScanner(){
        tokens.push_back("compound");
        tokens.push_back("{");
        tokens.push_back("circle");
        tokens.push_back("circle");
        tokens.push_back("}");

        doubles.push_back(1.0);
        doubles.push_back(2.0);
    }

    std::string nextToken() override{
        std::string result = tokens.front();
        tokens.pop_front();
        return result;
    }

    double nextDouble() override{
        double result = doubles.front();
        doubles.pop_front();
        return result;
    }

    bool isDone() override{
        return tokens.empty() && doubles.empty();
    }

private:
    std::list<std::string> tokens;
    std::list<double> doubles;
};