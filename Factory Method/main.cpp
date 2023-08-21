#include "Factory.h"
using namespace std;

int main() {
    Factory f;
    GoToSchool *walk = f.makeObject("WalkToSchool");
    walk->go();
    GoToSchool *fly = f.makeObject("FlyToSchool");
    fly->go();
}
