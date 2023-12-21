/* CSCI 200: Lab 5: L5B - List test suite
 *
 * Author: Gabe Berta
 * Resources used (Class Slides):
 *
 * Completed functions to work with linked lists
 */
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"

#include <exception>
#include <iostream>
#include <string>

template<typename T>
struct Node {
    T value;
    Node<T>* pNext;
    Node<T>* pPrev;
};

template<typename T>
class LinkedList final : public IList<T> {
public:
    LinkedList();
    ~LinkedList();

    int size() const override;
    T get(const int POS) const override;
    void set(const int POS, const T VALUE) override;
    void insert(const int POS, const T VALUE) override;
    void remove(const int POS) override;
    T min() const override;
    T max() const override;
    int find(const T VALUE) const override;
    void sort() override;

private: 
    Node<T>* _pHead;
    Node<T>* _pTail;
    int _size;
};


template<typename T>
LinkedList<T>::LinkedList() {
  // set size to zero
  _size = 0;
  // set head to be a nullptr
  _pHead = nullptr;
  // set tail to be a nullptr
  _pTail = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    // remove each node in the list
    Node<T>* currentNode = _pHead;
    while (currentNode != nullptr) {
        Node<T>* nextNode = currentNode->pNext;
        delete currentNode;
        currentNode = nextNode;
    }
}


template<typename T>
int LinkedList<T>::size() const {
    return _size;
}

template<typename T>
T LinkedList<T>::get(const int POS) const {
    // if POS is out of range, throw std::out_of_range exception
    if(POS < 0 || POS >= _size) {
        throw std::out_of_range("ERROR: OUT OF RANGE");
    }
    // set current node to head
    Node<T>* currentNode = _pHead;
    
    // advance current node to POS
    for(int i = 0; i < POS; i++) {
        currentNode = currentNode->pNext;
    }
    // return value of current node
    return T(currentNode->value);
}

template<typename T>
void LinkedList<T>::set(const int POS, const T VALUE) {
// if POS is out of range, throw std::out_of_range exception
    if(POS < 0 || POS >= _size) {
        throw std::out_of_range("ERROR: OUT OF RANGE");
    }
// set current node to head
    Node<T>* currentNode = _pHead;
// advance current node to POS
    for(int i = 0; i < POS; i++) {
        currentNode = currentNode->pNext;
    }
// set value of current node   
    currentNode->value = VALUE;
  
}

template<typename T>
void LinkedList<T>::insert(const int POS, const T VALUE) {
    // if POS is before zero, clamp to zero
    int clampedPos = std::max(0, POS);
    // if POS is after size, clamp to size
    clampedPos = std::min(clampedPos, _size);

    // create pointer to new node
    Node<T>* newNode = new Node<T>;
    // set value to be VALUE
    newNode->value = VALUE;
    // set previous pointer to nullptr
    newNode->pPrev = nullptr;
    // set next pointer to nullptr
    newNode->pNext = nullptr;

    // if list is currently empty
    if (_size == 0) {
        // set head and tail to new node
        _pHead = newNode;
        _pTail = newNode;
    }
    // otherwise
    else {
        // if position is before head
        if (clampedPos == 0) {
            newNode->pNext = _pHead;
            _pHead->pPrev = newNode;
            _pHead = newNode;
        }
        // else if position is after tail
        else if (clampedPos == _size) {
            newNode->pPrev = _pTail;
            _pTail->pNext = newNode;
            _pTail = newNode;
            newNode->pNext = nullptr;
        }
        else {
            // set current node to head
            Node<T>* currentNode = _pHead;

            // advance current node to pos
            for (int i = 0; i < clampedPos; i++) {
                currentNode = currentNode->pNext;
            }

            // link new node into current list
            newNode->pNext = currentNode;
            newNode->pPrev = currentNode->pPrev;
            currentNode->pPrev->pNext = newNode;
            currentNode->pPrev = newNode;
        }
    }

    // increment size
    _size++;
}



