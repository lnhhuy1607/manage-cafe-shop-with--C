#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Employee {
public:
    string empID;
    string name;
    char status;
    int numOfChildren;
    string education;
    int basicSalary;

    void Input() {
        cout << "Enter employee ID: ";
        cin.ignore();
        getline(cin, empID);
        cout << "Enter employee name: ";
        // cin.ignore();
        getline(cin, name);
        cout << "Enter status: ";
        cin >> status;
        // cin.ignore();
        cout << "Enter number of children: ";
        cin >> numOfChildren;
        // cin.ignore();
        cout << "Enter education: ";
        cin >> education;
        // cin.ignore();
        cout << "Enter basic salary: ";
        cin >> basicSalary;
        // cin.ignore(); // Ignore newline character
        // system("cls");
    }

    void Input(string empID, string name, char status, int numOfChildren, string education, int basicSalary) {
        this->empID = empID;
        this->name = name;
        this->status = status;
        this->numOfChildren = numOfChildren;
        this->education = education;
        this->basicSalary = basicSalary;
    }

    void DisplayProfile() {
        cout << "\t" << empID << "\t" << name << "\t\t\t" << status << "\t" << numOfChildren << "\t" << education << "\t" << basicSalary << "\tVND" << endl;
    }
};

class Salary {
private:
    Employee emp; // Assuming the Employee class is defined elsewhere as translated
    int leaveWithPay;
    int leaveWithoutPay;
    int overtimeHours;
    string workPerformance;

public:
    Salary(Employee employee) : emp(employee) {}

    void InputSalary() {
        cout << "Enter days of leave with pay: ";
        cin >> leaveWithPay;
        cout << "Enter days of leave without pay: ";
        cin >> leaveWithoutPay;
        cout << "Enter overtime hours: ";
        cin >> overtimeHours;
        cout << "Enter work performance: ";
        cin.ignore(); // Ignore newline character
        getline(cin, workPerformance);
        //system("cls");
    }

    float CalculateSalary() {
        float totalSalary = emp.basicSalary;
        int dailySalary = emp.basicSalary / 28;
        if (emp.numOfChildren > 2) {
            totalSalary += (5 * emp.basicSalary) / 100;
        }
        if (emp.education == "CH") { // Assuming "CH" stands for some qualification, translated to "education" previously
            totalSalary += (10 * emp.basicSalary) / 100;
        }
        totalSalary += dailySalary * overtimeHours * 4 / 100 - leaveWithoutPay * dailySalary * 5 / 100;
        return totalSalary;
    }

    void DisplaySalary() {
        cout << "\t" << emp.empID << "\t" << emp.name << "\t" << leaveWithPay << "\t" << leaveWithoutPay << "\t" << overtimeHours << "\t" << workPerformance << "\t" << CalculateSalary() << endl;
    }
};

class MENU {
private:
    vector<Employee> employees;
    vector<Salary> salaries;
    int numEmployees;

public:
    void InputProfile() {
        int method;
        cout << "Choose input method (1: Manual, 2: Predefined): " << endl;
        cin >> method;
        if (method == 1) {
            cout << "Enter number of employees: ";
            cin >> numEmployees;
            cin.ignore(); // Ignore newline character
            for (int i = 0; i < numEmployees; i++) {
                Employee employee;
                cout << "Employee " << i + 1 << ": " << endl;
                employee.Input();
                employees.push_back(employee);
            } 
        }
        else {
            numEmployees = 3;
            Employee employee;
            employee.Input("21200147", "Le Tan Nam", 'S', 0, "DH", 500000);
            employees.push_back(employee);
            employee.Input("21200100", "Le Van Nam", 'M', 2, "DH", 600000);
            employees.push_back(employee);
            employee.Input("21200146", "Nguyen Van Nam", 'M', 3, "CH", 900000);
            employees.push_back(employee);
        }          
    }

    void InputSalary() {
        for (int i = 0; i < numEmployees; i++) {
            cout << employees[i].empID << "\t" << employees[i].name << ": " << endl;
            Salary salary(employees[i]);
            salary.InputSalary();
            salaries.push_back(salary);
        }
    }

    void DisplayProfile() {
        cout << "Profiles: " << endl;
        for (int i = 0; i < numEmployees; i++) {
            employees[i].DisplayProfile();
        }
        system("pause");
    }

    void DisplaySalary() {
        cout << "Salaries: " << endl;
        for (int i = 0; i < numEmployees; i++) {
            salaries[i].DisplaySalary();
        }
        system("pause");
    }

    void AddEmployee() {
        int n; // Number of employees to add
        cout << "Enter number of employees to add: ";
        cin >> n;
        cin.ignore(); // Ignore remaining newline character
        for (int i = 0; i < n; i++) {
            Employee employee;
            cout << "Enter information for employee " << i + 1 << ": " << endl;
            employee.Input();
            employees.push_back(employee);
            numEmployees++; // Update number of employees
        }
    }

    void DeleteEmployee() {
        string empID;
        cout << "Enter employee ID to delete: ";
        cin >> empID;

        for (vector<Employee>::iterator it = employees.begin(); it != employees.end(); ++it) {
            if (it->empID == empID) {
                employees.erase(it);
                numEmployees--; // Update number of employees
                cout << "Employee with ID " << empID << " deleted." << endl;
                return;
            }
        }
        cout << "Employee with ID " << empID << " not found." << endl;
    }

    void EditEmployee() {
        string empID;
        cout << "Enter employee ID to edit: ";
        cin >> empID;

        for (vector<Employee>::iterator it = employees.begin(); it != employees.end(); ++it) {
            if (it->empID == empID) {
                cout << "Enter new information for employee with ID " << empID << ": " << endl;
                it->Input();
                cout << "Employee with ID " << empID << " updated." << endl;
                return;
            }
        }
        cout << "Employee with ID " << empID << " not found." << endl;
    }

    void SearchEmployee() {
        string empID;
        cout << "Enter employee ID to search: ";
        cin >> empID;

        for (vector<Employee>::iterator it = employees.begin(); it != employees.end(); ++it) {
            if (it->empID == empID) {
                cout << "Information of employee with ID " << empID << ": " << endl;
                it->DisplayProfile();
                system("pause");
                return;
            }
        }
        cout << "Employee with ID " << empID << " not found." << endl;
    }
    
    void PrintMenu() {
        int choice;
        while (choice != 9) {
            system("cls");
            cout << "\n===== MENU ======";
            cout << "\n1. Input profiles";
            cout << "\n2. Input salaries";
            cout << "\n3. Display profiles";
            cout << "\n4. Display salaries";
            cout << "\n5. Add employee";
            cout << "\n6. Delete employee";
            cout << "\n7. Edit employee";
            cout << "\n8. Search employee";
            cout << "\n9. Exit";
            cout << "\nEnter your choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                InputProfile();
                break;
            case 2:
                InputSalary();
                break;
            case 3:
                DisplayProfile();
                break;
            case 4:
                DisplaySalary();
                break;
            case 5:
                AddEmployee();
                break;
            case 6:
                DeleteEmployee();
                break;
            case 7:
                EditEmployee();
                break;
            case 8:
                SearchEmployee();
                break;
            }
        }
    }
};
int main()
{
    MENU menu;
    menu.PrintMenu();
}