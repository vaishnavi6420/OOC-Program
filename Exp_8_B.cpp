#include <iostream>
using namespace std;

class Value {
private:
    int data;

public:
    Value(int d = 0) {
        data = d;
    }

    bool operator==(const Value& other) const {
        return data == other.data;
    }

    bool operator!=(const Value& other) const {
        return data != other.data;
    }

    bool operator<(const Value& other) const {
        return data < other.data;
    }

    bool operator>(const Value& other) const {
        return data > other.data;
    }

    bool operator<=(const Value& other) const {
        return data <= other.data;
    }

    bool operator>=(const Value& other) const {
        return data >= other.data;
    }

    void display() const {
        cout << data << endl;
    }
};

int main() {
    Value a(10), b(20);

    cout << (a == b) << endl;
    cout << (a != b) << endl;
    cout << (a < b) << endl;
    cout << (a > b) << endl;
    cout << (a <= b) << endl;
    cout << (a >= b) << endl;

    return 0;
}