#include "OrderedArray.h"
#include <iostream>

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
void OrderedArray<T>::grow() {
    capacity += growSize;
    T* newData = new T[capacity];

    for (int i = 0; i < size; ++i)
    {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
}

// inserts an element in the correct order
template <typename T>
void OrderedArray<T>::insertInOrder(const T& newElement) {
    int insertIndex = 0;

    while (insertIndex < size && data[insertIndex] < newElement) {
        ++insertIndex;
    }

    for (int i = size; i > insertIndex; --i)
    {
        data[i] = data[i - 1]; // moves the element to the right
    }
    data[insertIndex] = newElement;
    ++size;
}

// inserts an element into the array
template <typename T>
void OrderedArray<T>::push(const T& newElement) {
    if (size >= capacity) {
        grow();
    }
    insertInOrder(newElement);
}

// get the size of the array
template <typename T>
int OrderedArray<T>::length() const {
    return size;
}

// finds the element at the index
template <typename T>
T OrderedArray<T>::getElement(int index) const {
    if (index < 0 || index >= size) {
        return T(); 
    }
    return data[index];
}

// remove an element based on index
template <typename T>
bool OrderedArray<T>::remove(int index) {
    if (index < 0 || index >= size) {
        std::cout << "No Element at specific index - ";
        return false;
    }
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
    return true;
}

// search for an element in the array
template <typename T>
int OrderedArray<T>::search(const T& target) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] == target) {
            return i;
        }
    }
    return -1; // not found
}

// Clears the array of elements
template <typename T>
void OrderedArray<T>::clear() {
    size = 0;
}

template <typename T>
void OrderedArray<T>::print() const {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
// Explicit instantiations (inspired by Modernes C++ blog example):
// template class MyClass<int>; etc.
// Explicit template instantiations
template class OrderedArray<int>;
template class OrderedArray<float>;
template class OrderedArray<double>;
template class OrderedArray<std::string>;