#pragma once

#include <string>

class Scanner{
public:
    virtual ~Scanner(){}
    virtual std::string nextToken() = 0;
    virtual double nextDouble() = 0;
    virtual bool isDone() = 0;
};