#pragma once
#include "GoToSchool.hpp"
using namespace std;

class FlyToSchool: public GoToSchool {
    void takeTransit() const override {
        cout << "We are taking a flight." << endl;
    }
    void arrive() const override {
        cout << "After 2 hours, we arrive." << endl;
    }
};