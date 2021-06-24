#ifndef PYTHONLIBRARIESINCPP_PYBUILTINS_HPP
#define PYTHONLIBRARIESINCPP_PYBUILTINS_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <climits>
#include <ostream>
#include <sstream>
//#include <windows.h>

using namespace std;

template <typename DataType>
string dataType(const DataType& argument) {
    const string argumentType = typeid(argument).name();
    if (argumentType == "i") {
        return "<class 'int'>";
    }
    else if (argumentType[0] == 'A' &&
             argumentType[argumentType.size() - 2] == '_' &&
             argumentType[argumentType.size() - 1] == 'i') {
        return "<class 'intArray'>";
    }
    else if (argumentType == "d") {
        return "<class 'double'>";
    }
    else if (argumentType[0] == 'A' &&
             argumentType[argumentType.size() - 2] == '_' &&
             argumentType[argumentType.size() - 1] == 'd') {
        return "<class 'doubleArray'>";
    }
    else if (argumentType == "f") {
        return "<class 'float'>";
    }
    else if (argumentType[0] == 'A' &&
             argumentType[argumentType.size() - 2] == '_' &&
             argumentType[argumentType.size() - 1] == 'f') {
        return "<class 'floatArray'>";
    }
    else if (argumentType == "c") {
        return "<class 'char'>";
    }
    else if (argumentType[0] == 'A' && argumentType[argumentType.size() - 1] == 'c') {
        return "<class 'charArray'>";
    }
    else if (argumentType == "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE") {
        return "<class 'std::string'>";
    }
    else if (argumentType[0] == 'A' &&
             (isdigit(argumentType[1]) ||
              isdigit(argumentType[2]))) {
        return "<class 'std::stringArray'>";
    }
    else if (argumentType == "b") {
        return "<class 'bool'>";
    }
    else if (argumentType[0] == 'A' &&
             argumentType[argumentType.size() - 2] == '_' &&
             argumentType[argumentType.size() - 1] == 'b') {
        return "<class 'boolArray'>";
    }
    else if (argumentType == "6String") {
        return "<class 'String'>";
    }
    else if (argumentType == "4Type") {
        return "<class 'Type'>";
    }
    return argumentType;
}

bool isdigit(const char &character) {
    switch (character) {
        case '0':
            return true;
        case '1':
            return true;
        case '2':
            return true;
        case '3':
            return true;
        case '4':
            return true;
        case '5':
            return true;
        case '6':
            return true;
        case '7':
            return true;
        case '8':
            return true;
        case '9':
            return true;
    }
    return false;
}
template <typename T>
void swapp(T *argument1, T *argument2) {
    T auxiliar = *argument1;
    *argument1 = *argument2;
    *argument2 = auxiliar;
}

template <typename T>
void swapr(T &argument1, T &argument2) {
    T auxiliar = argument1;
    argument1 = argument2;
    argument2 = auxiliar;
}

void print() {
    cout << endl;
}

template <typename DataType>
void print(const DataType& argument) {
    cout << argument << endl;
}

// TODO update this
template <typename DataType, typename ... DataTypes>
void print(const DataType& argument, const DataTypes& ... arguments) {

    // if type of arguemnt is string and equals "sep='somethging' or end='sonemtrgin'"
    // then do somethign about it. but first we need that type class
    // aaand raise exception when the data type is not in standards

    cout << argument << ' ';
    print(arguments ...);
}

#include "Object.hpp"
#include "Int.hpp"
#include "Float.hpp"
#include "String.hpp"
#include "BaseException.hpp"
#include "Exception.hpp"
#include "TypeError.hpp"
#include "ValueError.hpp"
#include "Type.hpp"
#include "List.hpp"
#include "NotImplementedError.hpp"
#include "Dict.hpp"


int len(const Object& object) {
    return object.__len__();
}

int len(const Object *object) {
    return object->__len__();
}

int len(const char* charArray) {
    return strlen(charArray);
}

int len(const string& stdString) {
    return stdString.size();
}

int len(const int& integer) {
    throw TypeError("object of type 'int' has no len()");
}

string type(const Object& object) {
    return object.__type__();
}

string type(const Object* object) {
    return object->__type__();
}

string repr(const Object& object) {
    return object.__rrepr__();
}


string id(const Object& object) {
    return object.__id__();
}

string tostr(const int& integer) {
    ostringstream oss;
    oss << integer;
    return string(oss.str());
}

string tostr(const double& doubler) {
    ostringstream oss;
    oss << doubler;
    return string(oss.str());
}

string input(const string& displayText="") {
    string userInput;
    print(displayText);
    getline(cin, userInput);
    return userInput;
}

List split(const string& basicString, const char& separator = ' ') {
    List splittedItems;
    String item("");
    const int basicStringSize = basicString.size();
    for (size_t index = 0; index < basicStringSize; index++) {
        if (basicString[index] == separator) {
            splittedItems.append_back(item);
            item = "";
            if (index == basicStringSize - 1) {
                break;
            }
            index++;
        }
        item += basicString[index];
    }
    if (!(item == "")) {
        splittedItems.append_back(item);
    }
    return splittedItems;
}

#endif //PYTHONLIBRARIESINCPP_PYBUILTINS_HPP