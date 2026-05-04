#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    void inputDetails() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayDetails() {
        cout << "\nName: " << name;
        cout << "\nRoll Number: " << rollNumber;
        cout << "\nMarks: " << marks;
        cout << "\nGrade: " << calculateGrade() << endl;
    }

    char calculateGrade() {
        if (marks >= 75) return 'A';
        else if (marks >= 60) return 'B';
        else if (marks >= 40) return 'C';
        else return 'F';
    }

    float getMarks() {
        return marks;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students(n);

    // Input details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << endl;
        students[i].inputDetails();
    }

    // Display details
    cout << "\n--- Student Details ---\n";
    for (int i = 0; i < n; i++) {
        students[i].displayDetails();
    }

    // Find topper
    int topperIndex = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].getMarks() > students[topperIndex].getMarks()) {
            topperIndex = i;
        }
    }

    cout << "\n--- Class Topper ---\n";
    students[topperIndex].displayDetails();

    // Calculate average
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].getMarks();
    }

    cout << "\nAverage Marks: " << (sum / n) << endl;

    return 0;
}