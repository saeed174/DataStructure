#include <iostream>
#include <vector>
#include "Sort.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    // auto start = high_resolution_clock::now();
    // vector<int> arr = {2,3,7,5,8};
    // vector<int> arr1 = {0,1,4,9,10};
    // int arr2[] = {8,5,7,3,2,10};
    vector<int> arr2 = {8,5,7,3,2,10};

    Heap_sort(arr2);
    
    for(int i = 0 ; i < 6 ; i++)
    {
        cout << arr2[i] << " ";
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << "\nTime taken by function: " << duration.count() << " microseconds" << "\n";
    return 0;
}