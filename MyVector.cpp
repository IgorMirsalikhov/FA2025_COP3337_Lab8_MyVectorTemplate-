#include "MyVector.hpp"
#include <iostream>

// Constructor
template <typename T>
MyVector<T>::MyVector(int capacity) : size(0) {
    this->capacity = capacity;
    elements = new T[capacity];
}

// Destructor
template <typename T>
MyVector<T>::~MyVector() {
    delete [] elements;
}

// Copy constructor
template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other) {
    size = other.size;
    capacity = other.capacity;
    elements = new T[capacity];

    //copy elements
    for(int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

template <typename T>
void MyVector<T>::push_back(const T& value) {
    if (size >= capacity) {
        allocate_memory(capacity * 2);
    }
    elements[size] = value;
    size++;
}

template <typename T>
T MyVector<T>::pop_back(void) {
    if (size > 0) {
        if (size - 1 < capacity / 2) {
            allocate_memory(capacity / 2);
        }
        return elements[--size];
    }
    else {
        // Throw an exception
        throw "The vector is empty!";
    }
}

template <typename T>
void MyVector<T>::print() const {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << elements[i] << ' ';
    }
    std::cout << "]\n"; 
}

template <typename T>
void MyVector<T>::allocate_memory(int memory_size) {
    capacity = memory_size;
    T *old = elements;
    // Allocate a new memory (bigger or smaller)
    elements = new T[memory_size];
    for (int i = 0; i < size; i++) {
        elements[i] = old[i];
    }
    // Deallocate the old memory
    delete [] old;
}

template <typename T>
T& MyVector<T>::at(int index) {
    if (index < size * -1 || index > size - 1) {
        throw "Invalid index";
    }
    if (index >= 0) {
        return elements[index];
    }
    else {
        return elements[size - (index * -1)];
    }
}

template <typename T>
void MyVector<T>::clear() {
    delete [] elements;
    size = 0;
    capacity = 10;
    
    elements = new T[capacity];
}

template <typename T>
int MyVector<T>::getSize() const {
    return size;
}

template <typename T>
void MyVector<T>::push_front(const T& value) {
    if (size >= capacity) {
        allocate_memory(capacity * 2);
    }
    for (int i = size; i >= 1; i--) {
        elements[i] = elements[i - 1]; 
    }
    elements[0] = value;
    size++;
}

template <typename T>
void MyVector<T>::insert(int pos, const T& value) {
    if (size == 0 && pos == -1) {
        push_back(value);
        return;
    }
    if (pos < size * -1  || pos > size - 1) {
        throw "Invalid index";
    }
    if (size >= capacity) {
        allocate_memory(capacity * 2);
    }
    if (pos < 0) {
        pos = size - (pos * -1);
    }
    for (int i = size; i >= pos; i--) {
        elements[i] = elements[i - 1]; 
    }
    elements[pos] = value;
    size++;
}
