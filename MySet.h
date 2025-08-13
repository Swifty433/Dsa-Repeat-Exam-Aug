//Part 2 - Setting up a Set class using OrderedArray
//I need to use Overloading to perfrom Set | Set and Set & Set operations

#pragma once
#include "headers.h"
#include "OrderedArray.h"

template <typename T>
class MySet {
	private:
		OrderedArray<T> data;

	public:
		// Constructors
		MySet();                   // Default constructor
		MySet(int growSize);        // Custom constructor with grow size

		// Methods
		void insert(const T& element);
		T getElement(int index) const;
		int length() const;
		bool remove(int index);
		int search(const T& target) const;
		void clear();

		// Operator overloads
		MySet<T> operator&(const MySet<T>& other) const; // Intersection
		MySet<T> operator|(const MySet<T>& other) const; // Union
};

//constructors
template <typename T>
MySet<T>::MySet() : data() {}

template <typename T>
MySet<T>::MySet(int growSize) : data(growSize) {}

//inserting elements only if not already present
template <typename T>
void MySet<T>::insert(const T& element)
{
	if (data.search(element) < 0)
	{
		data.push(element);
	}
}

//getting element at index
template <typename T>
T MySet<T>::getElement(int index) const
{
	return data.getElement(index);
}

//getting the current length of array
template <typename T>
int MySet<T>::length() const
{
	return data.length();

}

//removing an element at specific index
template <typename T>
bool MySet<T>::remove(int index)
{
	return data.remove(index);
}

//searching for an element
template <typename T>
int MySet<T>::search(const T& target) const
{
	return data.search(target);
}

//clearing the set
template <typename T>
void MySet<T>::clear()
{
	data.clear();
}

//Set & Set: - Returns a new set containing all elements common to both sets (Intersection)
template <typename T>
MySet<T> MySet<T>::operator&(const MySet<T>& other) const 
{

}

//Set | Set : - returns a new set containing all unique elements from each input set
template <typename T>
MySet<T> MySet<T>::operator|(const MySet<T>& other) const 
{

}