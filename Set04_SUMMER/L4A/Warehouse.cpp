// CSCI 200: Lab 4A Inventory Management
// Author: Gabe Berta
// Resources used: Class slides and ChatGPT for debugging 
// 
// 
// .

/**
 * @file Warehouse.cpp
 * @author Gabriel Berta
 * @brief This program creates classes and uses deep and shallow copies via the copy constructor and assignment operator. It also includes the deconstructor
 * @version 0.1
 * @date 2023-06-09
 * 
 * 
 * 
 */

#include "Warehouse.h"

using namespace std;

Warehouse::Warehouse() {
    _pBoxen = new vector<Box*>;
}

//Copy Constructror
Warehouse::Warehouse(const Warehouse& OTHER) {
    _pBoxen = new vector<Box*>;
    int temp = OTHER.getNumberOfBoxes(); 
    for (int i = 0; i < temp; i++) {
        _pBoxen->push_back(new Box(*OTHER.getBox(i)));  // Create a new Box object and copy the values
    }
}
//Destructor
Warehouse::~Warehouse(){
}

//copy Assignment Operator
Warehouse& Warehouse::operator=(const Warehouse& OTHER) {
    if (this == &OTHER) {
        return *this;  // Self-assignment check
    }

    // Delete the existing data
    delete _pBoxen;

    // Copy the data from OTHER to the current object
    _pBoxen = new vector<Box*>;
    int temp = OTHER.getNumberOfBoxes();
    for (int i = 0; i < temp; i++) {
        _pBoxen->push_back(OTHER.getBox(i));
    }

    return *this;
}








void Warehouse::storeInBox(const int SIZE) {
    _pBoxen->push_back( new Box(SIZE) );
}

Box* Warehouse::getBox(const int BOX_POS) const {
    return _pBoxen->at(BOX_POS);
}

int Warehouse::getNumberOfBoxes() const {
    return _pBoxen->size();
}

std::ostream& operator<<(ostream& os, const Warehouse& WH) {
    os << "Warehouse has " << WH.getNumberOfBoxes() << " boxes (";
    for(int i = 0; i < WH.getNumberOfBoxes(); i++) {
        os << WH.getBox(i)->getBoxSize();
        if(i < WH.getNumberOfBoxes() - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}