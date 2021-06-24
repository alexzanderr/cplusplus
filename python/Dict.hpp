#ifndef PYTHONLIBRARIESINCPP_DICT_HPP
#define PYTHONLIBRARIESINCPP_DICT_HPP

#include <map>

#include "Object.hpp"
#include "Int.hpp"
#include "String.hpp"
#include "List.hpp"

class Dict : public Object {

    string __classType__ = "<class 'Dict'>";

    map<Object*, Object*> __dict__;
    List __dictKeys__;
    List __dictValues__;

public:

    string __type__() const {
        return __classType__;
    }

    string __id__() const {
        return "0x123123";
    }

    int __len__() const {
        return 0;
    }

    Object&operator[](const int& key) {
        throw exception();
    }

    Object&operator[](const string& key) const {
        throw exception();
    }

    Object&operator[](const char* key) const {
        throw exception();
    }

};

#endif //PYTHONLIBRARIESINCPP_DICT_HPP