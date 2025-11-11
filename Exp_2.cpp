#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    void input() {
        cin >> real >> imag;
    }

    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i" << endl;
    }

    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex subtract(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
};

int main() {
    Complex c1, c2, sum, diff;

    c1.input();
    c2.input();

    sum = c1.add(c2);
    diff = c1.subtract(c2);

    c1.display();
    c2.display();
    sum.display();
    diff.display();

    return 0;
}