#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void Draw() = 0;     // fungsi abstract
    virtual float GetArea() = 0; // fungsi abstract
};

class Circle : public Shape
{
private:
    float r;

public:
    Circle(float radius) : r(radius) {}
    void Draw() override // fungsi override
    {
        cout << "Drawing a Circle\n";
    }
    float GetArea() override // fungsi override
    {
        return 3.14 * r * r;
    }
};

class rectangle : public Shape
{
private:
    float p, l;

public:
    rectangle(float panjang, float lebar) : p(panjang), l(lebar) {}
    void Draw() override // fungsi override
    {
        cout << "Drawing a Rectangle\n";
    }
    float GetArea() override // fungsi override
    {
        return p * l;
    }
};

class Triangle : public Shape
{
private:
    float a, t;

public:
    Triangle(float alas, float tinggi) : a(alas), t(tinggi) {}
    void Draw() override // fungsi override
    {
        cout << "Drawing a Triangle\n";
    }
    float GetArea() override // fungsi override
    {
        return 0.5 * a * t;
    }
};

int main()
{
    Shape *shapes[3];
    shapes[0] = new Circle(5);
    shapes[1] = new rectangle(8, 5);
    shapes[2] = new Triangle(6, 4);

    for (int i = 0; i < 3; i++)
    {
        shapes[i]->Draw();
        cout << "Area: " << shapes[i]->GetArea() << "\n\n";
    }

    for (int i = 0; i < 3; i++)
    {
        delete shapes[i];
    }

    return 0;
}