#include "OrderedArray.h"
#include <iostream>


int main() {
	OrderedArray<int> arr;

    arr.push(5);
    arr.push(2);
    arr.push(8);
    arr.push(1);
    arr.push(3);

    std::cout << "Initial contents: ";
    arr.print();

    //show the length of array
    std::cout << "Length: " << arr.length() << "\n"; //returns the length of array

    //get the element at index
    std::cout << "Element at index 2: " << arr.getElement(2) << "\n"; //returns the element at specified index

    //get and element at an invalid index
    std::cout << "Element at index 10: " << arr.getElement(10) << "\n";  //returns 0 if no elements are found
}