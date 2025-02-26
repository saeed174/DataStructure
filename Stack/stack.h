#ifndef STACk_H
#define STACk_H 
#include <iostream>
using namespace std;

template <class T>
class Node
{
public :
    T data;
    Node* next;
};

template <class T>
class Stack
{
private : 
    Node<T>* top;
    int length;

public :
    Stack(); 
    void push(T key);
    T    Top();
    void pop();
    bool empty();
    bool full();
    T    peek(int pos);
    int  size();
    ~Stack();
};

template <class T>
Stack<T>::Stack()
{
    top = nullptr;
    length = 0;
}

template <class T>
void Stack<T>::push(T key)
{
    Node<T>* temp = new Node<T>;
    if(temp == NULL)
    {
        cout << "Stack Overflow\n";
        return;
    }

    temp->data = key;
    if(top == nullptr)
    {
        top = temp;
        temp->next = nullptr;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
    length++;
}


template <class T>
T Stack<T>::Top()
{
    if(top == nullptr)
    {
        cout << "It is an empty stack\n";
        return T();
    }
    else
    {
        return top->data;
    }
}

template <class T>
void Stack<T>::pop()
{
    if(top == nullptr)
    {
        cout << "It is an empty stack\n";
        return;
    }
    Node<T>* temp = top;
    top = top->next;

    delete temp;
    length--;
}

template <class T>
bool Stack<T>::empty()
{
    if(top == nullptr)
        return true;
    else
        return false;
}

template <class T>
bool Stack<T>::full()
{
    Node<T>* temp = new Node<T>;

    if(temp == nullptr)
        return true;
    else
    {
        delete temp;
        return false;
    }
}

template <class T>
T Stack<T>::peek(int pos)
{
    Node<T>* temp = top;
    while(pos-- != 1 && temp!= nullptr)
    {
        temp = temp->next;
    }
    if(temp == nullptr)
    {
        cout << "Invalid position\n";
        return T();
    }
    return temp->data;
}

template <class T>
int Stack<T>::size()
{
    return length;
}

template <class T>
Stack<T>::~Stack()
{
    delete top;
}
#endif