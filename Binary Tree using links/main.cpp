#include <iostream>
#include "Binary_tree.h"
using namespace std;

int main()
{
    Binary_tree<int> b1;
    cout << "Pre order Display : \n";
    b1.pre_order_Display();

    cout << "===================\n";

    cout << "Pre order Display : \n";
    b1.itt_pre_order_Display();
    
    cout << "===================\n";

    cout << "In order Display : \n";
    b1.in_order_Display();

    cout << "===================\n";

    cout << "In order Display : \n";
    b1.itt_in_order_Display();

    cout << "===================\n";

    cout << "post order Display : \n";
    b1.post_order_Display();

    cout << "Level order Display : \n";
    b1.level_order_Display();

    cout << "The hight of tree = " << b1.hight() << "\n";

    return 0;
}
