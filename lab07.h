#pragma once
#include <iostream>
#include <cmath>
#include <cstring>

// ========================== Shape ==========================
class Shape {
protected:
    char* name;
    float area;

public:
    Shape(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        area = 0;
    }

    // Удамшил ашиглаж байгаа үед заавал virtual destructor хэрэгтэй
    virtual ~Shape() {
        delete[] name;
    }

    virtual void calculateArea() = 0; // Pure virtual function

    float getArea() const {
        return area;
    }

    const char* getName() const {
        return name;
    }
};

// ========================== TwoDShape ==========================
class TwoDShape : public Shape {
protected:
    float perimeter;

public:
    TwoDShape(const char* n) : Shape(n) {
        perimeter = 0;
    }

    virtual void calculatePerimeter() = 0;

    float getPerimeter() const {
        return perimeter;
    }
};

// ========================== Circle ==========================
class Circle : public TwoDShape {
    float x, y, r;

public:
    Circle(float x, float y, float r) : TwoDShape("Circle") {
        this->x = x;
        this->y = y;
        this->r = r;
        calculateArea();
        calculatePerimeter();
    }

    void calculateArea() override {
        area = 3.14159f * r * r;
    }

    void calculatePerimeter() override {
        perimeter = 2 * 3.14159f * r;
    }
};

// ========================== Square ==========================
class Square : public TwoDShape {
    float x, y, side;

public:
    Square(float x, float y, float s) : TwoDShape("Square") {
        this->x = x;
        this->y = y;
        this->side = s;
        calculateArea();
        calculatePerimeter();
    }

    void calculateArea() override {
        area = side * side;
    }

    void calculatePerimeter() override {
        perimeter = 4 * side;
    }
};

// ========================== Triangle ==========================
class Triangle : public TwoDShape {
    float x, y, side;

public:
    Triangle(float x, float y, float s) : TwoDShape("Triangle") {
        this->x = x;
        this->y = y;
        this->side = s;
        calculateArea();
        calculatePerimeter();
    }

    void calculateArea() override {
        // Зөв гурвалжны талбай олох томьёо
        area = (sqrt(3.0f) / 4.0f) * side * side;
    }

    void calculatePerimeter() override {
        perimeter = 3 * side;
    }
};
