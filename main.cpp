#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()
#include "MyLinkedList.h"
#include "lab07.h"

using namespace std;

void bubbleSort(MyLinkedList<TwoDShape*>& list) {
    int n = list.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (list.get(j)->getArea() > list.get(j + 1)->getArea()) {
                // Swap хийхийн тулд insert + remove ашиглана
                TwoDShape* a = list.get(j);
                TwoDShape* b = list.get(j + 1);
                list.remove(j);
                list.insert(j, b);
                list.remove(j + 1);
                list.insert(j + 1, a);
            }
        }
    }
}

int main() {
    srand(time(0));

    MyLinkedList<TwoDShape*> shapes;

    // 20-30 санамсаргүй объект үүсгэх
    int count = 20 + rand() % 11; // 20-30

    for (int i = 0; i < count; i++) {
        // Санамсаргүй тал 1.0 - 20.0
        float side = 1.0f + (rand() % 200) / 10.0f;
        int type = rand() % 3;

        if (type == 0)
            shapes.add(new Circle(0, 0, side));
        else if (type == 1)
            shapes.add(new Square(0, 0, side));
        else
            shapes.add(new Triangle(0, 0, side));
    }

    cout << "Эрэмбэлэхийн өмнө (" << shapes.length() << " дүрс):" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < (int)shapes.length(); i++) {
        cout << i + 1 << ". "
             << shapes.get(i)->getName()
             << " - Талбай: " << shapes.get(i)->getArea()
             << " - Периметр: " << shapes.get(i)->getPerimeter()
             << endl;
    }

    bubbleSort(shapes);

    cout << "\nТалбайгаар эрэмбэлсний дараа:" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < (int)shapes.length(); i++) {
        cout << i + 1 << ". "
             << shapes.get(i)->getName()
             << " - Талбай: " << shapes.get(i)->getArea()
             << " - Периметр: " << shapes.get(i)->getPerimeter()
             << endl;
    }

    // Санах ой чөлөөлөх
    for (int i = 0; i < (int)shapes.length(); i++)
        delete shapes.get(i);

    return 0;
}