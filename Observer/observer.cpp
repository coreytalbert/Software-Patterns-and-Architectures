#include <iostream>
#include <string>
#include <vector>
#include <any>
using namespace std;

class Observer;

class Observable {
protected:
    vector<Observer *> observers;
public:
    virtual void notify() const = 0;
    void registerObserver(Observer *observer) {
        observers.push_back(observer);
    }
};

class Observer {
protected:
    //vector<Observable *> subjects; // For pulling from subjects
public:
    virtual void action(const string &) const = 0;
    void observe(Observable *subject) {
        //subjects.push_back(subject);
        subject->registerObserver(this);
    }
};

/*** Observers ***/

class People: public Observer {
public:
    People(string s) {
        name = s;
    }

    void action(const string &s) const override {
        cout << name << " is running away from a " << s << endl;
    }

protected:
    string name;
};

class Organization: public Observer {
public:
    Organization(string s) {
        name = s;
    }

    void action(const string &s) const override {
        cout << name << " is paying attention on a " << s << endl;
    }

protected:
    string name;
};

/*** Subjects ***/

class FireDept: public Observable {
    string location;
public:
    void setAlarm(string locat) {
        location = locat;
        notify();
    }

    void notify() const override {
        for (const Observer *observer : observers) {
            observer->action("fire alarm near " + location);
        }
    }
};

class PoliceDept: public Observable {
    string location;
public:
    void setAlarm(string locat) {
        location = locat;
        notify();
    }

    void notify() const override {
        for (const Observer *observer : observers) {
            observer->action("attack alarm near " + location);
        }
    }
};

int main() {
    FireDept fd;
    PoliceDept pd;

    People ken("Ken");
    ken.observe(&fd); //ken subscribes to fd

    People mary("Mary");
    mary.observe(&pd); //mary subscribes to pd

    Organization csusm("CSUSM");
    // CSUSM subscribes to fd, pd
    csusm.observe(&fd);
    csusm.observe(&pd);

    // fd, pd each broadcast alarm
    fd.setAlarm("Twin Oaks");
    pd.setAlarm("Freeway 78");
}
