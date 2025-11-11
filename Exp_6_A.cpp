#include <iostream>
using namespace std;

class Student {
protected:
    int rollNumber;

public:
    void inputRollNumber() {
        cin >> rollNumber;
    }

    void displayRollNumber() const {
        cout << "Roll Number: " << rollNumber << endl;
    }
};

class Test : public Student {
protected:
    float marks1;
    float marks2;

public:
    void inputMarks() {
        cin >> marks1 >> marks2;
    }

    void displayMarks() const {
        cout << "Marks1: " << marks1 << ", Marks2: " << marks2 << endl;
    }
};

class Result : public Test {
private:
    float total;

public:
    void calculateTotal() {
        total = marks1 + marks2;
    }

    void displayResult() const {
        displayRollNumber();
        displayMarks();
        cout << "Total Marks: " << total << endl;
    }
};

int main() {
    Result r;
    r.inputRollNumber();
    r.inputMarks();
    r.calculateTotal();
    r.displayResult();

    return 0;
}