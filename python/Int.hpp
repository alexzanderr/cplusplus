#ifndef PYTHONLIBRARIESINCPP_INT_HPP
#define PYTHONLIBRARIESINCPP_INT_HPP

#include "Object.hpp"
#include "NotImplementedError.hpp"

class Int : public Object {

    int __integer__;
    const string __classType__ = "<class 'Int'>";

public:

    Int(int integer) {
        __integer__ = integer;
        __objectType__ = __classType__;
    }

    Int(Int& IntObject) {
        __integer__ = IntObject.GetInteger();
    }

    [[nodiscard]] int GetInteger () const {
        return __integer__;
    }

    ostream&operator<<(ostream& os) const {
        os << __integer__;
        return os;
    }

    string __type__() const {
        return __classType__;
    }

    string __id__() const {
        return "123";
    }

    int __len__() const {
        return __integer__;
    }

    string __rrepr__() const {
        ostringstream oss;
        oss << __integer__;
        return oss.str();
    }

    Object&operator[](const int& index) const {
        throw NotImplementedError("You cannot implement operator[] for class Int");
    }
};

#endif //PYTHONLIBRARIESINCPP_INT_HPP