#include <string>
using namespace std;
class Menu
{
public:
    string Name;
    string type; // drink or food
    int price;
    char size; //S M L
public:
    Menu(string Name, string type, int price, char size);
};

Menu::Menu(string name, string type, int price, char size)
{
    this -> Name = name;
    this -> type = type;
    this -> price = price;
    this -> size = size;
}
