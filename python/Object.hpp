#ifndef PYTHONLIBRARIESINCPP_OBJECT_HPP
#define PYTHONLIBRARIESINCPP_OBJECT_HPP

#include <iostream>
#include <exception>
using namespace std;

// the supreme class
class Object {
public:
    string __objectType__;

    virtual string __type__() const = 0;
    virtual string __id__() const = 0;
    virtual int __len__() const = 0;
    virtual string __rrepr__() const = 0;
    virtual ostream& operator<<(ostream& os) const = 0;
    virtual Object& operator[](const int& index) const = 0;

    friend ostream&operator<<(ostream& os, const Object& object) {
        //os << object.__rrepr__();
        object.operator<<(os);
        return os;
    }

    friend ostream&operator<<(ostream& os, const Object* object) {
        //os << object->__rrepr__();
        object->operator<<(os);
        return os;
    }

};

#endif //PYTHONLIBRARIESINCPP_OBJECT_HPP