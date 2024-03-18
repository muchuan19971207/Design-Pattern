#pragma once

#include "./shape.h"

class Iterator{
public:
    Iterator(){}

    virtual ~Iterator(){}
    
    virtual void first(){}

    virtual Shape* currentItem() const {
        return nullptr;
    }

    virtual void next(){}

    virtual bool isDone() const = 0;
};