#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int v = 0) {
        value = v;
    }

    Number operator+() const {
        return Number(+value);
    }

    Number operator-() const {
        return Number(-value);
    }

    Number operator++() {
        ++value;
        return *this;
    }

    Number operator++(int) {
        Number temp = *this;
        value++;
        return temp;
    }

    Number operator--() {
        --value;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;
        value--;
        return temp;
    }

    bool operator!() const {
        return value == 0;
    }

    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }

    Number operator-(const Number& other) const {
        return Number(value - other.value);
    }

    Number operator*(const Number& other) const {
        return Number(value * other.value);
    }

    Number operator/(const Number& other) const {
        return Number(value / other.value);
    }

    Number operator%(const Number& other) const {
        return Number(value % other.value);
    }

    bool operator==(const Number& other) const {
        return value == other.value;
    }

    bool operator!=(const Number& other) const {
        return value != other.value;
    }

    bool operator<(const Number& other) const {
        return value < other.value;
    }

    bool operator>(const Number& other) const {
        return value > other.value;
    }

    bool operator<=(const Number& other) const {
        return value <= other.value;
    }

    bool operator>=(const Number& other) const {
        return value >= other.value;
    }

    Number& operator=(const Number& other) {
        value = other.value;
        return *this;
    }

    void display() const {
        cout << value << endl;
    }
};

int main() {
    Number a(10), b(3), c;

    (+a).display();
    (-b).display();
    (a + b).display();
    (a - b).display();
    (a * b).display();
    (a / b).display();
    (a % b).display();

    cout << (a == b) << endl;
    cout << (a != b) << endl;
    cout << (a < b) << endl;
    cout << (a > b) << endl;
    cout << (a <= b) << endl;
    cout << (a >= b) << endl;
    cout << (!Number(0)) << endl;

    (++a).display();
    (a++).display();
    (--b).display();
    (b--).display();

    c = a;
    c.display();

    return 0;
}