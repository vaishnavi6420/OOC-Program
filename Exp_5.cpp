#include <iostream>
using namespace std;

class AreaCalculator {
public:
    float area(float radius) {
        return 3.14159f * radius * radius;
    }

    float area(float length, float width) {
        return length * width;
    }

    float area(float base, float height, int triangleFlag) {
        return 0.5f * base * height;
    }
};

int main() {
    AreaCalculator calc;

    cout << calc.area(5.0f) << endl;
    cout << calc.area(10.0f, 4.0f) << endl;
    cout << calc.area(6.0f, 3.0f, 1) << endl;

    return 0;
}