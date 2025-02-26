#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
using namespace std;

template <class T>
class Binary_tree
{
private :
    T* arr;
    int size;

public : 
    Binary_tree(int size);
    T get_at(int index);
    T get_left_child(int index);
    T get_right_child(int index);
    T get_parent(int index);
    void fill_tree();
    void Display();
    ~Binary_tree();
};

template <class T>
Binary_tree<T>::Binary_tree(int size)
{
    arr = new T[size+1];
    this->size = size;
}

template <class T>
T Binary_tree<T>::get_at(int index)
{
    return arr[index];
}

template <class T>
T Binary_tree<T>::get_left_child(int index)
{
    if((2*index) > size)
    {
        cout << "Out of boundry\n";
        return T();
    }
    else
    {
        return arr[2*index];
    }
}

template <class T>
T Binary_tree<T>::get_right_child(int index)
{
    if((2*index+1) > size)
    {
        cout << "Out of boundry\n";
        return T();
    }
    else
    {
        return arr[2*index+1];
    }
}

template <class T>
T Binary_tree<T>::get_parent(int index)
{
    if(index == 1)
    {
        cout << "It is the first Node = has not parents\n";
        return T();
    }
    else if(index > size)
    {
        cout << "Out of boundry\n";
        return T();
    }
    else
    {
        return arr[index/2];
    }
}

template <class T>
void Binary_tree<T>::fill_tree()
{
    for(int i = 1 ; i <= size ; i++)
    {
        cout << "Enter the element no." << i << " : ";
        cin >> arr[i];
    }
}

template <class T>
void Binary_tree<T>::Display()
{
    for(int i = 1 ; i <= size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

template <class T>
Binary_tree<T>::~Binary_tree()
{
    delete arr;
}

#endif