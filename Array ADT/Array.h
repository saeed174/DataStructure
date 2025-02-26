#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

template <class T>
class Array
{
public:
    Array();
    Array(int siz);
    virtual ~Array();
    void Display();
    bool Is_empty();
    void Fill(int len);
    void Append(T data);
    void Insert(int index, T data);
    void Delete(int index);
    bool Search(T data);
    int  Get_length();
    int  Get_size();
    int  Get_index(T data);
    T    Get(int index);
    void Set(int index, T data);
    T    Max();
    T    Min();
    T    Sum();
    T    Average();
    void Reverse();
    void Sort();
    void Swap(int ind1,int ind2);
    bool Binary_search(T key);
    int  Binary_search_index(T key);
    void Left_shift();
    void Right_shift();
    void Insert_in_sorted(T data);
    void Resize(int new_size);
    bool Is_sorted();
    void Merge(Array a, Array b);
    void Union(Array a, Array b);
    Array<T>& operator=(const Array<T>& other);

private:
    T* ptr;
    int size;
    int length;
};
#endif // ARRAY_H

template <class T>
Array<T>::Array()
{
    size = 0;
    ptr = nullptr;
    length = 0;
}

template <class T>
Array<T>::Array(int siz)
{
    size = siz;
    ptr = new T[size];
    length = 0;
}

