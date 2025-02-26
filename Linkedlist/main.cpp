#include <iostream>
#include <algorithm>
#include <vector>
#include "Linkedlist.h"
using namespace std;

int main()
{
    Linkedlist<int> list;

    if(list.is_impty())
        cout << "It is an empty list\n";

    int itt;
    cout << "Enter the number of element you want to insert : ";
    cin >> itt;

    for(int i = 0 ; i < itt ; i++)
    {
        int new_element;
        cout << "Enter the element no." << i+1 << " : ";
        cin >> new_element;

        list.push_back(new_element);
    }

    list.Display();
    cout << "================================\n";
    if(list.search(25))
    {
        cout << "Exist\n";
    }
    else
    {
        cout << "non exist\n";
    }

    list.Delete_at(0);

    list.Display();
    cout << "================================\n";

    list.insert_at(0,-5);
    list.Display();
    cout << "================================\n";

    list.sort();
    list.Display();
    cout << "================================\n";

    cout << "Max Element in the list : " << list.max() << "\n";
    cout << "Min Element in the list : " << list.min() << "\n";


    
    return 0;
}