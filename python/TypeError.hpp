#ifndef PYTHONLIBRARIESINCPP_TYPEERROR_HPP
#define PYTHONLIBRARIESINCPP_TYPEERROR_HPP

#include "Exception.hpp"

class TypeError : public Exception {

    string __classType__ = "<class 'TypeError'>";

public:

    explicit TypeError(const string& message) : Exception(message) {
        __objectType__ = __classType__;
    }

    ostream&operator<<(ostream& os) const {
        os << __message__;
        return os;
    }

    string __type__() const {
        return __classType__;
    }

    string __id__() const {
        return "0x123123";
    }

    int __len__() const {
        return 0;
    }

    string __rrepr__() const {
        return __message__;
    }

    Object&operator[](const int& index) const {
        throw exception();
    }

};

#endif //PYTHONLIBRARIESINCPP_TYPEERROR_HPP