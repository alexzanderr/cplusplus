#ifndef PYTHONLIBRARIESINCPP_PYMATH_HPP
#define PYTHONLIBRARIESINCPP_PYMATH_HPP

// this document includes mathematical functions and algorithms

#include <iostream>
#include "pybuiltins.hpp"

using namespace std;

int __abs__(const int& value) {
    if (value > 0) {
        return value;
    }
    return -value;
}

double __power__(const double& base, const int& exponent) {
    if (exponent == 0) {
        return 1;
    }
    const int exp = __abs__(exponent);
    double powerValue = 1;
    for (size_t index = 0; index < exp; index++) {
        powerValue *= base;
    }
    if (exponent > 0) {
        return powerValue;
    }
    return (1.0 / powerValue);
}

class Function {
    virtual string __rrepr__() const = 0;
    virtual ostream& operator<<(ostream& os) const = 0;

    friend ostream&operator<<(ostream& os, const Function& FunctionObject) {
        FunctionObject.operator<<(os);
        return os;
    }

    friend ostream&operator<<(ostream& os, const Function* FunctionObject) {
        FunctionObject->operator<<(os);
        return os;
    }
};

class Constant : public Function {
    double __result__ = 0.0;
    string __representation__;

public:

    explicit Constant(const double& constant) {
        __result__ += constant;
        __representation__ = tostr(constant);
    }

    [[nodiscard]] double GetValue() const {
        return __result__;
    }

    ostream& operator<<(ostream& os) const {
        os << __result__;
        return os;
    }

    string __rrepr__() const {
        return __representation__;
    }
};

class Linear : public Function {

    double __result__ = 0.0;
    string __representation__ = "X";

public:

    explicit Linear(const double& parameter, const double& constant=0.0) {
        __result__ += parameter + constant;
        if (constant) {
            __representation__ += " + " + tostr(constant);
        }
    }

    [[nodiscard]] double GetValue() const {
        return __result__;
    }

    ostream& operator<<(ostream& os) const {
        os << __result__;
        return os;
    }

    string __rrepr__() const {
        return __representation__;
    }

};

class PowerLinear: public Function {
    double __base__;
    double __exponent__;
    double __result__ = 0.0;
    string __representation__ = "X";

public:

    explicit PowerLinear(const double& base, const int& exponent,  const double& constant=0.0) {
        __base__ = base;
        __exponent__ = exponent;
        __result__ = __power__(base, exponent);
        __representation__ += "^" + tostr(exponent);
    }

    friend Constant operator*(const Constant& ConstantObject, const PowerLinear& PowerLinearObject) {
        return Constant(ConstantObject.GetValue() * PowerLinear(PowerLinearObject.GetBase(), PowerLinearObject.GetExponent()).GetValue());
    }

    [[nodiscard]] double GetBase() const {
        return __base__;
    }

    [[nodiscard]] double GetExponent() const {
        return __exponent__;
    }

    [[nodiscard]] double GetValue() const {
        return __result__;
    }

    ostream& operator<<(ostream& os) const {
        os << __result__;
        return os;
    }

    string __rrepr__() const {
        return __representation__;
    }
};

Function* ComputeDervative(const Constant& ConstantFunction) {
    return new Constant(0);
}

Function* ComputeDerivative(const Linear& LinearFunction) {
    return new Constant(1);
}

Function* ComputeDerivative(const PowerLinear& PowerLinearFunction) {
    return new Constant(Constant(PowerLinearFunction.GetExponent()) * PowerLinear(PowerLinearFunction.GetBase(), PowerLinearFunction.GetExponent() - 1));
}

#endif //PYTHONLIBRARIESINCPP_PYMATH_HPP