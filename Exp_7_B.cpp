#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    void setName(string n) {
        name = n;
    }
    void showName() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
protected:
    int roll;
public:
    void setRoll(int r) {
        roll = r;
    }
    void showRoll() {
        cout << "Roll No: " << roll << endl;
    }
};

class Teacher : public Person {
protected:
    string subject;
public:
    void setSubject(string s) {
        subject = s;
    }
    void showSubject() {
        cout << "Subject: " << subject << endl;
    }
};

class Assistant : public Student, public Teacher {
public:
    void setAssistant(string n, int r, string s) {
        Student::setName(n);
        setRoll(r);
        setSubject(s);
    }
    void showAssistant() {
        Student::showName();
        showRoll();
        showSubject();
    }
};

int main() {
    Assistant a;
    a.setAssistant("Riya", 42, "Physics");
    a.showAssistant();
    return 0;
}