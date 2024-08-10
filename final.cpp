#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;
class Employee {
public:
    string empID;
    string name;
    char status;
    int numOfChildren;
    string education;
    int basicSalary;

    void Input();

    void Input(string empID, string name, char status, int numOfChildren, string education, int basicSalary);

    void DisplayProfile();
};

void Employee::DisplayProfile()
{
    cout << "\t" << empID << "\t" << name << "\t\t\t" << status << "\t" << numOfChildren << "\t" << education << "\t" << basicSalary << "\tVND" << endl;
}

void Employee::Input()
{
    cout << "Enter employee ID: ";
    cin.ignore();
    getline(cin, empID);
    cout << "Enter employee name: ";
        
    getline(cin, name);
    cout << "Enter status: ";
    cin >> status;
        
    cout << "Enter number of children: ";
    cin >> numOfChildren;
        
    cout << "Enter education: ";
    cin >> education;
        
    cout << "Enter basic salary: ";
    cin >> basicSalary;
}

void Employee::Input(string empID, string name, char status, int numOfChildren, string education, int basicSalary)
{
    this->empID = empID;
    this->name = name;
    this->status = status;
    this->numOfChildren = numOfChildren;
    this->education = education;
    this->basicSalary = basicSalary;
}
class Salary {
private:
    Employee emp; // Assuming the Employee class is defined elsewhere as translated
    int leaveWithPay;
    int leaveWithoutPay;
    int overtimeHours;
    string workPerformance;
public:
    Salary(Employee employee) : emp(employee) {}

    void InputSalary();

    double CalculateSalary();

    void DisplaySalary();
};

void Salary::InputSalary()
{
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

double Salary::CalculateSalary()
{
    double totalSalary = emp.basicSalary;
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

void Salary::DisplaySalary()
{
    cout << "\t" << emp.empID << "\t" << emp.name << "\t" << leaveWithPay << "\t" << leaveWithoutPay << "\t" << overtimeHours << "\t" << workPerformance << "\t" << CalculateSalary() << endl;
}

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

            numEmployees = 10;
            Employee employee;
            employee.Input("21200147", "Le Tan A", 'S', 0, "DH", 500000);
            employees.push_back(employee);
            employee.Input("21200100", "Le Van B", 'M', 2, "DH", 600000);
            employees.push_back(employee);
            employee.Input("21200146", "Nguyen Van C", 'M', 3, "CH", 900000);
            employees.push_back(employee);
            employee.Input("21200150", "Le Nhat D", 'M', 0, "DH", 500000);
            employees.push_back(employee);
            employee.Input("21200151", "Le Minh E", 'S', 2, "DH", 500000);
            employees.push_back(employee);
            employee.Input("21200152", "Nguyen Tan F", 'L', 0, "DH", 600000);
            employees.push_back(employee);
            employee.Input("21200153", "Nguyen Thi G", 'M', 3, "DH", 700000);
            employees.push_back(employee);
            employee.Input("21200154", "Vo Tan H", 'S', 2, "DH", 500000);
            employees.push_back(employee);
            employee.Input("21200155", "Trinh Tan L", 'M', 0, "DH", 900000);
            employees.push_back(employee);
            employee.Input("21200156", "Chu Tan M", 'S', 1, "DH", 500000);
            employees.push_back(employee);
        }    
        //PrintStaffToFile();      
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
        cout << "\t" << "empID" << "\t\t" << "Name" << "\t\t\t\t" << "Status" << "\t" << "Child" << "\t" << "Edu" << "\t" << "Basic salary" << endl;
        for (int i = 0; i < numEmployees; i++) {
            employees[i].DisplayProfile();
        }
        system("pause");
    }
    void PrintStaffToFile() {
        ofstream file("staff.txt");
        if (!file.is_open()) {
            cout << "Cannot open staff.txt for writing!" << endl;
            return;
        }
        file << "\t\tStaff list" <<endl;
        for (int i = 0; i < numEmployees; i++) {
            file << employees[i].empID << ", " << employees[i].name << ", " << employees[i].status << ", " << employees[i].numOfChildren << ", " << employees[i].education << ", " << employees[i].basicSalary << endl;
        }

        file.close();
        cout << "Employee details written to staff.txt." << endl;
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
        while (choice != 10) {
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
            cout << "\n9. Print list employee";
            cout << "\n10. Exit";
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
            case 9:
                PrintStaffToFile();
                break;
            // case 10:
            //     break;
            // }
        }
    }
    }
};
class Menu
{
    public:
        int Num;
        string name;
        string type; // drink or food
        int price;
        string size; //S M L
    public:
        void Input(int Num, string name, string type, int price, string size);
        void Output();
        
        
};

