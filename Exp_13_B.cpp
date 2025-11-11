#include <iostream>
using namespace std;

class InvalidAgeException {
public:
    string message;
    InvalidAgeException(string msg) {
        message = msg;
    }
};

class Person {
private:
    string name;
    int age;
public:
    void setPerson(string n, int a) {
        if (a < 0 || a > 150)
            throw InvalidAgeException("Invalid age entered");
        name = n;
        age = a;
    }
    void showPerson() {
        cout << name << " " << age << endl;
    }
};

int main() {
    Person p;
    string n;
    int a;
    cin >> n >> a;
    try {
        p.setPerson(n, a);
        p.showPerson();
    } catch (InvalidAgeException e) {
        cout << e.message << endl;
    }
    return 0;
}