/* CSCI 200: Lab 5: L5B - List test suite
 *
 * Author: Gabe Berta
 * Resources used (Class Slides):
 *
 * Completed functions to work with arrays
 */
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template<typename T>
class Array final : public IList<T> {
public:
    Array();
    ~Array();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;

private:
    int _size;
    int* _pArray;
};


template<typename T>
Array<T>::Array() {
    // set size to zero
    _size = 0;
    // set array to be a nullptr
    _pArray = nullptr;
}


template<typename T>
Array<T>::~Array() {
    // deallocate current array
    if(_pArray != nullptr){
       delete[] _pArray; 
    }
}

template<typename T>
int Array<T>::size() const { 
    return _size;
}

template<typename T>
T Array<T>::get(const int POS) const {
    //if POS is out of range, throw std::out_of_range exception
    if (POS < 0 || POS >= _size) {
        throw std::out_of_range("ERROR: OUT OF RANGE");
    }
    // return value at POS within array
    return _pArray[POS];
}



template<typename T>
void Array<T>::set(const int POS, const T VALUE) {
    // if POS is out of range, throw std::out_of_range exception
    if(POS < 0 || POS >= _size) {
        throw std::out_of_range("ERROR: OUT OF RANGE");
    }
    _pArray[POS] = VALUE;
    // set VALUE at POS within array    

}

template<typename T>
void Array<T>::insert(const int POS, const T VALUE) {
    // If POS is before zero, clamp to zero
    int clampAtIndex = std::max(0, POS);

    // If POS is after size, clamp to size
    clampAtIndex = std::min(clampAtIndex, _size);

    // Create a new array of size + 1
    T* tempArray = new T[_size + 1];

    // Copy elements 0 to POS from the old array to the new array
    for (int i = 0; i < clampAtIndex; i++) {
        tempArray[i] = _pArray[i];
    }

    // Set the element at POS in the new array to VALUE
    tempArray[clampAtIndex] = VALUE;

    // Copy elements POS to size from the old array to the new array
    for (int i = clampAtIndex; i < _size; i++) {
        tempArray[i + 1] = _pArray[i];
    }

    // Delete the old array
    delete[] _pArray;

    // Set the old array to be the new array
    _pArray = tempArray;

    // Increment the size
    _size++;
}

template<typename T>
void Array<T>::remove(const int POS) {
    // If array is empty, throw std::out_of_range exception
    if (_size == 0) {
        throw std::out_of_range("ERROR: Array is empty");
    }

    // If POS is before zero, clamp to zero
    int clampedAtIndex = std::max(0, POS);

    // If POS is after size, clamp to size
    clampedAtIndex = std::min(clampedAtIndex, _size - 1);

    // Create a new array of size - 1
    T* newArray = new T[_size - 1];

    // Copy elements from 0 to POS from the old array to the new array
    for (int i = 0; i < clampedAtIndex; i++) {
        newArray[i] = _pArray[i];
    }

    // Copy elements from POS+1 to size from the old array to the new array
    for (int i = clampedAtIndex + 1; i < _size; i++) {
        newArray[i - 1] = _pArray[i];
    }

    // Delete the old array
    delete[] _pArray;

    // Set the old array to be the new array
    _pArray = newArray;

    // Decrement the size
    --_size;
}

template<typename T>
T Array<T>::min() const {
    // If array is empty, throw std::out_of_range exception
    if (_size == 0) {
        throw std::out_of_range("ERROR: Array is empty");
    }

    // Find minimum value within the array
    T minValue = _pArray[0];
    for (int i = 1; i < _size; i++) {
        if (_pArray[i] < minValue) {
            minValue = _pArray[i];
        }
    }

    // Return the minimum value
    return minValue;
}

template<typename T>
T Array<T>::max() const {
    // If array is empty, throw std::out_of_range exception
    if (_size == 0) {
        throw std::out_of_range("ERROR: Array is empty");
    }

    // Find maximum value within the array
        T maxValue = _pArray[0];
    for (int i = 1; i < _size; i++) {
        if (_pArray[i] > maxValue) {
            maxValue = _pArray[i];
        }
    }

    // Return the maximum value
    return maxValue;
}



template<typename T>
int Array<T>::find(const T VALUE) const {
    // Search for the first occurrence of VALUE
    for (int i = 0; i < _size; i++) {
        if (_pArray[i] == VALUE) {
            // Return the index if found
            return i;
        }
    }
    
    // Return -1 if VALUE is not found
    return -1;
}

#endif//ARRAY_H