void Menu::Output()
{
    cout<<"\t"<<Num<<"\t"<<name<<"\t\t"<<type<<"\t\t"<<price<<"\t\t"<<size;
}
void Menu::Input(int Num, string name, string type, int price, string size)
{
    this -> Num = Num;
    this -> name = name;
    this -> type = type;
    this -> price = price;
    this -> size = size;
}
class BILL
{
    private:
        string ShopName;
        int Chose; //number product
        float Tax; //8%
        unsigned int Number; //number chosen
        int Payment_method;
        float Total_amount;
        vector <Menu> menu;
        string size;
        float amount ;
        float price;
        double extra;
        float bill_price;
    public:
        void ShowMenu();
        void Pay();
        void printbill();
        void BillPlay();
        float CalculateTotalRevenue(vector<float> bill_amounts);
        friend float Total(BILL bill);
};
float BILL::CalculateTotalRevenue(vector<float> bill_amounts) {
    float total_revenue = 0;
    for (float amount : bill_amounts) {
        total_revenue += amount;
    }
    return total_revenue;
}
void BILL::printbill()
{
    cout << "----------------BILL---------------\n";
    cout << "\t" << ShopName << endl;
    cout << "Product name: " << menu[Chose - 1].name << endl;
    cout << "Size: " << size << endl;
    cout << "Quantity: " << Number << endl;
    cout << "Price per item: " << price << endl;
    cout << "Total price: " << bill_price << endl;
    cout << "Tax: " << Tax << endl;
    cout << "Payment method: ";
    if(Payment_method == 1)
    {
        cout << "Cash" << endl;
    }
    else
    {
        cout << "Credit" << endl;
    }
    cout << "Total amount: " << Total_amount << endl;
    cout << "----------------------------------\n";
}
void BILL::ShowMenu()
{
    cout<<"\t\t\t\t\tMENU"<<endl;;
    menu.resize(14);
    menu[0].Input(1, "Americano", "Drink", 50000, "L/M/S");
    menu[1].Input(2, "Cappuchino", "Drink", 40000, "L/M/S");
    menu[2].Input(3, "Expresso", "Drink", 50000, "L/M/S");
    menu[3].Input(4, "Mocha     ", "Drink", 60000, "L/M/S");
    menu[4].Input(5, "Milk coffee", "Drink", 30000, "L/M/S");
    menu[5].Input(6, "Ice tea   ", "Drink", 5000, "L/M/S");
    menu[6].Input(7, "Orange juice", "Drink", 30000, "L/M/S");
    menu[7].Input(8, "Soda    ", "Drink", 30000, "L/M/S");
    menu[8].Input(9, "Americano", "Drink", 50000, "L/M/S");
    menu[9].Input(10, "Bread    ", "Food", 5000, "X");
    menu[10].Input(11, "Croisssant", "Food", 20000, "X");
    menu[11].Input(12, "Cupcake   ", "Food", 20000, "X");
    menu[12].Input(13, "Cheesecake", "Food", 20000, "X");
    menu[13].Input(14, "Sandwich", "Food", 20000, "X");
    for(int i = 0; i < menu.size(); i++)
    {
        menu[i].Output();
        cout<<endl;
    }
}
void BILL::Pay()
{
    ofstream file("bill.txt");
    if (!file.is_open()) {
        cerr << "Khong the mo file." << endl;
        return; // Thêm return để thoát khỏi hàm nếu không thể mở file
    }
    ShopName = "    KAKA Coffee";
    file << "\t" << ShopName << endl;
    file << "----------------BILL---------------\n";
    time_t currentTime = std::time(nullptr); // set up in thoi gian
    tm* localTime = std::localtime(&currentTime);
    file << "Print date: " << put_time(localTime, "%Y-%m-%d") << std::endl;
    file << "Print time: " << put_time(localTime, "%H:%M:%S") << std::endl;
    file<<"Order "<<"         "<<"Size "<<"       "<<"Quantity"<<"       "<<"Price"<<endl;
    Total_amount=0;
    while(true){
    string order ;
    cout << "Product order: ";
    cin >> Chose;
    file << menu[Chose - 1].name << "       ";
    cout<< "Size: ";
    cin >> size;
     file <<size<<"       ";
    cout << "Quantity: ";
    cin >> Number;
    file << "       " << Number;
    if(size == "S" or size == "x" or size == "s") price = menu[Chose - 1].price;
    if(size == "M" or size == "m" ) price = menu[Chose - 1].price + 5000;
    if(size == "L" or size == "l" ) price = menu[Chose - 1].price+ 10000;
    bill_price= price*Number;
    file<<"          "<<bill_price<<endl;
    file<<"--------------------------------------------:"<<endl;
    amount = price * Number  + Total_amount;
    Total_amount= amount;
    cout <<"That's all ?: ";
    cin>>order;
    if(order == "y" or order == "yes") break;
    }
    cout<< "Extra: ";
    cin>>extra;
    file<<"Extra: "<<extra<<endl;
    cout << "Payment method (1: Cash, 2: Credit): ";
    cin >> Payment_method;
    if(Payment_method == 1)
    {
        file << "Payment Method: Cash " << endl;
    }
    else
    {
        file << "Payment Method: Credit " << endl;
    }
    file << "---------------****************************------------------\n";
    file << "TOTAL: " << Total_amount - float(Total_amount*extra/100) << endl;
    file << " Thank you very much <3";

    file.close();
}

