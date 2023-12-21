/**
 * @file main.cpp
 * @author Gabe Berta
 * @brief tests sort functions
 * Resources used: class slides, chatgpt for debugging
 * @version 0.1
 * @date 2023-06-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Array.hpp"
#include "LinkedList.hpp"
#include "List.hpp"
#include <iostream>
#include<cstdlib>
#include<ctime>

int main() {
    srand(time(0));
    Array<int>* test = new Array<int>();
    for(int i = 0; i < 10; i++) {
        test->insert(i, rand() % (10) + 1);
    }

    test->sort();
    for(int i = 0; i < test->size(); i++) {
        std::cout << test->get(i) << " ";
    }
    std::cout << std::endl;
    delete test;

    LinkedList<int>* list = new LinkedList<int>();

    list->insert(0, 5);
    list->insert(1, 4);
    list->sort();
    std::cout << list->get(0) << std::endl;

    delete list;
    return 0;
    
    

    return 0;
}