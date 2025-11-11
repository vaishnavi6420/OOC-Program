#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int roll;
public:
    friend ostream& operator<<(ostream& out, const Student& s);
    friend istream& operator>>(istream& in, Student& s);
};

ostream& operator<<(ostream& out, const Student& s) {
    out << s.name << " " << s.roll;
    return out;
}

istream& operator>>(istream& in, Student& s) {
    in >> s.name >> s.roll;
    return in;
}

int main() {
    Student s;
    cin >> s;
    cout << s;
    return 0;
}