#include <iostream>
#include "Heap.h"
using namespace std;

int main()
{
    Heap<int> h1(50);
    int sz;
    cout << "Enter the number of element you want to insert in heap : ";
    cin >> sz;

    for (int i = 0; i < sz; i++) 
    {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        h1.insert(value);
    }
    h1.Display();
    cout << "Max : " << h1.max() << "\n";
    cout << "Min : " << h1.min() << "\n";
    h1.insert(5);
    h1.Delete();
    h1.Display();

    return 0;
}