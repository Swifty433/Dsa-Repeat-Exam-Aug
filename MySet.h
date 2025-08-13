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
		//constructors
		MySet() : data() {} //default constructor
		MySet(int growSize) : data(growSize) {} //custom constructor with grow size

		//inserting elements only if not already present
		void insert(const T& element) 
		{
			if (data.search(element) < 0) 
			{
				data.push(element);
			}
		}

		//getting element at index
		T getElement(int index) const 
		{
			return data.getElement(index);
		}

		//getting the current length of array
		int length() const 
		{
			return data.length();

		}

		//removing an element at specific index
		bool remove(int index)
		{
			return data.remove(index);
		}

		//searching for an element
		int search(const T& target) const 
		{
			return data.search(target);
		}

		//clearing the set
		void clear() 
		{
			data.clear();
		}

		//Set & Set: - Returns a new set containing all elements common to both sets (Intersection)
		MySet<T> operator&(const MySet<T> other) const
		{
			
		}

		//Set | Set : - returns a new set containing all unique elements from each input set
		MySet<T> operator|(const MySet<T> other) const
		{

		}
};