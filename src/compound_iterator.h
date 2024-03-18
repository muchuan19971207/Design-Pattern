#pragma once

#include "./iterator.h"

template<class ShapePtrPtr>
class CompoundIterator : public Iterator{
public:
    CompoundIterator(ShapePtrPtr begin, ShapePtrPtr end): _begin(begin), _end(end){
        first();
    }

    void first() override{
        _current = _begin;
    }

    Shape* currentItem() const override {
        return *_current;
    }

    void next() override {
        _current++;
    }

    bool isDone() const override {
        return _current == _end;
    }

private:
    ShapePtrPtr _current;
    ShapePtrPtr _begin;
    ShapePtrPtr _end;
};