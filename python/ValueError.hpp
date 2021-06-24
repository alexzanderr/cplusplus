#ifndef PYTHONLIBRARIESINCPP_VALUEERROR_HPP
#define PYTHONLIBRARIESINCPP_VALUEERROR_HPP

#include "Exception.hpp"

class ValueError : public Exception {
    string __classType__ = "<class 'ValueError'>";
public:

    explicit ValueError(const string& message) : Exception(message) {
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
        throw ValueError("You cannot implement operator[] for ValueError class.");
    }
};

#endif //PYTHONLIBRARIESINCPP_VALUEERROR_HPP