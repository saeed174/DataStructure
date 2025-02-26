#include <iostream>
#include "AVL_Tree.h"
using namespace std;

int main()
{
    AVL_Tree<int> t1;
    
    int  sz;
    cout << "How many element do you want to insert : ";
    cin >> sz;

    for(int i = 0 ; i < sz ; i++)
    {
        int add;
        cout << "Enter element no." << i+1 << " : ";
        cin >> add;
        t1.insert(add);
    }

    t1.Display();
    cout << t1.root->data << "\n";

    t1.Delete(75);
    t1.Display();
    cout << t1.root->data << "\n";

    return 0;
}