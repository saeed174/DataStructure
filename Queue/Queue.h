#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <class T>
class Node
{
public :
    T data;
    Node<T>* next;
};

template <class T>
class Queue
{
private:
    Node<T>* top;
    Node<T>* rear;
public:
    Queue();
    void push(T element);
    T    Top();
    void pop();
    bool empty();
    bool full();
    ~Queue();
};

template <class T>
Queue<T>::Queue()
{
    top = nullptr;
    rear = nullptr;
}

template <class T>
void Queue<T>::push(T element)
{
    Node<T>* temp = new Node<T>;

    if(temp == NULL)
    {
        cout << "It is a full queue\n";
        return;
    }

    temp->data = element;
    temp->next = nullptr;
    if(top == nullptr)
    {
        top = temp;
        rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

template <class T>
T Queue<T>::Top()
{
    if(top == nullptr)
    {
        cout << "It is an empty queue\n";
        return T();
    }

    return top->data;
}

template <class T>
void Queue<T>::pop()
{
    if(top == nullptr)
    {
        cout << "It is an empty queue\n";
        return;
    }
    
    Node<T>* temp = top;
    top = top->next;
    delete temp;
}

template <class T>
bool Queue<T>::empty()
{
    if(top == nullptr)
        return true;
    else
        return false;
}

template <class T>
bool Queue<T>::full()
{
    Node<T>* temp = new Node<T>;
    if(temp == NULL)
    
        return true;
    else
        return false;
}

template <class T>
Queue<T>::~Queue()
{
}

#endif