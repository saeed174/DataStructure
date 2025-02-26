// It is an complete Binary tree
// In Max_Heap : every node shoud have an element greater than or equal its decendants (اي كل عنصر اكبر من العناصر الي تحته)
// In Min_Heap : every node shoud have an element less than or equal its decendants (اي كل عنصر اصغر من العناصر الي تحته)

// the height && insertion time always = log(n) base 2 
#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;

template <class T>
class Heap
{
    private :
        T* arr;
        int length;
        int size;
    public :
       Heap();
       Heap(int sz);
       void set_size(int sz);
       void insert(T data);
       void Display();
       bool Search(T key);
       void Delete();
       void another_Delete();
       ~Heap(); 
};

template <class T>
Heap<T>::Heap()
{
    arr = nullptr;
    length = 0;
    size = 0;
}

template <class T>
Heap<T>::Heap(int sz)
{
    arr = new T[sz];
    size = sz;
    length = 0;
}

template <class T>
void Heap<T>::set_size(int sz)
{
    delete [] arr;
    arr = new T[sz];
    size = sz;
    length = 0;
}

template <class T>
void Heap<T>::insert(T data)
{
    if (length > size) 
    {
        cout << "Heap is full!" << endl;
        return;
    }

    arr[length] = data;
    T temp = data;
    int i = length;
    while(i > 0 && temp > arr[i/2])
    {
        arr[i] = arr[i/2];
        i/=2;
    }
    arr[i] = temp;
    length++;
}

template <class T>
bool Heap<T>::Search(T key)
{
    for(int i = 0 ; i < length ; i++)
    {
        if(arr[i] == key)
        {
            return true;
        }
    }
    return false;
}

template <class T>
void Heap<T>::another_Delete()
{
    if(length == 0)
    {
        cout << "It is an empty heap\n";
    }
    else
    {
        for(int i = 0 ; i < length-1 ; i++)
            arr[i] = arr[i+1];
        arr[length-1] = 0;
        length--;
    }
}

template <class T>
void Heap<T>::Delete()
{
    arr[0] = arr[length-1];
    T temp = arr[0];
    int i = 0,j = 2*i;
    length--;
    while(j < length)
    {
        if(arr[j+1] > arr[j])
            j++;
        if(arr[i] < arr[j])
        {
            swap(arr[i],arr[j]);
            i = j;
            j = 2*j;
        }
        else
        {
            break;
        }
    }
}

template <class T>
void Heap<T>::Display()
{
    for(int i = 0 ; i < length ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

template <class T>
Heap<T>::~Heap()
{
    // delete [] arr;
}

#endif