template <class T>
void Array<T>::Display()
{
    if (length == 0)
    {
        cout << "The array is empty\n";
        return;
    }
    for (int i = 0; i < length; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << "\n";
}

template <class T>
bool Array<T>::Is_empty()
{
    return length == 0;
}

template <class T>
void Array<T>::Fill(int len)
{
    if (len > size)
    {
        cout << "Not enough space to fill the array\n";
        return;
    }
    for (int i = 0; i < len; i++)
    {
        cout << "Enter element no." << i + 1 << ": ";
        cin >> ptr[i];
    }
    length = len;
}

template <class T>
void Array<T>::Append(T data)
{
    if (length < size)
    {
        ptr[length] = data;
        length++;
    }
    else
    {
        cout << "Array is full\n";
    }
}

template <class T>
void Array<T>::Insert(int index, T data)
{
    if (index >= size)
    {
        cout << "Index out of bounds\n";
        return;
    }
    if (index >= length)
    {
        ptr[index] = data;
        length = index + 1;
    }
    else
    {
        for (int i = length; i > index; i--)
        {
            ptr[i] = ptr[i - 1];
        }
        ptr[index] = data;
        length++;
    }
}

template <class T>
void Array<T>::Delete(int index)
{
    if (length == 0)
    {
        cout << "The array is empty\n";
        return;
    }
    if (index >= length)
    {
        cout << "Invalid index\n";
        return;
    }
    for (int i = index; i < length - 1; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    length--;
}

template <class T>
bool Array<T>::Search(T data)
{
    for (int i = 0; i < length; i++)
    {
        if (ptr[i] == data)
        {
            return true;
        }
    }
    return false;
}

template<class T>
inline int Array<T>::Get_length()
{
    return length;
}

template<class T>
inline int Array<T>::Get_size()
{
    return size;
}

template <class T>
int Array<T>::Get_index(T data)
{
    for (int i = 0; i < length; i++)
    {
        if (ptr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

template <class T>
T Array<T>::Get(int index)
{
    if (index >= length || index < 0)
    {
        cout << "Index out of bounds\n";
        return T();
    }
    return ptr[index];
}

template <class T>
void Array<T>::Set(int index, T data)
{
    if (index >= length || index < 0)
    {
        cout << "Index out of bounds\n";
        return;
    }
    ptr[index] = data;
}

template <class T>
T Array<T>::Max()
{
    if (length == 0)
    {
        cout << "The array is empty\n";
        return T();
    }
    T mx = ptr[0];
    for (int i = 1; i < length; i++)
    {
        if (ptr[i] > mx)
        {
            mx = ptr[i];
        }
    }
    return mx;
}

template <class T>
T Array<T>::Min()
{
    if (length == 0)
    {
        cout << "The array is empty\n";
        return T();
    }
    T mn = ptr[0];
    for (int i = 1; i < length; i++)
    {
        if (ptr[i] < mn)
        {
            mn = ptr[i];
        }
    }
    return mn;
}

template<class T>
inline T Array<T>::Sum()
{
    T total = T();
    if (length == 0)
    {
        cout << "The array is empty\n";
        return T();
    }

    for (int i = 0; i < length; i++)
    {
        total += ptr[i];
    }
    return total;
}

template<class T>
inline T Array<T>::Average()
{
    T total = T();
    if (length == 0)
    {
        cout << "The array is empty\n";
        return T();
    }

    for (int i = 0; i < length; i++)
    {
        total += ptr[i];
    }
    return total/length;
}

template <class T>
void Array<T>::Reverse()
{
    if (length == 0)
    {
        cout << "The array is empty\n";
        return;
    }
    int ed = length - 1;
    for (int i = 0; i < length / 2; i++)
    {
        T temp = ptr[i];
        ptr[i] = ptr[ed];
        ptr[ed] = temp;
        ed--;
    }
}

template<class T>
inline void Array<T>::Sort()
{
    std::sort(ptr, ptr + length);
}

template<class T>
inline void Array<T>::Swap(int ind1, int ind2)
{
    T temp = ptr[ind1];
    ptr[ind1] = ptr[ind2];
    ptr[ind2] = temp;
}

template<class T>
inline bool Array<T>::Binary_search(T key)
{
    Sort();

    int lower = 0;
    int higher = length - 1;
    int middle = (lower + higher) / 2;


    while (lower <= higher)
    {
        middle = (lower + higher) / 2;
        if (ptr[middle] == key)
        {
            return 1;
        }
        else if (key > ptr[middle])
        {
            lower = middle + 1;
        }
        else if (key < ptr[middle])
        {
            higher = middle - 1;
        }
    }


    return false;
}

template<class T>
inline int Array<T>::Binary_search_index(T key)
{
    Sort();

    int lower = 0;
    int higher = length - 1;
    int middle = (lower + higher) / 2;


    while (lower <= higher)
    {
        middle = (lower + higher) / 2;
        if (ptr[middle] == key)
        {
            return middle;
        }
        else if (key > ptr[middle])
        {
            lower = middle + 1;
        }
        else if (key < ptr[middle])
        {
            higher = middle - 1;
        }
    }


    return -1;
}

template<class T>
inline void Array<T>::Left_shift()
{
    if (length == 0)
    {
        cout << "The array is empty\n";
        return;
    }
    T temp = ptr[0];
    for (int i = 0; i < length - 1; i++)
    {
        ptr[i] = ptr[i + 1];
    }
    ptr[length - 1] = temp;
}

template<class T>
inline void Array<T>::Right_shift()
{
    if (length == 0)
    {
        cout << "The array is empty\n";
        return;
    }
    T temp = ptr[length - 1];
    for (int i = length - 1 ; i > 0; i--)
    {
        ptr[i] = ptr[i - 1];
    }
    ptr[0] = temp;
}

template<class T>
inline void Array<T>::Insert_in_sorted(T data)
{
    if (length == size)
    {
        Resize(size + 1);
    }
    ptr[length] = data;
    length++;

    for (int i = length - 1; i >= 0; i--)
    {
        if (ptr[i] < ptr[i-1])
        {
            T temp = ptr[i];
            ptr[i] = ptr[i - 1];
            ptr[i - 1] = temp;
        }
        else
        {
            break;
        }
    }
}

template<class T>
inline void Array<T>::Resize(int new_size)
{
    T* temp = ptr;
    ptr = new T[new_size];

    for (int i = 0; i < length; i++)
    {
        ptr[i] = temp[i];
    }

    size = new_size;
    delete[] temp;
}

template<class T>
inline bool Array<T>::Is_sorted()
{
    for (int i = 0; i < length-1; i++)
    {
        if (ptr[i] > ptr[i + 1])
        {
            return false;
        }
    }
    return true;
}

template<class T>
inline void Array<T>::Merge(Array a, Array b)
{
    int i, j, k;
    i = j = k = 0;
    while (i < b.length && j < a.length)
    {
        if (b.ptr[i] < a.ptr[j])
        {
            ptr[k++] = ptr[i++];
        }
        else
        {
            ptr[k++] = a.ptr[j++];
        }
    }

    for (; i < b.length;)
    {
        ptr[k++] = b.ptr[i++];
    }

    for (; j < a.length;)
    {
        ptr[k++] = a.ptr[j++];
    }

    length = b.length + a.length;
}

template<class T>
inline Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other) {
        delete[] ptr;
        ptr = other.ptr;
        size = other.size;
        length = other.length;
        other.ptr = nullptr;
        other.size = 0;
        other.length = 0;
    }
    return *this;
}



template <class T>
Array<T>::~Array()
{
    delete[] ptr;
}