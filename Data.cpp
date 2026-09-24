//
// Created by steph on 9/17/2026.
//

#include "Data.h"

#include <iostream>
#include <ostream>
#include <string>
using namespace std;
class Data {
    public:
    int numID;
    string name;

    Data(int numID, string name) {
        this->numID = numID;
        this->name = name;
    }
    void print() {
        cout<<numID<<" "<<name<<endl;
    }
};
