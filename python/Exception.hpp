#ifndef PYTHONLIBRARIESINCPP_EXCEPTION_HPP
#define PYTHONLIBRARIESINCPP_EXCEPTION_HPP

#include "BaseException.hpp"

class Exception : public BaseException {

    string __classType__ = "<class 'Exception'>";
public:

    Exception(const string& message): BaseException(message) {
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

    Object&operator[](const int& index) const {
        throw Exception("You cannot implement operator[] for Exception class.");
    }
};

#endif //PYTHONLIBRARIESINCPP_EXCEPTION_HPP