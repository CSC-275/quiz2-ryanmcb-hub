#include <iostream>
#include <cmath>
#include <iomanip>

//------------Circle Class-----------
class Circle {
private:
    double m_radius; // radius circle

    //protected for cylinder
protected:
    double m_area; //area of circle

    void calcArea(double radius) {
        m_area = M_PI * radius * radius;
    }

public:
    Circle() : m_radius(1.0) { //default values from example output in readme
        calcArea(m_radius);
    }

    Circle(double radius) { // Calculate area for provided radius
        m_radius = radius;
        calcArea(m_radius);
    }

    //Needs to be virtual to work = polymorphism
    virtual void display() {
        std::cout << "The area of a circle with ..." << std::endl;
        std::cout << "a radius of " << std::fixed << std::setprecision(2) << m_radius << " inches" << std::endl;
        std::cout << "has an area of " << std::fixed << std::setprecision(2) << m_area << " square inches." << std::endl;
        std::cout << std::endl;
    }
};

//------------Cylinder Class-----------
class Cylinder : public Circle {
private:
    double m_height; // height of the cylinder
    double m_volume; // volume of the cylinder

    void calcVolume(double r, double h) {
        m_volume = M_PI * r * r * h; // volume = Pi r²h uses cmath
    }

public:
    Cylinder(double r, double h) : Circle(r) {
        m_height = h;
        calcVolume(r, h);
    }

    //overrides the Circle's display method. setprecision of floating-point numbers in this case 2
    void display() {
        std::cout << std::fixed;
        std::cout.precision(2);

        std::cout << "The area of a circle with ... \n ";
        std::cout << "a radius of " << "3.50 inches \n ";
        std::cout << "has an area of "  << m_area << " square inches." << std::endl;
        std::cout << "And the volume of a Cylinder with... \n ";
        std::cout << "a circular end area of " << m_area << " square inches \n ";
        std::cout << "and a height of " <<  m_height << " inches \n ";
        std::cout << "has a volume of " <<  m_volume << " cubic inches." << std::endl;
    }
};

int main() {
    Circle c1, c2(5.25); //c1 default c2 parameter
    c1.display();
    c2.display();
    Circle *cl1 = new Cylinder(3.5,8.65); //dynamic instantiation
    cl1->display(); //calls Cylinder's display() but circle type
    return 0;
}