
#include <iostream>
#include "builtins.py.h"
#include "exceptions.py.h"
#include <map>
using namespace std;

class Counter {
    map<int, int> frequency_dict_int;
    map<char, int> frequency_dict_char;

public:
    Counter() {

    }

    /*
        takes an array and returns a 
        map based on the frequency of the elements of the array
    */
    Counter(const int *array) {
        const int size = len(array);
        for(size_t index = 0; index < size; index++) {
            if (frequency_dict_int.find(array[index]) != frequency_dict_int.end()) {
                frequency_dict_int[array[index]]++;            
            }
            else {
                frequency_dict_int.insert(pair<int, int>(array[index], 1));
            }
        }
        frequency_dict_char.insert(pair<char, int>('0', -1));
    }

    Counter(const char *array) {
        const int size = len(array);
        for(size_t index = 0; index < size; index++) {
            if (frequency_dict_char.find(array[index]) != frequency_dict_char.end()) {
                frequency_dict_char[array[index]]++;            
            }
            else {
                frequency_dict_char.insert(pair<char, int>(array[index], 1));
            }
        }
        frequency_dict_int.insert(pair<int, int>(0, -1));
    }

    int operator [] (int value) const {
        map<int, int>::const_iterator iter = frequency_dict_int.find(value);
        if (iter == frequency_dict_int.end()) {
            throw ParameterError("invalid key for frequency dict, error at overloaded operator");
        }
        return iter->second;
    }

    int operator [] (char value) const {
        map<char, int>::const_iterator iter = frequency_dict_char.find(value);
        if (iter == frequency_dict_char.end()) {
            throw ParameterError("invalid key for frequency dict, error at overloaded operator");
        }
        return iter->second;
    }

    // prints the map on the screen 
    // format => python dict: {1: 2, }
    friend ostream& operator<< (ostream& os, const Counter &obj) {
        os << "{";
        if (obj.frequency_dict_char.find('0')->second == -1) {
            for(map<int, int>::const_iterator index = obj.frequency_dict_int.begin(); 
                index != obj.frequency_dict_int.end(); index++) {
                os << index->first << ":" << index->second << ", ";
            }
        }
        else {
            for(map<char, int>::const_iterator index = obj.frequency_dict_char.begin(); 
                index != obj.frequency_dict_char.end(); index++) {
                os << "\'"<< index->first << "\'" << ":" << index->second << ", ";
            }
        }
        os << "}";
        return os;
    }
};