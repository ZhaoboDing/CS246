#include <iostream>
#include <utility>
#include "array.h"
using namespace std;

Array::Array() : arr{nullptr}, size{0}, capacity{0} {}

Array::Array(const Array &other)
        : arr{(other.capacity == 0) ? nullptr : new int[other.capacity]},
          size{other.size}, capacity{other.capacity} {
    // Can we use a range-based for loop here? Why or why not?
    for (int i = 0; i < other.size; i++) {
        arr[i] = other.arr[i];
    }
}

Array::Array(Array &&other)
        : arr{other.arr}, size{other.size}, capacity{other.capacity} {
    other.arr = nullptr;
}

Array &Array::operator=(const Array &other) {
    if (this == &other)
        return *this;
    Array copy{other};
    swap(copy.arr, this->arr);
    swap(copy.size, this->size);
    swap(copy.capacity, this->capacity);
    return *this;
}

Array &Array::operator=(Array &&other) {
    swap(other.arr, this->arr);
    swap(other.size, this->size);
    swap(other.capacity, this->capacity);
    return *this;
}

Array::~Array() { delete[] arr; }

Array::Iterator::Iterator(int *elem) : elem{elem} {}

Array::Iterator &Array::Iterator::operator++() {
    elem++;
    return *this;
}

bool Array::Iterator::operator!=(const Iterator &other) const {
    return elem != other.elem;
}

int &Array::Iterator::operator*() { return *elem; }

Array::Iterator Array::begin() const { return Iterator(arr); }

Array::Iterator Array::end() const { return Iterator(arr + size); }

void Array::doubleCap() {
    if (capacity == 0)
        capacity = 2;
    else
        capacity *= 2;
    int *newArr = new int[capacity];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

void Array::insert_back(int n) {
    if (size == capacity)
        doubleCap();

    arr[size] = n;
    size++;
}

void Array::remove_back() { size--; }

ostream &operator<<(ostream &out, Array &arr) {
    out << "Size: " << arr.size << " Capacity: " << arr.capacity << endl;
    for (int &n : arr) {
        out << n << " ";
    }
    out << endl;

    return out;
}
