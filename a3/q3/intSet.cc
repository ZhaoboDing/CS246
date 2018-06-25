#include <iostream>
#include <utility>
#include "intSet.h"

array::array() {
  capacity = length = 0;
  arr = NULL;
}

array::~array() {
  delete[] arr;
}

void array::extend() {
  if (capacity) {
    capacity <<= 1;
    int *tmp = new int[capacity];
    for (int i = 0; i < length; i++)
      tmp[i] = arr[i];

    delete[] arr;
    arr = tmp;
  }
  else {
    capacity = 10;
    arr = new int[capacity];
  }
}

void array::add(int k) {
  int l = 0, r = length - 1;

  while (l <= r) {
    int mid = (l + r) >> 1;
    if (arr[mid] == k)
      return;
    if (k < arr[mid])
      r = mid - 1;
    else
      l = mid + 1;
  }

  if (capacity == length)
    extend();
  for (int i = length; i > l; i--)
    arr[i] = arr[i - 1];
  // Move the elements in reverse order to avoid losing data

  arr[l] = k;
  length++;
  return;
}

intSet::intSet() {
  return;
}

intSet::intSet(const intSet &is) {
  set = is.set;
}

intSet::~intSet() {
  return;
}

intSet::intSet(intSet &&is) {
  set.capacity = is.set.capacity;
  set.length = is.set.length;
  set.arr = is.set.arr;

  is.set.arr = NULL;
  is.set.capacity = is.set.length = 0;
}

intSet &intSet::operator=(const intSet &is) {
  set.capacity = is.set.capacity;
  set.length = is.set.length;
  set.arr = new int[set.capacity];
  for (int i = 0; i < set.length; i++)
    set.arr[i] = is.set.arr[i];

  return *this;
}

void swapInt(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

void swapArr(int *a, int *b) {
  int *t = a;
  a = b;
  b = t;
}

intSet &intSet::operator=(intSet &&is) {
  std::swap(set.capacity, is.set.capacity);
  std::swap(set.length, is.set.length);
  std::swap(set.arr, is.set.arr);
  return *this;
}

void intSet::swap(intSet &is) {
  std::swap(set.length,   is.set.length  );
  std::swap(set.capacity, is.set.capacity);
  std::swap(set.arr,      is.set.arr     );
}

intSet intSet::operator|(const intSet &other) {
  intSet ans;
  int i = 0, j = 0;

  while (i < set.length && j < other.set.length)
    if (set.arr[i] == other.set.arr[j]) {
      ans.set.add(set.arr[i]);
      i++;
      j++;
    }
    else if (set.arr[i] < other.set.arr[j]) {
      ans.set.add(set.arr[i]);
      i++;
    }
    else {
      ans.set.add(other.set.arr[j]);
      j++;
    }

  for (int t = i; t < set.length; t++)
    ans.set.add(set.arr[t]);
  for (int t = j; t < other.set.length; t++)
    ans.set.add(other.set.arr[t]);

  return ans;
}

intSet intSet::operator&(const intSet &other) {
  intSet ans;
  int i = 0, j = 0;

  while (i < set.length && j < other.set.length)
    if (set.arr[i] == other.set.arr[j]) {
      ans.set.add(set.arr[i]);
      i++;
      j++;
    }
    else if (set.arr[i] < other.set.arr[j])
      i++;
    else
      j++;

  return ans;
}

bool intSet::operator==(const intSet &other) {
  if (set.length != other.set.length)
    return false;

  for (int i = 0; i < set.length; i++)
    if (set.arr[i] != other.set.arr[i])
      return false;

  return true;
}

bool intSet::isSubset(const intSet &s) {
  int p = 0;

  for (int i = 0; i < s.set.length; i++) {
    while (p < set.length && set.arr[p] < s.set.arr[i])
      p++;
    if (p == set.length || s.set.arr[i] < set.arr[p])
      return false;
  }

  return true;
}

bool intSet::contains(int e) {
  int l = 0, r = set.length - 1;

  // Since the array is ordered, we can perform a binary search
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (set.arr[mid] == e)
      return true;
    if (e < set.arr[mid])
      r = mid - 1;
    else
      l = mid + 1;
  }

  return false;
}

void intSet::add(int e) {
  set.add(e);
}

void intSet::remove(int e) {
  int l = 0, r = set.length - 1;

  while (l <= r) { // Binary search
    int mid = (l + r) >> 1;
    if (set.arr[mid] == e) {
      set.length--;
      for (int i = mid; i < set.length; i++)
        set.arr[i] = set.arr[i + 1];
        break;
    }
    if (e < set.arr[mid])
      r = mid - 1;
    else
      l = mid + 1;
  }
}

std::ostream& operator<<(std::ostream &out, const intSet &is) {
  out << '(';
  for (int i = 0; i < is.set.length; i++) {
    if (i > 0)
      out << ","; // The first element does not need a prefixed comma
    out << is.set.arr[i];
  }
  out << ')';
  return out;
}
