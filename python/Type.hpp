#ifndef PYTHONLIBRARIESINCPP_TYPE_HPP
#define PYTHONLIBRARIESINCPP_TYPE_HPP

#include "Object.hpp"

class Type : public Object {

    string __classType__ = "<class 'Type'>";
    string __typeInputed__;

public:

    Type(const Object& object) {
        __typeInputed__ = object.__objectType__;
    }

    ostream&operator<<(ostream& os) const {
        os << __typeInputed__;
        return os;
    }

    string __type__() const {
        return __classType__;
    }
};

#endif //PYTHONLIBRARIESINCPP_TYPE_HPP