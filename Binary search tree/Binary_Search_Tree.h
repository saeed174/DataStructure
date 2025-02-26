// Properties :
// 1 - No Duplicated
// 2 - Inorder gives sorted order

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

template <class T>
class Node
{
    public :
        T data;
        Node<T>* Lchild;
        Node<T>* Rchild;
};

template <class T>
class Binary_Search_Tree
{
    private :
        Node<T>* root = nullptr;
        void in_order(Node<T>* p);
        Node<T>*  RDelete(Node<T>* p,T key);
        int get_hight(Node<T>* p);
        Node<T>* InPre(Node<T>* p);
        Node<T>* InSucc(Node<T>* p);
    public :
        Binary_Search_Tree();
        Binary_Search_Tree(int sz);
        Binary_Search_Tree(T arr[] , int sz);
        Binary_Search_Tree(vector<T> arr);
        Binary_Search_Tree(deque<T> arr);
        void insert(T element);
        bool search(T key);
        void Display();
        void Delete(T key);
        int hight();
        void pre_create(T arr[] , int sz);
        ~Binary_Search_Tree();
};

template <class T>
void Binary_Search_Tree<T>::insert(T element)
{
    if(root == nullptr)
    {
        root = new Node<T>;
        root->data = element;
        root->Lchild = nullptr;
        root->Rchild = nullptr;
        return;
    }
    else
    {
        char dir;
        Node<T>* temp = root;
        while(temp != nullptr)
        {
            if(element > temp->data)
            {
                if(temp->Rchild != nullptr)
                    temp = temp->Rchild;
                else
                {
                    dir = 'R';
                    break;
                }
            }
            else if(element < temp->data)
            {
                if(temp->Lchild != nullptr)
                    temp = temp->Lchild;
                else
                {
                    dir = 'L';
                    break;
                }
            }
            else if(element == temp->data)
            {
                cout << "This is an exist element\n";
                return;
            }
        }
        Node<T>* add = new Node<T>;
        add->data = element;
        if(dir == 'R')
            temp->Rchild = add;
        else
            temp->Lchild = add;
        add->Lchild = nullptr;
        add->Rchild = nullptr;
    }
}

template <class T>
Binary_Search_Tree<T>::Binary_Search_Tree()
{
    root = nullptr;
}

template <class T>
void Binary_Search_Tree<T>::pre_create(T arr[] , int sz)
{
    stack<Node<T>*> store;
    Node<T>* temp;
    int i = 0;
    root = new Node<T>;
    root->data = arr[i++];
    root->Lchild = root->Rchild = nullptr;
    temp = root;
    while(i<sz)
    {
        if(arr[i] < temp->data)
        {
            Node<T>* add = new Node<T>;
            add->data = arr[i++];
            add->Lchild = add->Rchild = nullptr;
            temp->Lchild = add;
            store.push(temp);
            temp = add;
        }
        else
        {
            if(!store.empty())
            {
                if(arr[i] > temp->data && arr[i] < store.top()->data)
                {
                    Node<T>* add = new Node<T>;
                    add->data = arr[i++];
                    add->Lchild = add->Rchild = nullptr;
                    temp->Rchild = add;
                    temp = add;
                }
                else
                {
                    temp = store.top();
                    store.pop();
                }
            }
            else
            {
                Node<T>* add = new Node<T>;
                add->data = arr[i++];
                add->Lchild = add->Rchild = nullptr;
                temp->Rchild = add;
                temp = add;
            }
        }
    }

}

template <class T>
Binary_Search_Tree<T>::Binary_Search_Tree(int sz)
{
    cout << "Lets fill the Binary tree : \n";
    for(int i = 0 ; i < sz ; i++)
    {
        int add;
        cout << "Enter the element no." << i+1 << " : ";
        cin >> add;
        this->insert(add);
    }
}

template <class T>
Binary_Search_Tree<T>::Binary_Search_Tree(T arr[],int sz)
{
    for(int i = 0 ; i < sz ; i++)
    {
        this->insert(arr[i]);
    }
}

template <class T>
Binary_Search_Tree<T>::Binary_Search_Tree(vector<T> arr)
{
    for(int i = 0 ; i < arr.size() ; i++)
    {
        this->insert(arr[i]);
    }
}

template <class T>
Binary_Search_Tree<T>::Binary_Search_Tree(deque<T> arr)
{
    for(int i = 0 ; i < arr.size() ; i++)
    {
        this->insert(arr[i]);
    }
}

template <class T>
bool Binary_Search_Tree<T>::search(T key)
{
    if(root == nullptr)
        return false;
    else
    {
        Node<T>* temp = root;
        while(temp != nullptr)
        {
            if(temp->data == key)
            {
                return true;
            }
            else if(key > temp->data)
            {
                temp = temp->Rchild;
            }
            else
            {
                temp = temp->Lchild;
            }
        }
        return false;
    }
}
        
template <class T>
void Binary_Search_Tree<T>::in_order(Node<T>* p)
{
    if(p != nullptr)
    {
        in_order(p->Lchild);
        cout << p->data << " ";
        in_order(p->Rchild);
    }
}

template <class T>
void Binary_Search_Tree<T>::Display()
{
    in_order(root);
    cout << "\n";
}

template <class T>
int Binary_Search_Tree<T>::get_hight(Node<T>* p)
{
    int x = 0 ,y = 0;
    if(p == nullptr)
        return 0;
    
    x = get_hight(p->Lchild);
    y = get_hight(p->Rchild);

    if(x>y)
        return x+1;
    else
        return y+1;
}

template <class T>
int Binary_Search_Tree<T>::hight()
{
    return get_hight(root);
}

template <class T>
Node<T>* Binary_Search_Tree<T>::InPre(Node<T>* p)
{
    while(p != nullptr && p->Rchild != nullptr)
        p = p->Rchild;

        return p;
}

template <class T>
Node<T>* Binary_Search_Tree<T>::InSucc(Node<T>* p)
{
    while(p != nullptr && p->Lchild != nullptr)
        p = p->Lchild;

        return p;
}

template <class T>
Node<T>*  Binary_Search_Tree<T>::RDelete(Node<T>* p,T key)
{
    if(p == nullptr)
        return nullptr;
    if(p->Lchild == nullptr && p->Rchild == nullptr)
    {
        if(p == root)
            root == nullptr;
        free(p);
        return nullptr;
    }
    if(key < p->data)
        p->Lchild = RDelete(p->Lchild,key);
    else if(key > p->data)
        p->Rchild = RDelete(p->Rchild,key);
    else
    {
        if(get_hight(p->Lchild) > get_hight(p->Rchild))
        {
            Node<T>* temp = InPre(p->Lchild);
            p->data = temp->data;
            p->Lchild = RDelete(p->Lchild,temp->data);
        }
        else
        {
            Node<T>* temp = InSucc(p->Rchild);
            p->data = temp->data;
            p->Rchild = RDelete(p->Rchild,temp->data);
        }
    }
    return p;
}

template <class T>
void Binary_Search_Tree<T>::Delete(T key)
{
    RDelete(root,key);
}

template <class T>
Binary_Search_Tree<T>::~Binary_Search_Tree()
{

}
#endif // Binary_Search_Tree