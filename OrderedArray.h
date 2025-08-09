#pragma once

//Templated Class
template <typename T>
class OrderedArray {
private:
    T* data;
    int size;
    int capacity;
    int growSize;

    void grow();
    void insertInOrder(const T& newElement);

public:
    OrderedArray(int grow_size);
    OrderedArray();
    ~OrderedArray();

    void push(const T& newElement);
    int length() const;
    T getElement(int index) const;
    bool remove(int index);
    int search(const T& target) const;
    void clear();
    void print() const;

};