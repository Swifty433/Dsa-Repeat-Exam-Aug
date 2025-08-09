#include "OrderedArray.h"

template <typename T>
OrderedArray<T>::OrderedArray(int grow_size) : data(nullptr), size(0), capacity(0), growSize(grow_size)
{
}

template <typename T>
OrderedArray<T>::OrderedArray() : data(nullptr), size(0), capacity(0), growSize(10)
{
}

template <typename T>
OrderedArray<T>::~OrderedArray() {
    delete[] data;
}

// Insert a new element into the ordered array
template <typename T>
void OrderedArray<T>::grow() {}

// inserts an element in the correct order
template <typename T>
void OrderedArray<T>::insertInOrder(const T& newElement) {}

// inserts an element into the array
template <typename T>
void OrderedArray<T>::push(const T& newElement) {}

// get the size of the array
template <typename T>
int OrderedArray<T>::length() const {}

// finds the element at the index
template <typename T>
T OrderedArray<T>::getElement(int index) const {}

// remove an element based on index
template <typename T>
bool OrderedArray<T>::remove(int index) {}

// search for an element in the array
template <typename T>
int OrderedArray<T>::search(const T& target) const {}

// Clears the array of elements
template <typename T>
void OrderedArray<T>::clear() {}