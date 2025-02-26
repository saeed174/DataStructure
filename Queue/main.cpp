#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    Queue<int> q1;

    q1.push(25);
    q1.push(20);
    q1.push(15);
    q1.push(10);

    cout << q1.Top() <<" ";
    q1.pop();
    cout << q1.Top() <<" ";
    q1.pop();
    cout << q1.Top() <<" ";
    q1.pop();


    return 0;
}