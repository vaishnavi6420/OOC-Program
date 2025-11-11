#include <iostream>
using namespace std;

double divide(int a, int b) {
    if (b == 0)
        throw "Division by zero error";
    return (double)a / b;
}

int main() {
    int x, y;
    cin >> x >> y;
    try {
        double result = divide(x, y);
        cout << "Result: " << result << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}