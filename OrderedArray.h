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

    void push(const T& newElement); //Puts element into the array in order
    int length() const; //Returns the number of elements in the array
    T getElement(int index) const; //Returns a copy of element at index given
    bool remove(int index); //Takes in index of an element and removes it from the array
    int search(const T& target) const; //searches for element at specific index
    void clear(); //Empties the array
    //void print() const; //Allows printing to console
};