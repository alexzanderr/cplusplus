#ifndef PYTHONLIBRARIESINCPP_NOTIMPLEMENTEDERROR_HPP
#define PYTHONLIBRARIESINCPP_NOTIMPLEMENTEDERROR_HPP

#include "RuntimeError.hpp"

class NotImplementedError : public RuntimeError {

    const string __classType__ = "<class 'NotImplementedError'>";

public:

    string __type__() const {
        return __classType__;
    }


    NotImplementedError(const string& message): RuntimeError(message) {
        __message__ = message;
    }

    Object&operator[](const int& index) const {
        throw NotImplementedError("You cannot implement operator[] for class NotImplementedError");
    }

};

#endif //PYTHONLIBRARIESINCPP_NOTIMPLEMENTEDERROR_HPP