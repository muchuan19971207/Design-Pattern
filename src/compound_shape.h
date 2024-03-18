#ifndef COMPOUND_SHAPE_H
#define COMPOUND_SHAPE_H

#include <list>

#include "./iterator.h"
#include "./compound_iterator.h"
#include "./shape.h"
#include "./shape_visitor.h"

class CompoundShape : public Shape {
   public:
    CompoundShape() {}

    CompoundShape(Shape* shapes[], int count) {
        for (int i = 0; i < count; i++) {
            _shapes.push_back(shapes[i]);
        }
    };

    double area() const override {
        double result = 0;
        for(Shape* s : _shapes){
            result += s->area();
        }
        return result;
    }

    Iterator* createIterator() override {
        return new CompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(), _shapes.end());
    }

    int count() const { return _shapes.size(); }

    ~CompoundShape() {
        for(Shape* s : _shapes){
            delete s;
        }
    }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitCompoundShape(this);
    }

    void add(Shape* shape) override{
        _shapes.push_back(shape);
    }

    void remove(Shape* shape) override{
        for(auto it = _shapes.begin() ; it != _shapes.end() ; it++){
            if(*it == shape){
                delete *it;
                _shapes.erase(it);
                break;
            }else{
                Iterator *shapeIt = (*it)->createIterator();
                if(!shapeIt->isDone())
                    (*it)->remove(shape);
                delete shapeIt;
            }
        }
    }

   private:
    // int _count;
    std::list<Shape*> _shapes;
};

#endif