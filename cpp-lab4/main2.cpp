#include <iostream>
using namespace std;

class Polygon {
protected:
    int m_width, m_height;
public:
    Polygon(int w, int h) : m_width(w), m_height(h) {}
    virtual ~Polygon() { cout << "Polygon::~Polygon()" << endl; }
    virtual int area() = 0;
};

class Rectangle: public Polygon {
public:
    Rectangle(int w, int h) : Polygon(w,h) {}
    ~Rectangle() { cout << "Rectangle::~Rectangle()" << endl; }
    int area() {
        cout << "Calculating the area of rectangle: ";
        return m_width * m_height;
    }
};

class Triangle: public Polygon {
public:
    Triangle(int w, int h) : Polygon(w,h) {}
    ~Triangle() { cout << "Triangle::~Triangle()" << endl; }
    int area() {
        cout << "Calculating the area of triangle: ";
        return m_width * m_height / 2;
    }
};

void printAreaOf(Polygon * pPoly) {
    cout << pPoly->area() << endl;
}

void printAreasOf(Polygon * pPolys[], int size) {
    for (int i = 0; i < size; i++) {
        cout << pPolys[i]->area() << endl;
    }
}

int main () {
    Rectangle rect(4,5);
    Triangle trgl(4,5);

    Polygon *pPoly;

    pPoly = &rect;
    cout << "Calling pPoly->area()" << endl;
    cout << pPoly->area() << endl << endl;

    pPoly = &trgl;
    cout << "Calling pPoly->area()" << endl;
    cout << pPoly->area() << endl << endl;

    cout << "Calling printAreaOf(Polygon *pPoly = &rect)" << endl;
    printAreaOf(&rect);
    cout << endl;

    cout << "Calling printAreaOf(Polygon *pPoly = &trgl)" << endl;
    printAreaOf(&trgl);
    cout << endl;

    Polygon *polys[] = {&rect, &trgl};

    cout << "Calling printAreasOf(polys[] = {&rect, &trgl})" << endl;
    printAreasOf(polys, 2);
    cout << endl;

    cout << "Polygon *p = new Triangle(10,20)" << endl;
    Polygon *p = new Triangle(10,20);
    cout << "delete p" << endl;
    delete p;
    cout << endl;

    cout <<"The end od main" << endl;
    return 0;
}

