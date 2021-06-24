#ifndef PYTHONLIBRARIESINCPP_BASEEXCEPTION_HPP
#define PYTHONLIBRARIESINCPP_BASEEXCEPTION_HPP

#include <exception>
#include "Object.hpp"

using namespace std;

class BaseException : public Object, public exception {

    string __classType__ = "<class 'BaseException'>";

protected:

    string __message__ = "Exception origins unknown.";

public:

    BaseException(const string& message) {
        __message__ = message;
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

    ostream&operator<<(ostream& os) const {
        os << __message__;
        return os;
    }

    // this version of name is used because
    // unfortunately GetMessage already exists in C++
    [[nodiscard]] string __GetMessage__() const {
        return __message__;
    };

    Object&operator[](const int& index) const {
        throw BaseException("You cannot implement operator[] for BaseException class.");
    }
};


#endif //PYTHONLIBRARIESINCPP_BASEEXCEPTION_HPP