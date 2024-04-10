#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to contain information about employee
struct Employee {


    string name;
    int id{};
    double salary{};
};

// Function prototypes
void addEmployee(vector<Employee>& employees);
void displayEmployees(const vector<Employee>& employees);
void modifyEmployee(vector<Employee>& employees);
void searchEmployee(const vector<Employee>& employees);

[[maybe_unused]] void printPaySlip(const Employee& employee);

int main() {
    vector<Employee> employees;
    char choice;

     do{
         //information to be displayed on the system menu
        cout << "Payroll System Menu" << endl;
        cout << "1. Add new employee record" << endl;
        cout << "2. Display all employee records" << endl;
        cout << "3. Modify employee record" << endl;
        cout << "4. Search employee record" << endl;
        cout << "5. Print employee payslip" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addEmployee(employees);
                break;
            case '2':
                displayEmployees(employees);
                break;
            case '3':
                modifyEmployee(employees);
                break;
            case '4':
                searchEmployee(employees);
                break;
            case '5':
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '6');

    return 0;
}

// Function to add a new employee record
void addEmployee(vector<Employee>& employees) {
    Employee empl;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, empl.name);
    cout << "Enter ID: ";
    cin >> empl.id;
    cout << "Enter salary: ";
    cin >> empl.salary;
    employees.push_back(empl);
    cout << "Employee added successfully." << endl;
}

// Function to display all employee records
void displayEmployees(const vector<Employee>& employees) {
    if (employees.empty()) {
        cout << "No employee records found." << endl;
    } else {
        cout << "Employee Records:" << endl;
        for (const auto& empl : employees) {
            cout << "Name: " << empl.name << ", ID: " << empl.id << ", Salary: $" << empl.salary << endl;
        }
    }
}

// Function to modify employee record
void modifyEmployee(vector<Employee>& employees) {
    int id;
    cout << "Enter employee ID to modify: ";
    cin >> id;
    bool found = false;
    for (auto& empl : employees) {
        if (empl.id == id) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, empl.name);
            cout << "Enter new salary: ";
            cin >> empl.salary;
            found = true;
            cout << "Employee record modified successfully." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}

// Function to search employee record
void searchEmployee(const vector<Employee>& employees) {
    int id;
    cout << "Enter employee ID to search: ";
    cin >> id;
    bool found = false;
    for (const auto& empl : employees) {
        if (empl.id == id) {
            cout << "Employee found:" << endl;
            cout << "Name: " << empl.name << ", ID: " << empl.id << ", Salary: $" << empl.salary << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}

// Function to print employee payslip
[[maybe_unused]] void printPaySlip(const vector<Employee>& employees) {
    int id;
    cout << "Enter employee ID to print payslip: ";
    cin >> id;
    bool found = false;
    for (const auto& empl : employees) {
        if (empl.id == id) {
            cout << "Employee Payslip:" << endl;
            cout << "Name: " << empl.name << ", ID: " << empl.id << endl;
            cout << "Salary: $" << empl.salary << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee with ID " << id << " not found." << endl;
    }
}