// A simple dynamicly resized array implementation
#ifndef __ARRAY_H__
#define __ARRAY_H__
#include <iostream>

class Array {
    int *arr;
    int size;
    int capacity;

    void doubleCap();

public:
    Array();
    Array(const Array &other);
    Array(Array &&other);
    Array &operator=(const Array &other);
    Array &operator=(Array &&other);
    ~Array();

    class Iterator {
        int *elem;
        // only methods in Array could create iterators.
        explicit Iterator(int *elem);

    public:
        Iterator &operator++();
        bool operator!=(const Iterator &other) const;
        int &operator*();

        friend class Array;
    };

    Iterator begin() const;
    Iterator end() const;
    void insert_back(int n);
    void remove_back();
    friend std::ostream &operator<<(std::ostream &out, Array &arr);
};

std::ostream &operator<<(std::ostream &out, Array &arr);
#endif
