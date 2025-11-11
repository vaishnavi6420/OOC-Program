#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    void inputDetails() {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter marks: ";
        cin >> marks;
        cin.ignore(); // Clear input buffer
    }

    void displayDetails() const {
        cout << "\nStudent Details:\n";
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    const int SIZE = 5;
    Student students[SIZE];

    cout << "Enter details for " << SIZE << " students:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].inputDetails();
    }

    cout << "\nDisplaying all student details:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        students[i].displayDetails();
    }

    return 0;
}