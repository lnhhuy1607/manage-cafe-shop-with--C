#include <iostream>
#include <vector>
#include <string>

using namespace std;


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
    public:
        void ShowMenu();
        void Pay();
};

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
    menu[9].Input(10, "Break    ", "Food", 5000, "X");
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
    ShopName = "    KAKA Coffee";
    cout << "Product order: ";
    cin >> Chose;
    cout << "Quantity: ";
    cin >> Number;
    Tax = 0.08;
    cout << "Payment method (1: Cash, 2: Credit): ";
    cin >> Payment_method;
    Total_amount = menu[Chose - 1].price * Number * 0.92;
    cout << "----------------BILL---------------\n";
    cout << "\t" << ShopName << endl;
    cout << Chose << ". " << menu[Chose - 1].name << endl;
    cout << "Tax: " << Tax << endl;
    cout << "Quatity: " << Number << endl;
    if(Payment_method == 1)
    {
        cout << "Payment Method: Cash " << endl;
    }
    else
    {
        cout << "Payment Method: Credit " << endl;
    }
    cout << "Total amount: " << Total_amount << endl;
    cout << "----------------------------------\n";
}
int main()
{
    BILL bill;
    bill.ShowMenu();
    bill.Pay();
}
