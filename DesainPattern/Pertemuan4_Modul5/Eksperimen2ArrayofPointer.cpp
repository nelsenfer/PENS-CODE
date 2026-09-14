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

class Triangle : public Shape
{
    float base;
    float height;

public:
    Triangle(float b, float h)
    {
        base = b;
        height = h;
    }

    float getArea() override
    {
        return 0.5 * base * height;
    }

    string getName() override
    {
        return "Triangle";
    }
};

int main()
{
    Shape *shapes[3]; // array pointer ke Shape
    shapes[0] = new Square(4);
    shapes[1] = new Circle(2);
    shapes[2] = new Triangle(3, 5);

    cout << "\n=== Shape Summary ===" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << shapes[i]->getName() << " area = " << shapes[i]->getArea() << endl;
        delete shapes[i]; // menghapus objek yang dialokasikan secara dinamis
    }

    return 0;
}