#include <iostream>
using namespace std;

class Institute {
protected:
    string name;
public:
    void setInstitute(string n) {
        name = n;
    }
    void showInstitute() {
        cout << "Institute: " << name << endl;
    }
};

class Department {
protected:
    string dept;
public:
    void setDepartment(string d) {
        dept = d;
    }
    void showDepartment() {
        cout << "Department: " << dept << endl;
    }
};

class Faculty : public Institute, public Department {
private:
    string facultyName;
public:
    void setFaculty(string fn, string in, string dn) {
        facultyName = fn;
        setInstitute(in);
        setDepartment(dn);
    }
    void showFaculty() {
        cout << "Faculty: " << facultyName << endl;
        showInstitute();
        showDepartment();
    }
};

int main() {
    Faculty f;
    f.setFaculty("Dr. Mehta", "TechVerse Institute", "Computer Science");
    f.showFaculty();
    return 0;
}