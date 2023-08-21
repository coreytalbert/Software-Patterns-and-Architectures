#pragma once
#include <iostream>
using namespace std;

class GoToSchool {
    void getUp() const {
        cout << "Get up." << endl;
    }
    void eatBreakfast() const {
        cout << "Eat breakfast." << endl;
    }
    virtual void takeTransit() const {
        cout << "Take school bus." << endl;
    }
    virtual void arrive() const = 0;
public:
    void go() const {
        getUp();
        eatBreakfast();
        takeTransit();
        arrive();
    }
};