//BACKUP - Project: OrderedArray & MySet
//Part 1 - OrderedArray Implementation
//I need to use a dynamic array that will automatically resize when capacity is reached and implement the functions in the doc

#include "OrderedArray.h"

//COnstructor 
template <typename T>
OrderedArray<T>::OrderedArray(int grow_size) : data(nullptr), size(0), capacity(0), growSize(grow_size)
{
}

//Default constructor - starts with growsize 10
template <typename T>
OrderedArray<T>::OrderedArray() : data(nullptr), size(0), capacity(0), growSize(10)
{
}

//destructor - frees up dynamic memory being used
template <typename T>
OrderedArray<T>::~OrderedArray() {
    delete[] data;
}

// Insert a new element into the ordered array
template <typename T>
void OrderedArray<T>::grow() {
    capacity += growSize; //increases the total space
    T* newData = new T[capacity]; //allocate a bigger array

    //copys over all the old data into the new array
    for (int i = 0; i < size; ++i)
    {
        newData[i] = data[i];
    }

    delete[] data; //removes the old array
    data = newData; //points to the new array
}

// inserts an element in the correct order
template <typename T>
void OrderedArray<T>::insertInOrder(const T& newElement) {
    int insertIndex = 0;

    //searches for the first spot where to place element
    while (insertIndex < size && data[insertIndex] < newElement) {
        ++insertIndex;
    }

    //move everything one step to the right to create gap
    for (int i = size; i > insertIndex; --i)
    {
        data[i] = data[i - 1]; // moves the element to the right
    }
    data[insertIndex] = newElement; //drop new value into place
    
    //comment out when no longer needed
    std::cout << "new element added \n";

    ++size; //size increases as new element is added
}

// inserts an element into the array
template <typename T>
void OrderedArray<T>::push(const T& newElement) {
    //if there is no room we shall make MORE!!!!!
    if (size >= capacity) {
        grow();
    }
    insertInOrder(newElement);
}

// get the size of the array - not capacity
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
        return false; //returns false if no element exisits
    }
    //moves everything to the left to the left
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size; //element size is one less now
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

////this prints all the values in the array in correct order
//template <typename T>
//void OrderedArray<T>::print() const {
//    for (int i = 0; i < size; ++i) {
//        std::cout << data[i] << " ";
//    }
//    std::cout << std::endl;
//}

//this is refrenced in my readme file
// Explicit instantiations (inspired by Modernes C++ blog example):
// template class MyClass<int>; etc.
// Explicit template instantiations
//template class OrderedArray<int>;
//template class OrderedArray<float>;
//template class OrderedArray<double>;
//template class OrderedArray<std::string>;