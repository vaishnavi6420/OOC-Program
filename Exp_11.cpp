#include <iostream>
using namespace std;

class Employee {
public:
    virtual double calculateSalary() = 0;
};

class SalariedEmployee : public Employee {
private:
    double monthlySalary;
public:
    SalariedEmployee(double salary) {
        monthlySalary = salary;
    }
    double calculateSalary() {
        return monthlySalary;
    }
};

class HourlyEmployee : public Employee {
private:
    double hoursWorked;
    double hourlyRate;
public:
    HourlyEmployee(double hours, double rate) {
        hoursWorked = hours;
        hourlyRate = rate;
    }
    double calculateSalary() {
        return hoursWorked * hourlyRate;
    }
};

class CommissionedEmployee : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;
public:
    CommissionedEmployee(double base, double sales, double rate) {
        baseSalary = base;
        salesAmount = sales;
        commissionRate = rate;
    }
    double calculateSalary() {
        return baseSalary + (salesAmount * commissionRate);
    }
};

int main() {
    SalariedEmployee s(50000);
    HourlyEmployee h(160, 200);
    CommissionedEmployee c(30000, 100000, 0.1);

    cout << "Salaried Employee Salary: " << s.calculateSalary() << endl;
    cout << "Hourly Employee Salary: " << h.calculateSalary() << endl;
    cout << "Commissioned Employee Salary: " << c.calculateSalary() << endl;

    return 0;
}