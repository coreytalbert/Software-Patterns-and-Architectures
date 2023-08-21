#pragma once
#include <string>
#include "FlyToSchool.hpp"
#include "WalkToSchool.hpp"
using namespace std;

class Factory {
public:
    GoToSchool *makeObject(const string &type) {
        if (type == "FlyToSchool") {
            return new FlyToSchool();
        }
        if (type == "WalkToSchool") {
            return new WalkToSchool();
        }
        return nullptr;
    }
};