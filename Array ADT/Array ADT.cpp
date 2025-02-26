#include <iostream>
#include "Array.h"
#include <algorithm>

using namespace std;
int main()
{
    Array<int> arr(25);
    arr.Fill(10);
    arr.Display();
    
    if (arr.Is_sorted())
    {
        cout << "The array is sorted\n";
    }
    else
    {
        cout << "The array is Not sorted\n";
    }

    Array<int> arr2(15);
    arr2.Fill(10); 
    arr2.Display();

    Array<int> arr3(arr.Get_size() + arr2.Get_size());
    arr3.Merge(arr, arr2);
    arr3.Display();




    return 0;
}
