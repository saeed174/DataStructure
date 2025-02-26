#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    Stack<int> st;
    st.push(5);
    st.push(10);
    st.push(15);

    int length = st.size();

    for(int i = 0 ; i < length ; i++)
    {
        cout << st.Top() << " ";
        st.pop();
    }

    return 0;
}

