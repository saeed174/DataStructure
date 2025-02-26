#include <iostream>
#include "Binary tree.h"
using namespace std;

int main()
{
    Binary_tree<int> b1(7);
    b1.fill_tree();
    b1.Display();
    cout << b1.get_at(3) << "\n";
    cout << b1.get_parent(3) << "\n";
    cout << b1.get_left_child(3) << "\n";
    cout << b1.get_right_child(3) << "\n";
}
