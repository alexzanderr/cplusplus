#ifndef PYTHONLIBRARIESINCPP_CHAR_HPP
#define PYTHONLIBRARIESINCPP_CHAR_HPP

#include "Object.hpp"

class Char : public Object {
    char __character__;
    const string __classType__ = "<class 'Char'>";
public:
    explicit Char(const char& character) {
        __character__ = character;
        __objectType__ = __classType__;
    }

    [[nodiscard]] char GetCharacter () const {
        return __character__;
    }

    ostream&operator<<(ostream& os) const {
        os << __character__;
        return os;
    }

    string __type__() const {
        return __classType__;
    }

    string __id__() const {
        return "123";
    }

    int __len__() const {
        return 1;
    }

    string __rrepr__() const {
        string representation = "'";
        representation += __character__;
        representation += "'";
        return representation;
    }

    Object&operator[](const int& index) const {
        throw exception();
    }
};

#endif //PYTHONLIBRARIESINCPP_CHAR_HPP