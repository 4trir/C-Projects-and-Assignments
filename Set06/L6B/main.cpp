/**
 * @file main.cpp
 * @author Gabe Berta
 * @brief tests search functions
 * Resources used: class slides, chatgpt for debugging
 * @version 0.1
 * @date 2023-06-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LinkedList.hpp"
#include "Array.hpp"

int main() {
    srand(time(0));
    int implementationChoice;
    std::cout << "Choose list implementation:\n";
    std::cout << "1. Array\n";
    std::cout << "2. Linked List\n";
    std::cin >> implementationChoice;

    int n;
    std::cout << "Enter the number of integers to store in the list: ";
    std::cin >> n;

    int min, max;
    std::cout << "Enter the smallest and largest values to generate: ";
    std::cin >> min >> max;

    Array<int> array;
    LinkedList<int> linkedList;

    if (implementationChoice == 1) {
        for (int i = 0; i < n; i++) {
            array.insert(i ,rand() % (max - min + 1) + min);
        }
    } else if (implementationChoice == 2) {
        for (int i = 0; i < n; i++) {
            linkedList.insert(i, rand() % (max - min + 1) + min);
        }
    }

    std::cout << "Original List: ";
    for (int i = 0; i < n; i++) {
        if (implementationChoice == 1) {
            std::cout << array.get(i) << " ";
        } else if (implementationChoice == 2) {
            std::cout << linkedList.get(i) << " ";
        }
    }
std::cout << std::endl;

    std::cout << std::endl;

    if (implementationChoice == 1) {
        array.sort();
    } else if (implementationChoice == 2) {
        linkedList.sort();
    }

    std::cout << "Sorted List: ";
    for (int i = 0; i < n; i++) {
        if (implementationChoice == 1) {
            std::cout << array.get(i) << " ";
        } else if (implementationChoice == 2) {
            std::cout << linkedList.get(i) << " ";
        }
    }
    std::cout << std::endl;

    int numValues;
    std::cout << "How Many Values Would You Like to Search For?" << std::endl;
    std::cin >> numValues;

    std::vector<int> target;

    for (int i = 0; i < numValues; i++) {
        int x;
        std::cin >> x;
        target.push_back(x);
    }

    std::cout << "Search Results: ";
    if (implementationChoice == 1) {
        for (unsigned int i = 0; i < target.size(); i++) {
            int index = array.search(target[i]);
            if (index != -1) {
                std::cout << "Found at index " << index << std::endl;
            } else {
                std::cout << "Not found" << std::endl;
            }
        }
    } else if (implementationChoice == 2) {
        for (unsigned int i = 0; i < target.size(); i++) {
            int index = linkedList.search(target[i]);
            if (index != -1) {
                std::cout << "Found at index " << index << std::endl;
            } else {
                std::cout << "Not found" << std::endl;
            }
        }
    }

    return 0;
}
