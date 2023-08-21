#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Lego {
public:
    virtual void play() const = 0;
};

class LegoBrick1X1: public Lego {
private:
    string color;
public:
    LegoBrick1X1(const string &val): color(val) {}
    void play() const override {
        cout << "A " << color << " Lego 1X1 brick" << endl;
    }
};

class LegoBrick1X2: public Lego {
private:
    string color;
public:
    LegoBrick1X2(const string &val): color(val) {}
    void play() const override {
        cout << "A " << color << " Lego 1X2 brick" << endl;
    }
};

class LegoBrick2X2: public Lego {
private:
    string color;
public:
    LegoBrick2X2(const string &val): color(val) {}
    void play() const override {
        cout << "A " << color << " Lego 2X2 brick" << endl;
    }
};

class LegoFigure: public Lego {
private:
    string occupation;
public:
    LegoFigure(const string &val): occupation(val) {}
    void play() const override {
        cout << "A " << occupation << " Lego figure." << endl;
    }
};

class LegoProduct: public Lego {
private:
    vector<Lego *> children;
    string name;
public:
    LegoProduct(const string &val): name(val) {}
    void add(Lego *child) {
        children.push_back(child);
    }
    void play() const override {
        cout << "A Lego " << name << " that contains: " << endl;
        for (const Lego *child : children) {
            child->play();
        }
    }
};

int main() {
    LegoBrick1X1 brick1("red");
    LegoBrick1X2 brick2("yellow");
    LegoBrick2X2 brick3("blue");
    LegoBrick2X2 brick4("green");

    LegoFigure figure1("prince");
    LegoFigure figure2("princess");
    LegoFigure figure3("knight");

    LegoProduct product1("castle");
    LegoProduct product2("kingdom");

    product1.add(&brick1);
    product1.add(&brick2);
    product1.add(&brick3);
    product1.add(&brick4);

    product2.add(&figure1);
    product2.add(&figure2);
    product2.add(&figure3);
    product2.add(&product1);
    product2.play();

    return 1;
}
