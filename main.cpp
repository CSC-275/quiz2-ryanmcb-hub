#include <iostream>
#include <cmath>
using namespace std;

//------------Circle Class-----------
class Circle {
private:
    double m_radius; // radius circle This is private in UML?

    //protected for cylinder
protected:
    double m_area; //area of circle
    void calcArea(double radius) {
        m_area = M_PI * radius * radius;
    }

public:
    Circle() {
        m_radius = 1.0;
        m_area = 3.14; //default values from example output in readme
    }

    Circle(double radius) {
        m_radius = radius;
        calcArea(radius); //calc area from radius
    }

    //this didn't work unless it was virtual
    virtual void display() {
        cout << fixed; //displayed in fixed-point notation
        cout.precision(2); //set decimal place to 2
        cout << "\nThe area of a circle with ...\n";
        cout << "a radius of " << m_radius << " inches\n";
        cout << "has an area of " << m_area << " square inches." << endl;
    }

    // Give access to protected data for derived class-
    //m_radius is private in the uml diagram cant just do cout << m_radius
    //only private in circle object? Not sure if marked Incorrectly?
    double getRadius() const { return m_radius; }
};

//------------Cylinder Class-----------
class Cylinder : public Circle {
private:
    double m_height; // height of the cylinder
    double m_volume; // volume of the cylinder

    //r=radius h=volume
    double calcVolume(double r, double h) {
        return M_PI * r * r * h; // volume = Pi r²h uses cmath
    }

public:
    Cylinder(double r, double h) : Circle(r) {
        m_height = h;
        m_volume = calcVolume(r, h);
    }

    void display() { //overide circle
        cout << fixed;
        cout.precision(2);
        cout << "\nThe area of a circle with ...\n";
        cout << "a radius of " << getRadius() << " inches\n";
        cout << "has an area of " << m_area << " square inches." << endl;
        cout << "And the volume of a Cylinder with...\n";
        cout << "a circular end area of " << m_area << " square inches\n";
        cout << "and a height of " << m_height << " inches" << endl;
        cout << "has a volume of " << m_volume << " cubic inches." << endl;
    }
};

int main() {
    Circle c1, c2(5.25); //c1 default c2 parameter
    c1.display();
    c2.display();
    Circle *cl1 = new Cylinder(3.5, 8.65); //dynamic
    cl1->display();
    return 0;
}
