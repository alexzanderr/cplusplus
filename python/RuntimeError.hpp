#ifndef PYTHONLIBRARIESINCPP_RUNTIMEERROR_HPP
#define PYTHONLIBRARIESINCPP_RUNTIMEERROR_HPP

#include "Exception.hpp"

class RuntimeError : public Exception {

    const string __classType__ = "<class 'RuntimeError'>";

public:

    RuntimeError(const string& message) : Exception(__message__) {}

    Object&operator[](const int& index) const {
        throw RuntimeError("You cannot implement operator[] for RuntimeError class.");
    }

};

#endif //PYTHONLIBRARIESINCPP_RUNTIMEERROR_HPP
