#ifndef PYTHONLIBRARIESINCPP_LIST_HPP
#define PYTHONLIBRARIESINCPP_LIST_HPP

#include <deque>
#include <vector>
#include <functional>



#include "Object.hpp"
#include "Int.hpp"
#include "Char.hpp"
#include "Float.hpp"
#include "String.hpp"
#include "BaseException.hpp"
#include "TypeError.hpp"
#include "NotImplementedError.hpp"

class List : public Object {

    vector<Object*> container;
    const string __classType__ = "<class 'List'>";

public:

    [[nodiscard]] vector<Object*> __GetList__() const {
        return container;
    }

    List() {
        __objectType__ = __classType__;
    };


    List(int integer) {
        __objectType__ = __classType__;

        // finding the total number of digits
        int copy = integer;
        int numberOfDigits = 1;
        while (copy > 9) {
            numberOfDigits++;
            copy /= 10;
        }

        // creating and allocating the digits array
        int current = 0;
        int digits[numberOfDigits];
        while (integer) {
            digits[current++] = integer % 10;
            integer /= 10;
        }

        // iterating the digits array and saving digits into container
        for (size_t index = numberOfDigits - 1; index > 0; index--) {
            container.push_back(new Int(digits[index]));
        }
        container.push_back(new Int(digits[0]));
    }


    List(const List& ListObject) {
        if (this == &ListObject) {
            return;
        }
        const int len = ListObject.__len__();
        for (size_t index = 0; index < len; index++) {
            // we need to do this because we cannot use an
            // overloaded operator like [] on a pointer
            // using __GetList__
            container.push_back(ListObject.__GetList__()[index]);
        }
    }

    List(const List* ListObject) {
        if (this == ListObject) {
            return;
        }
        const int len = ListObject->__len__();
        for (size_t index = 0; index < len; index++) {
            // we need to do this because we cannot use an
            // overloaded operator like [] on a pointer
            // using __GetList__
            container.push_back(ListObject->__GetList__()[index]);
        }
    }

    List(const char* basicString) {
        __objectType__ = __classType__;
        const int size = strlen(basicString);
        for (size_t index = 0; index < size; index++) {
            container.push_back(new Char(basicString[index]));
        }
    }

    // append back
    void append_back(Int IntObject) {
        container.push_back(new Int(IntObject));
    }

    void append_back(Int* IntObject) {
        container.push_back(new Int(IntObject->GetInteger()));
    }

    void append_back(const Object& object) {
        Object *newObject = const_cast<Object *>(&object);
        container.push_back(newObject);
    }

    void append_back(String StringObject) {
        container.push_back(new String(StringObject));
    }

    void append_back(const Object* object) {
        Object *newObject = (Object *)(&object);
        container.push_back(newObject);
    }

    void append_back(const List& ListObject) {
        container.push_back(new List(ListObject));
    }

    void append_back(const List* ListObject) {
        container.push_back(new List(ListObject));
    }

    // append_back int
    void append_back(const int& integer) {
        container.push_back(new Int(integer));
    }

    // append_back char
    void append_back(const char& character) {
        container.push_back(new Char(character));
    }

    void append_back(const char* charArray) {
        container.push_back(new String(charArray));
    }

    // append_back float
    void append_back(const float& floater) {
        container.push_back(new Float(floater));
    }

    // append_back string
    void append_back(const string& stdString) {
        container.push_back(new String(stdString));
    }


    /*
    // returns a copy of the current list
    List* copy() {
        List *copiedList = new List();
        const int containerSize = container.size();
        for (size_t index = 0; index < containerSize; index++) {
            //copiedList->append_back(container[index]);
        }
        return copiedList;
    }

     */

    Object& operator[] (const int& index) const {
        return *container[index];
    }

    ostream&operator<<(ostream& os) const {
        os << '[';
        const int ListObjectSize = container.size() - 1;
        for (size_t index = 0; index < ListObjectSize; index++) {
            if (container[index]->__objectType__ == "<class 'String'>" ||
                container[index]->__objectType__ == "<class 'Char'>") {
                os << container[index]->__rrepr__() << ", ";
            } else {
                container[index]->operator<<(os) << ", ";
            }
        }
        if (container[ListObjectSize]->__objectType__ == "<class 'String'>" ||
            container[ListObjectSize]->__objectType__ == "<class 'Char'>") {
            os << container[ListObjectSize]->__rrepr__() << ']';
        } else {
            container[ListObjectSize]->operator<<(os) << ']';
        }
        return os;
    }

    string __type__() const {
        return __classType__;
    }

    string __id__() const {
        // smecherii cu stringstream
        return "123";
    }

    int __len__() const {
        return container.size();
    }

    bool containsStrings = false;
    void ContainsStrings(List ListObject) {
        if (ListObject.__type__() == "<class 'List'>") {
            const int size = ListObject.__len__();
            if (size > 0) {
                for (size_t index = 0; index < size; index++) {
                    if (ListObject[index].__type__() == "<class 'Char'>" ||
                        ListObject[index].__type__() == "<class 'String'>") {
                        containsStrings = true;
                        return;
                    } else if (ListObject[index].__type__() == "<class 'List'>"){
                        ContainsStrings((List &) ListObject[index]);
                    }
                }
            }
        }
    }

    string __repr__() {
        ContainsStrings(*this);
        if (containsStrings) {
            return "\"" + __rrepr__() + "\"";
        }
        return "'" + __rrepr__() + "'";
    }

    string __rrepr__() const {
        string content = "[";
        const int size = this->__len__() - 1;
        for (size_t index = 0; index < size; index++) {
            content += container[index]->__rrepr__() + ", ";
        }
        content += container[size]->__rrepr__() + "]";
        return content;
    }

};

#endif //PYTHONLIBRARIESINCPP_LIST_HPP