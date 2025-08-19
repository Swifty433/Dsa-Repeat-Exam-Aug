#pragma once
#include "headers.h"

//Templated Class
//Stores elements in ascending order according to their natural ordering
//use of dyanmic array the will resize when capacity is reached
template <typename T>
class OrderedArray {
private:
    //Variables
    T* data; //Pointer to the array
    int size; //current number of elements in array
    int capacity; //total capacity of the array
    int growSize; //number of elements the array grows by

    void grow(); //resizes array by growsize
    void insertInOrder(const T& newElement); //inserts an element into its correct position

public:
    OrderedArray(int grow_size); //Lets user decide by how much the want array to grow when needed to be resized
    OrderedArray(); //Default constructor, Defaults to sensible value
    ~OrderedArray(); //Destructor to free all memory, including what which is dynamically allocated by it

    // Copy constructor and assignment operator (Rule of Three)
    OrderedArray(const OrderedArray& other);
    OrderedArray& operator=(const OrderedArray& other);

    void push(const T& newElement); //Puts element into the array in order
    int length() const; //Returns the number of elements in the array
    T getElement(int index) const; //Returns a copy of element at index given
    bool remove(int index); //Takes in index of an element and removes it from the array
    int search(const T& target) const; //searches for element at specific index
    void clear(); //Empties the array
    //void print() const; //Allows printing to console
};

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

// Copy constructor
// Creates a new OrderedArray as a copy of another
template <typename T>
OrderedArray<T>::OrderedArray(const OrderedArray& other)
    : size(other.size), capacity(other.capacity), growSize(other.growSize)
{
    if (capacity > 0) {
        data = new T[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
	}
    else {
        data = nullptr;
    }
}

// Assignment operator
// Assigns the contents of one OrderedArray to another
template <typename T>
OrderedArray<T>& OrderedArray<T>::operator=(const OrderedArray& other)
{
    if (this != &other) {
        delete[] data;

        size = other.size;
        capacity = other.capacity;
        growSize = other.growSize;

        if (capacity > 0) {
            data = new T[capacity];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        else {
            data = nullptr;
        }
    }
    return *this;
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