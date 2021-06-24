#ifndef PYTHONLIBRARIESINCPP_STL_VECTOR_IMPLEMENTATION_HPP
#define PYTHONLIBRARIESINCPP_STL_VECTOR_IMPLEMENTATION_HPP

#include <iostream>

using namespace std;


struct object {
    virtual void printt() const = 0;
    virtual ostream &operator<<(ostream &os) const = 0;

    friend ostream &operator<<(ostream &os, const object *obj) {
        obj->operator<<(os);
        return os;
    }

    friend ostream &operator<<(ostream &os, const object& obj) {
        obj.operator<<(os);
        return os;
    }

};

struct Intt : public object {
    int x;

    Intt(int _x) {
        x = _x;
    }

    void printt() const {
        cout << "123123";
    }

    ostream&operator<<(ostream& os) const {
        os << x;
        return os;
    }
};

struct list : public object {
    object **l;
    int dim = 0;

    list() {

    }

    list(list& x) {
        l = new object*[x.dim];
        for (int i = 0; i < x.dim; ++i) {
            l[i] = x.l[i];
        }
        dim = x.dim;
    }

    void append(int x) {
        if (dim == 0) {
            l = new object*[1];
            l[0] = new Intt(x);
            dim++;
        } else {
            object **temp = new object*[dim];
            for (int i = 0; i < dim; ++i) {
                temp[i] = l[i];
            }
            l = new object*[dim + 1];
            for (int i = 0; i < dim + 1; ++i) {
                l[i] = temp[i];
            }
            l[dim++] = new Intt(x);
        }
    }

    void append(list x) {
        if (dim == 0) {
            l = new object*[1];
            l[0] = new list(x);
            dim++;
        } else {
            object **temp = new object*[dim];
            for (int i = 0; i < dim; ++i) {
                temp[i] = l[i];
            }
            l = new object*[dim + 1];
            for (int i = 0; i < dim + 1; ++i) {
                l[i] = temp[i];
            }
            l[dim++] = new list(x);
        }
    }

    ostream&operator<<(ostream& os) const {
        os << '[';
        for (int i = 0; i < dim - 1; ++i) {
            os << l[i] << ", ";
        }
        os << l[dim - 1] << ']';
        return os;
    }

    object& operator[](const int &index) {
        return *l[index];
    }

    void printt() const {
        cout << "123";
    }

};

#endif //PYTHONLIBRARIESINCPP_STL_VECTOR_IMPLEMENTATION_HPP