void BILL::BillPlay()
{
   
    string continue_order;
    while(true) {
        cout << "Do you want to generate a new bill? (yes/no): ";
        cin >> continue_order;
        if(continue_order == "yes") {
            Pay();
        } else if (continue_order == "no") {
            break;
        } else {
            cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
        }
    }
}
class InventoryManagement {
public:
    string name; // Product name
    string type; // Product type (e.g., "can", "bag")
    int amount; // Remaining quantity

public:
    // Constructor
    InventoryManagement(const string& itemName, const string& itemType, int initialAmount) 
        : name(itemName), type(itemType), amount(initialAmount) {}

    // Destructor
    ~InventoryManagement() {}

    // Function to decrease the quantity of a product
    void decreaseAmount(int amountToReduce) {
        if (amountToReduce > 0 && amountToReduce <= amount) {
            amount -= amountToReduce;
            cout << "Used " << amountToReduce << " " << type << " of " << name << ". Current quantity: " << amount << endl;
        } else {
            cerr << "Not enough product or invalid quantity!" << endl;
        }
    }

    // Function to increase the quantity of a product
    void increaseAmount(int amountToAdd) {
        if (amountToAdd > 0) {
            amount += amountToAdd;
            cout << "Added " << amountToAdd << " " << type << " of " << name << ". Current quantity: " << amount << endl;
        } else {
            cerr << "Invalid quantity!" << endl;
        }
    }
    void setName(const string& newName) {
        name = newName;
    }

    // Function to modify the product type
    void setType(const string& newType) {
        type = newType;
    }

    // Function to modify the product amount
    void setAmount(int newAmount) {
        amount = newAmount;
    }
    //friend void setupCafeInventory(InventoryManagement IV);
    // Function to display information about the product
    void show() const {
        cout << "Product name: " << name << endl;
        cout << "Product type: " << type << endl;
        cout << "Remaining quantity: " << amount << endl;
        cout << "--------------------------------" << endl;
    }
};

void setupCafeInventory(vector<InventoryManagement> &cafeInventory) {
    // Create a list of products in the café
    

    // Add ingredients, plastic cups, and packaging to the list
    cafeInventory.push_back(InventoryManagement("Coffee", "bag", 100)); // Initial quantity of coffee
    cafeInventory.push_back(InventoryManagement("Milk", "can", 50)); // Initial quantity of milk
    cafeInventory.push_back(InventoryManagement("Sugar", "packet", 30)); // Initial quantity of sugar
    cafeInventory.push_back(InventoryManagement("Plastic cup", "piece", 200)); // Initial quantity of plastic cups
    cafeInventory.push_back(InventoryManagement("Packaging", "box", 100)); // Initial quantity of packaging

}
float Total(BILL bill)
{
    float total = 0;
    total = total + bill.amount;
    return total;
}
void updateInventory(vector<InventoryManagement> &cafeInventory) {
    string name;
    cout << "Please input inventory to update: ";
    cin >> name;
    for (int i = 0; i < cafeInventory.size(); i++) {
        if (name == cafeInventory[i].name) {
            int newQuantity;
            cout << "Input new quantity: ";
            cin >> newQuantity;
            cafeInventory[i].setAmount(newQuantity); // Đặt lại số lượng của sản phẩm
            cout << "Inventory updated successfully!" << endl;
            return;
        }
    }
    cerr << "Product not found in the inventory!" << endl;
}

void ShowInventory(vector<InventoryManagement> cafeInventory)
{
    // Display information about the products in the café
    cout << "List of products in the cafe:" << endl;
    cout << "--------------------------------" << endl;
    for (vector<InventoryManagement>::iterator it = cafeInventory.begin(); it != cafeInventory.end(); ++it) {
        it->show();
    }
}

void program()
{
    MENU staff;
    BILL Bill;
    
    vector <InventoryManagement> IV;
    setupCafeInventory(IV);
    int x;
    float total = 0;
    while(x != 4)
    {
        system("cls");
        cout << "=== Main Program ===";
        cout << "\n1. Manage Staff";
        cout << "\n2. Display Menu";
        cout << "\n3. Manage Inventory";
        cout << "\nYour choice: ";
        cin >> x;
        
        switch(x)
        {
        case 1:
            staff.PrintMenu();
            break;
        case 2:
            Bill.ShowMenu();
            Bill.BillPlay();
            total = total + Total(Bill);
            cout << "Total prevenue: " << total << endl;
            system("pause");
            break;
        case 3:
            int x; 
            cout << "1. Print list inventory " << endl;
            cout << "2. Change quantity of inventory " << endl;
            cout << "Input your choice: ";
            cin >> x;
            if(x == 1)
            {
                ShowInventory(IV);
            }
            else{
                updateInventory(IV);
            }
            system("pause");
            break;
        } 
    }
}

int main()
{
    program();
    return 0;
}