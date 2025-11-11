#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle() {
        length = 0;
        width = 0;
    }

    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    ~Rectangle() {
        cout << "Rectangle object destroyed\n";
    }

    double area() const {
        return length * width;
    }

    double perimeter() const {
        return 2 * (length + width);
    }

    void display() const {
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

int main() {
    Rectangle r1(10.5, 4.2);
    r1.display();

    Rectangle r2;
    r2.display();

    return 0;
}