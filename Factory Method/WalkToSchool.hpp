#pragma once
#include "GoToSchool.hpp"
using namespace std;

class WalkToSchool: public GoToSchool {
    void takeTransit() const override {
        cout << "We are walking to school." << endl;
    }
    void arrive() const override {
        cout << "After 10 minutes, we arrive." << endl;
    }
};