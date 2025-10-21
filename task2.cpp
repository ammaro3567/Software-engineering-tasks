#include <iostream>
using namespace std;

class laptop {
public:
    string Brand;
    string Color;
    int Price;

  void Print(){
        cout << "Brand: " << Brand << endl;
        cout << "Color: " << Color << endl;
        cout << "Price: " << Price << endl;
  }
};

int main() {
    laptop l;
    l.Brand = "Dell";
    l.Color = "Silver";
    l.Price = 15000;
    l.Print();
    return 0;
}
