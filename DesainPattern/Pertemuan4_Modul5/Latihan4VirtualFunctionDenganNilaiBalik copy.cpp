#include <iostream>
using namespace std;

class Shape
{
public:
    virtual float getArea()
    { // fungsi virtual
        return 0;
    }

    virtual string getName()
    {
        return "Shape";
    }

    virtual ~Shape() {} // virtual destructor agar aman jika di pakai delete pada pointer ke base class
};

class Square : public Shape
{
    float side;

public:
    Square(float s) { side = s; }
    float getArea() override
    {
        return side * side;
    }

    string getName() override
    {
        return "Square";
    }
};

class Circle : public Shape
{
    float radius;

public:
    Circle(float r) { radius = r; }
    float getArea() override
    {
        return 3.14 * radius * radius;
    }

    string getName() override
    {
        return "Circle";
    }
};

int main()
{
    Shape *S1 = new Square(5);
    Shape *S2 = new Circle(3);

    cout << "==== Area Calculator ====" << endl;
    cout << S1->getName() << " area = " << S1->getArea() << endl;
    cout << S2->getName() << " area = " << S2->getArea() << endl;

    delete S1; // menghapus objek Square
    delete S2; // menghapus objek Circle

    return 0;
}