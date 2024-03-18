#pragma once

#include "./iterator.h"
#include "./compound_shape.h"

Shape* selectFirstByArea(Shape* s, double min, double max) {
    Iterator* t = s->createIterator();
    Shape* result = nullptr;
    for(t->first() ; !t->isDone() ; t->next()){
        if(min < t->currentItem()->area() && t->currentItem()->area() < max){
            result = t->currentItem();
            break;
        }
    }
    delete t;
    return result;
}

Shape* selectFirstByArea(Iterator* t, double min, double max){
    for(t->first() ; !t->isDone() ; t->next()){
        if(min < t->currentItem()->area() && t->currentItem()->area() < max){
            return t->currentItem();
        }
    }
    return nullptr;
}

template<class ShapeConstraint>
Shape* selectShape(Shape* shape, ShapeConstraint constraint) {
    Iterator* it = shape->createIterator();
    Shape* result = nullptr;
    for(it->first() ; !it->isDone() ; it->next()){
        if(constraint(it->currentItem())){
            result = it->currentItem();
            break;
        }
    }
    delete it;
    return result;
}