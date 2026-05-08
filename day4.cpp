#include<bits/stdc++.h>
using namespace std;

// Base Class
class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n, int i) {
        name = n;
        id = i;
    }

    // Virtual function for runtime polymorphism
    virtual double calculateSalary() = 0;

    virtual void display() {
        cout << "Employee ID : " << id << endl;
        cout << "Employee Name : " << name << endl;
    }

    virtual ~Employee() {}
};

// Derived Class - FullTime Employee
class FullTime : public Employee {
private:
    double monthlySalary;
    double bonus;

public:
    FullTime(string n, int i, double salary, double b)
        : Employee(n, i) {

        monthlySalary = salary;
        bonus = b;
    }

    double calculateSalary() override {
        return monthlySalary + bonus;
    }

    void display() override {
        cout << "\n----- Full Time Employee -----" << endl;
        Employee::display();

        cout << "Base Salary : " << monthlySalary << endl;
        cout << "Bonus : " << bonus << endl;
        cout << "Total Salary : " << calculateSalary() << endl;
    }
};

// Derived Class - PartTime Employee
class PartTime : public Employee {
private:
    int hoursWorked;
    double hourlyRate;

public:
    PartTime(string n, int i, int hours, double rate)
        : Employee(n, i) {

        hoursWorked = hours;
        hourlyRate = rate;
    }

    double calculateSalary() override {
        return hoursWorked * hourlyRate;
    }

    void display() override {
        cout << "\n----- Part Time Employee -----" << endl;
        Employee::display();

        cout << "Hours Worked : " << hoursWorked << endl;
        cout << "Hourly Rate : " << hourlyRate << endl;
        cout << "Total Salary : " << calculateSalary() << endl;
    }
};

int main() {

    vector<Employee*> employees;

    // Storing employees
    employees.push_back(new FullTime("Jashan", 101, 50000, 5000));
    employees.push_back(new PartTime("Rahul", 102, 6, 400));
    employees.push_back(new FullTime("Aman", 103, 60000, 8000));
    employees.push_back(new PartTime("Priya", 104, 5, 500));

    double highestSalary = 0;
    Employee* highestPaid = nullptr;

    cout << "\n===== Employee Salary Details =====\n";

    // Runtime polymorphism
    for(auto emp : employees) {

        emp->display();

        if(emp->calculateSalary() > highestSalary) {
            highestSalary = emp->calculateSalary();
            highestPaid = emp;
        }
    }

    // Highest paid employee
    cout << "\n===== Highest Paid Employee =====\n";

    if(highestPaid != nullptr) {
        highestPaid->display();
    }

    // Free memory
    for(auto emp : employees) {
        delete emp;
    }

    return 0;
}