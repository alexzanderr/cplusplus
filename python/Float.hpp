#ifndef PYTHONLIBRARIESINCPP_FLOAT_HPP
#define PYTHONLIBRARIESINCPP_FLOAT_HPP

#include "Object.hpp"

class Float : public Object {

    float __floater__;
    const string __classType__ = "<class 'Float'>";

public:

    explicit Float(const float& floater) {
        __floater__ = floater;
        __objectType__ = __classType__;
    }

    ostream&operator<<(ostream& os) const {
        os << __floater__;
        return os;
    }

    string __type__() const {
        return __classType__;
    }

    string __id__() const {
        return "123";
    }

    int __len__() const {
        return __floater__;
    }

    string __rrepr__() const {
        ostringstream oss;
        oss << __floater__;
        return oss.str();
    }

    Object&operator[](const int& index) const {
        throw NotImplementedError("You cannot implement operator[] for Float class.");
    }
};

#endif //PYTHONLIBRARIESINCPP_FLOAT_HPP