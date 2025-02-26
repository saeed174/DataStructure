// Sorting techniques :
// 1- Bubble
// 2- Inserion         O(n^2)
// 3- Selection

// 4- Heap sort
// 5- merge sort        O(nlogn)
// 6- Quick sort
// 7- Tree sort

// 8- Shell sort        O(n^(3/2))

// 9- count sort        O(n) but large memory space
// 10- Radix sort
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

template <class T> // complexity O(n^2) , coparision O(n^2) , no.swaps O(n^2) , Adaptive , Stable
void Bubble_sort(T arr[],int sz)
{
    for(int i = 0 ; i < sz-1; i++)
    {
        bool swap = 0;
        for(int j = 0 ; j < sz-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap = 1;
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(!swap)
            break;
    }
}

template <class T>
void Bubble_sort(vector<T> &array)
{
    for(int i = 0 ; i < array.size()-1 ; i++)
    {
        bool swap = 0;
        for(int j = 0 ; j < array.size()-1 ; j++)
        {
            if(array[j] > array[j+1])
            {
                swap = 1;
                T temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
        if(!swap)
            break;
    }
}

template <class T>
void Bubble_sort(deque<T> &array)
{
    for(int i = 0 ; i < array.size()-1 ; i++)
    {
        bool swap = 0;
        for(int j = 0 ; j < array.size()-1 ; j++)
        {
            if(array[j] > array[j+1])
            {
                swap = 1;
                T temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
        if(!swap)
            break;
    }
}


template <class T> // complexity O(n^2) , coparision O(n^2) , no.swaps O(n^2)
void Insertion_sort(T arr[] , int sz)
{
    int rearr = 2;
    for(int i = 1 ; i < sz ; i++)
    {
        for(int j = rearr-1 ; j > 0 ; j--)
        {
            if(arr[j] < arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
        rearr++;
    }
}

template <class T>
void Insertion_sort(vector<T> &arr)
{
    int rearr = 2;
    for(int i = 1 ; i < arr.size() ; i++)
    {
        for(int j = rearr-1 ; j > 0 ; j--)
        {
            if(arr[j] < arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
        rearr++;
    }
}

template <class T>
void Insertion_sort(deque<T> &arr)
{
    int rearr = 2;
    for(int i = 1 ; i < arr.size() ; i++)
    {
        for(int j = rearr-1 ; j > 0 ; j--)
        {
            if(arr[j] < arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
        rearr++;
    }
}

/*
                | Bubble sort | Insertion sort|
    ==========================================|
    min comp    |      O(n)   |     O(n)      |
    ==========================================|
    max comp    |     O(n^2)  |    O(n^2)     |
    ==========================================|
    min swap    |     O(1)    |    O(1)       |
    ==========================================|
    max swap    |     O(n^2)  |    O(n^2)     |
    ==========================================|
    adaptive    |     Yes     |    Yes        |
    ==========================================|
    stable      |     Yes     |    Yes        |
    ==========================================|
    linked list |      No     |    Yes        |
    ==========================================|
    key passing |      No     |    Yes        |
*/



template <class T> // complexity O(n^2) , coparision O(n^2) , no.swaps O(n), NOT Adaptive , Not Stable
void Selection_sort(T arr[], int sz)
{
    for(int i = 0 ; i < sz-1 ; i++)
    {
        int j,k;
        j = k = i;
        while (j < sz)
        {
            if(arr[j] < arr[k])
            {
                k = j;
            }
            j++;
        }
        swap(arr[i],arr[k]);
    }
}

template <class T> 
void Selection_sort(vector<T> &arr)
{
    for(int i = 0 ; i < arr.size()-1 ; i++)
    {
        int j,k;
        j = k = i;
        while (j < arr.size())
        {
            if(arr[j] < arr[k])
            {
                k = j;
            }
            j++;
        }
        swap(arr[i],arr[k]);
    }
}

template <class T> 
void Selection_sort(deque<T> &arr)
{
    for(int i = 0 ; i < arr.size()-1 ; i++)
    {
        int j,k;
        j = k = i;
        while (j < arr.size())
        {
            if(arr[j] < arr[k])
            {
                k = j;
            }
            j++;
        }
        swap(arr[i],arr[k]);
    }
}

template<class T>
void Heap_sort(T arr[] , int sz)
{
    priority_queue<T, vector<T> , greater<T>> rearr(arr,arr+sz);
    int i = 0;
    while(!rearr.empty())
    {
        arr[i++] = rearr.top();
        rearr.pop();
    }
}

template<class T>
void Heap_sort(vector<T> &arr)
{
    priority_queue<T, vector<T> , greater<T>> rearr(arr.begin(),arr.end());
    int i = 0;
    while(!rearr.empty())
    {
        arr[i++] = rearr.top();
        rearr.pop();
    }
}

template<class T>
void Heap_sort(deque<T> &arr)
{
    priority_queue<T, vector<T> , greater<T>> rearr(arr.begin(),arr.end());
    int i = 0;
    while(!rearr.empty())
    {
        arr[i++] = rearr.top();
        rearr.pop();
    }
}


template<class T>
int partition(T arr[] , int l , int h)
{
    int pivot = arr[l];
    int i = l , j = h;

    do
    {
        do{i++;}while (arr[i] <= pivot);
        do{j--;}while (arr[j] > pivot);
        if(i<j) swap(arr[i] , arr[j]);
    }while (i < j);

    swap(arr[l], arr[j]);
    return j;
}

template<class T>
void Quick_sort(T arr[],int l,int h)
{
    int j;
    if(l<h)
    {
        j = partition(arr,l,h);
        Quick_sort(arr,l,j);
        Quick_sort(arr,j+1,h);
    }
}

template<class T>
int partition(vector<T> &arr, int l , int h)
{
    int pivot = arr[l];
    int i = l , j = h;

    do
    {
        do{i++;}while (arr[i] <= pivot);
        do{j--;}while (arr[j] > pivot);
        if(i<j) swap(arr[i], arr[j]);
    }while (i<j);

    swap(arr[l], arr[j]);
    return j;
}

template<class T>
void Quick_sort(vector<T> &arr,int l,int h)
{
    int j;
    if(l<h)
    {
        j = partition(arr,l,h);
        Quick_sort(arr,l,j);
        Quick_sort(arr,j+1,h);
    }
}

template<class T>
int partition(deque<T> &arr, int l , int h)
{
    int pivot = arr[l];
    int i = l , j = h;

    do
    {
        do{i++;}while (arr[i] <= pivot);
        do{j--;}while (arr[j] > pivot);
        if(i<j) swap(arr[i], arr[j]);
    }while (i<j);

    swap(arr[l], arr[j]);
    return j;
}

template<class T>
void Quick_sort(deque<T> &arr,int l,int h)
{
    int j;
    if(l<h)
    {
        j = partition(arr,l,h);
        Quick_sort(arr,l,j);
        Quick_sort(arr,j+1,h);
    }
}

template<class T>
T* Merge(T arr1 [] , T arr2 [] , int sz1 , int sz2)
{
    int i,j,k;
    i = j = k = 0;
    T *arr3 = new T[sz1+sz2];

    while(i < sz1 && j < sz2)
    {
        if(arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    for(;i < sz1 ; i++)
    {
        arr3[k++] = arr1[i];
    }
    for(;j < sz2 ; j++)
    {
        arr3[k++] = arr2[j];
    }

    return arr3;
}

template<class T>
vector<T> Merge(vector<T> arr1 , vector<T> arr2)
{
    int i,j,k;
    int sz1 = arr1.size();
    int sz2 = arr2.size();
    i = j = k = 0;
    vector<T> arr3(sz1+sz2);

    while(i < sz1 && j < sz2)
    {
        if(arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    for(;i < sz1 ; i++)
    {
        arr3[k++] = arr1[i];
    }
    for(;j < sz2 ; j++)
    {
        arr3[k++] = arr2[j];
    }

    return arr3;
}

template<class T>
deque<T> Merge(deque<T> arr1 , deque<T> arr2)
{
    int i,j,k;
    int sz1 = arr1.size();
    int sz2 = arr2.size();
    i = j = k = 0;
    deque<T> arr3(sz1+sz2);

    while(i < sz1 && j < sz2)
    {
        if(arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    for(;i < sz1 ; i++)
    {
        arr3[k++] = arr1[i];
    }
    for(;j < sz2 ; j++)
    {
        arr3[k++] = arr2[j];
    }

    return arr3;
}

template<class T>
void Merge(T arr[],int l,int mid,int h)
{
    int i , j , k;
    T b[h+1] = {};
    i = l ; j = mid+1 ; k = l;
    while(i <= mid && j <= h)
    {
        if(arr[i] < arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }

    for(; i <= mid ; i++)
        b[k++] = arr[i];
    for(; j <= h ; j++)
        b[k++] = arr[j];

    for(int i = l ; i <= h ; i++)
    {
        arr[i] = b[i];
    }
}

template<class T>
void Merge_sort(T arr[] , int sz)
{
    int p,i,l,mid,h;

    for(p = 2 ; p <= sz ; p*=2)
    {
        for(i = 0 ; i+p-1 < sz ; i+=p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(arr,l,mid,h);
        }
    }

    if(p/2 < sz)
        Merge(arr,0,p/2-1,sz-1);
}

template<class T>
void rec_Merge_sort(T arr[] , int l , int h)
{
    if(l < h)
    {
        int mid = (l+h)/2;
        rec_Merge_sort(arr,l,mid);
        rec_Merge_sort(arr,mid+1,h);
        Merge(arr,l,mid,h);
    }
}


template<class T>
int find_max(T arr[] , int sz)
{
    T mx = T();
    for(int i = 0 ; i < sz ; i++)
    {
        if(arr[i] > mx)
            mx = arr[i];
    }

    return (sz != 0) ? mx : 0;
}

template<class T>
void Count_sort(T arr[] , int sz)
{
    int mx = find_max(arr,sz);
    T temp[mx+1] = {0};
    for(int i = 0 ; i < sz ; i++)
    {
        temp[arr[i]]++;
    }
    int j = 0;
    for(int i = 0 ; i < mx+1 ; i++)
    {
        while(temp[i]--)
        {
            arr[j++] = i;
        }
    }
}

