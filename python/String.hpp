#ifndef PYTHONLIBRARIESINCPP_STRING_HPP
#define PYTHONLIBRARIESINCPP_STRING_HPP

#include <iostream>
#include "Object.hpp"
using namespace std;

class String : public Object {
    string __string__;
    const string __classType__ = "<class 'String'>";
public:
    explicit String(): __string__("") {
        __objectType__ = __classType__;
    }

    explicit String(const string &stdString) {
        __string__ = stdString;
        __objectType__ = __classType__;
    }

    ostream&operator<<(ostream& os) const {
        os << __string__;
        return os;
    }

    string __type__() const {
        return __classType__;
    }

    string __id__() const {
        return "0x123123";
    }

    int __len__() const {
        return __string__.size();
    }

    string __rrepr__() const {
        return "'" + __string__ + "'";
    }

    void operator+=(const char& character) {
        __string__ += character;
    }

    void operator+=(const string& basicString) {
        __string__ += basicString;
    }

    String operator+(const string& basicString) {
        return String(__string__ + basicString);
    }

    String operator+(const char& character) {
        return String(__string__ + character);
    }

    String&operator=(const string& basicString) {
        if (__string__ == basicString) {
            return *this;
        }
        __string__ = basicString;
        return *this;
    }

    String&operator=(const String& StringObject) {
        if (this == &StringObject) {
            return *this;
        }
        __string__ = StringObject.__string__;
        return *this;
    }

    bool operator!=(const string& basicString) {
        return __string__ != basicString;
    }

    bool operator!=(const char* charArray) {
        return __string__ != charArray;
    }

    bool operator!=(const char& character) {
        if (__string__.size() > 0) {
            return false;
        }
        return false;
    }

    bool operator==(const char* charArray) {
        return __string__ == charArray;
    }

    bool operator==(const String& StringObject) {
        return __string__ == StringObject.GetContent();
    }

    bool operator==(const String* StringObject) {
        return __string__ == StringObject->GetContent();
    }

    [[nodiscard]] string GetContent() const {
        return __string__;
    }

    Object&operator[](const int& index) const {
        throw exception();
    }

};

#endif //PYTHONLIBRARIESINCPP_STRING_HPP

/*
 *
 * static bool vowel(const char &character) {
        char ccharacter = toupper(character);
        switch(ccharacter)
        {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
        }
        return false;
    }

    static bool ContainsOnlyVowels(const char *charArray) {
        const int charArraySize = strlen(charArray);
        for(size_t index = 0; index < charArraySize; index++) {
            if (!vowel(charArray[index])) {
                return false;
            }
        }
        return true;
    }

    static bool ContainsOnlyVowels(const string &sstring) {
        const int sstringSize = sstring.size();
        for(size_t index = 0; index < sstringSize; index++) {
            if (!vowel(sstring[index])) {
                return false;
            }
        }
        return true;
    }

    static bool ContainsOnlyVowels(const String &sString) {
        const int sStringSize = sString.len();
        for(size_t index = 0; index < sStringSize; index++) {
            if (!vowel(sString[index])) {
                return false;
            }
        }
        return true;
    }

    static bool isPalindrome(const char *charArray) {
        int start = 0;
        int stop = strlen(charArray) - 1;
        bool result = true;
        while (start < stop) {
            if (charArray[start] != charArray[stop]) {
                return false;
            }
            start++;
            stop--;
        }
        return true;
    }

    static bool isPalindrome(const string &sstring) {
        int start = 0;
        int stop = sstring.size() - 1;
        bool result = true;
        while (start < stop) {
            if (sstring[start] != sstring[stop]) {
                return false;
            }
            start++;
            stop--;
        }
        return true;
    }

    static bool isPalindrome(const String &sString) {
        int start = 0;
        int stop = sString.len() - 1;
        bool result = true;
        while (start < stop) {
            if (sString[start] != sString[stop]) {
                return false;
            }
            start++;
            stop--;
        }
        return true;
    }
 *
 */