template<typename T>
void LinkedList<T>::remove(const int POS) {
    // if list is empty, throw std::out_of_range exception
    if (_size == 0) {
        throw std::out_of_range("ERROR: List is empty");
    }

    // if POS is before zero, clamp to zero
    int clampedPos = std::max(0, POS);

    // if POS is after size, clamp to size
    clampedPos = std::min(clampedPos, _size - 1);

    // if list has one element
    if (_size == 1) {
        Node<T>* nodeToDelete = _pHead;
        _pHead = nullptr;
        _pTail = nullptr;
        delete nodeToDelete;
    }
    else {
        // if deleting head
        if (clampedPos == 0) {
            Node<T>* nodeToDelete = _pHead;
            _pHead = _pHead->pNext;
            _pHead->pPrev = nullptr;
            delete nodeToDelete;
        }
        // else if deleting tail
        else if (clampedPos == _size - 1) {
            Node<T>* nodeToDelete = _pTail;
            _pTail = _pTail->pPrev;
            _pTail->pNext = nullptr;
            delete nodeToDelete;
        }
        else {
            // set current node to head
            Node<T>* currentNode = _pHead;

            // advance current node to space before position
            for (int i = 0; i < clampedPos - 1; ++i) {
                currentNode = currentNode->pNext;
            }

            // set node to delete to the current node's next node
            Node<T>* nodeToDelete = currentNode->pNext;

            // unlink node to delete
            currentNode->pNext = nodeToDelete->pNext;
            nodeToDelete->pNext->pPrev = currentNode;

            // delete node
            delete nodeToDelete;
        }
    }

    // decrement size
    _size--;
}


template<typename T>
T LinkedList<T>::min() const {
    // if list is empty, throw std::out_of_range exception
    if (_size == 0) {
        throw std::out_of_range("ERROR: List is empty");
    }

    // find minimum value within list
    T minValue = _pHead->value;
    Node<T>* currentNode = _pHead->pNext;
    while (currentNode != nullptr) {
        if (currentNode->value < minValue) {
            minValue = currentNode->value;
        }
        currentNode = currentNode->pNext;
    }

    // return min value
    return minValue;
}


template<typename T>
T LinkedList<T>::max() const {
    // if list is empty, throw std::out_of_range exception
    if (_size == 0) {
        throw std::out_of_range("ERROR: List is empty");
    }

    // find maximum value within list
    T maxValue = _pHead->value;
    Node<T>* currentNode = _pHead->pNext;
    while (currentNode != nullptr) {
        if (currentNode->value > maxValue) {
            maxValue = currentNode->value;
        }
        currentNode = currentNode->pNext;
    }

    // return max value
    return maxValue;
}


template<typename T>
int LinkedList<T>::find(const T VALUE) const {
    // search for first occurrence of VALUE
    int index = 0;
    Node<T>* currentNode = _pHead;
    while (currentNode != nullptr) {
        if (currentNode->value == VALUE) {
            return index; // Return the index of the found value
        }
        currentNode = currentNode->pNext;
        index++;
    }

    // If value is not found, return -1
    return -1;
}
template<typename T>
void LinkedList<T>::sort() {
    if (_size <= 1) {
        return;
    }

    LinkedList<T> leftHalf;
    LinkedList<T> rightHalf;

    // Traverse the list to find the middle node
    Node<T>* middle = _pHead;
    while (middle && middle->pNext && middle->pNext->pNext) {
        _pTail = _pTail->pNext;
        middle = middle->pNext->pNext;
    }

    // Set the head and tail pointers for the left and right halves
    leftHalf._pHead = _pHead;
    leftHalf._pTail = _pTail;
    leftHalf._size = (_size + 1) / 2;

    rightHalf._pHead = middle->pNext;
    rightHalf._pTail = _pTail;
    rightHalf._size = _size / 2;

    leftHalf.sort();
    rightHalf.sort();

    Node<T>* leftCurrent = leftHalf._pHead;
    Node<T>* rightCurrent = rightHalf._pHead;

    if (leftCurrent->value <= rightCurrent->value) {
        _pHead = leftCurrent;
        leftCurrent = leftCurrent->pNext;
    } else {
        _pHead = rightCurrent;
        rightCurrent = rightCurrent->pNext;
    }

    Node<T>* current = _pHead;

    while (leftCurrent && rightCurrent) {
        if (leftCurrent->value <= rightCurrent->value) {
            current->pNext = leftCurrent;
            leftCurrent->pPrev = current;
            leftCurrent = leftCurrent->pNext;
        } else {
            current->pNext = rightCurrent;
            rightCurrent->pPrev = current;
            rightCurrent = rightCurrent->pNext;
        }
        current = current->pNext;
    }

    if (leftCurrent) {
        current->pNext = leftCurrent;
        leftCurrent->pPrev = current;
    }

    if (rightCurrent) {
        current->pNext = rightCurrent;
        rightCurrent->pPrev = current;
    }

    _pTail = current;

    while (_pTail->pNext) {
        _pTail = _pTail->pNext;
    }
}







#endif//LINKED_LIST_H