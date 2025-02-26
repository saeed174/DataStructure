#include <iostream>
#include <vector>
#include <deque>
#include "Binary_Search_Tree.h"
using namespace std;

int main()
{
    int array[8] = {30,20,10,15,25,40,50,45};
    Binary_Search_Tree<int> b;
    b.pre_create(array,8);
    b.Display();

    return 0;
}