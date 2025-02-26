#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class T>
class Node
{
public : 
    T data;
    Node<T>* Rchild;
    Node<T>* Lchild;
};

template <class T>
class Binary_tree
{
private :
    Node<T>* root;
    queue<Node<T>*> store;
    void pre_order(Node<T>* p);
    void in_order(Node<T>* p);
    void post_order(Node<T>* p);
    int get_hight(Node<T>* p);

public :
    Binary_tree();
    void delete_tree(Node<T>* node);
    void pre_order_Display();
    void itt_pre_order_Display();
    void in_order_Display();
    void itt_in_order_Display();
    void post_order_Display();
    // void itt_post_order_Display();
    void level_order_Display();
    int  hight();
    ~Binary_tree();
    
};

template <class T>
Binary_tree<T>::Binary_tree()
{
    root = new Node<T>;
    cout << "Enter The Root value : ";
    T add;
    cin >> add;
    root->data = add;
    root->Lchild = root->Rchild = nullptr;
    store.push(root);
    while (!store.empty())
    {
        Node<T>* temp = store.front();
        store.pop();
        T set;
        cout << "Enter the left children of " << temp->data << " : ";
        cin >> set;
        if(set != -1)
        {
            Node<T>* left = new Node<T>;
            left->data = set;
            temp->Lchild = left;
            store.push(left);
        }
        else
        {
            temp->Lchild = nullptr;
        }
        cout << "Enter the right children of " << temp->data << " : ";
        T set2;
        cin >> set2;
        if(set2 != -1)
        {
            Node<T>* right = new Node<T>;
            right->data = set2;
            temp->Rchild = right;
            store.push(right);
        }
        else
        {
            temp->Rchild = nullptr;
        }
    }
    
}

template <class T>
void Binary_tree<T>::pre_order(Node<T>* p)
{
    if(p!= nullptr)
    {
        cout << p->data << " ";
        pre_order(p->Lchild);
        pre_order(p->Rchild);
    }
}

template <class T>
void Binary_tree<T>::pre_order_Display()
{
    pre_order(root);
    cout << "\n";
}

template <class T>
void Binary_tree<T>::itt_pre_order_Display()
{
    stack<Node<T>*> addr;
    Node<T>* temp = root;
    

    while (!addr.empty() || temp != nullptr)
    {
        if(temp != nullptr)
        {
            addr.push(temp);
            cout << temp->data << " ";
            temp = temp->Lchild;
        }
        else
        {
            temp = addr.top();
            addr.pop();
            temp = temp->Rchild;
        }
    }

    cout << "\n";
}

template <class T>
void Binary_tree<T>::itt_in_order_Display()
{
    stack<Node<T>*> addr;
    Node<T>* temp = root;
    

    while (!addr.empty() || temp != nullptr)
    {
        if(temp != nullptr)
        {
            addr.push(temp);
            temp = temp->Lchild;
        }
        else
        {
            temp = addr.top();
            addr.pop();
            cout << temp->data << " ";
            temp = temp->Rchild;
        }
    }

    cout << "\n";
}

template <class T>
void Binary_tree<T>::in_order(Node<T>* p)
{
    if(p != nullptr)
    {
        in_order(p->Lchild);
        cout << p->data << " ";
        in_order(p->Rchild);
    }
}

template <class T>
void Binary_tree<T>::in_order_Display()
{
    in_order(root);
    cout << "\n";
}

template <class T>
void Binary_tree<T>::post_order(Node<T>* p)
{
    if(p != nullptr)
    {
        post_order(p->Lchild);
        post_order(p->Rchild);
        cout << p->data << " ";
    }
}

template <class T>
void Binary_tree<T>::post_order_Display()
{
    post_order(root);
    cout << "\n";
}

template <class T>
int Binary_tree<T>::get_hight(Node<T>* p)
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
int Binary_tree<T>::hight()
{
    return get_hight(root);
}

template <class T>
void Binary_tree<T>::level_order_Display()
{
    queue<Node<T>*> arr;
    arr.push(root);
    while(!arr.empty())
    {
        Node<T>* temp = arr.front(); 
        cout << temp->data << " ";
        if(temp->Lchild != nullptr)
        {
            arr.push(temp->Lchild);
        }
        if(temp->Rchild != nullptr)
        {
            arr.push(temp->Rchild);
        }

        arr.pop();
    }
    cout << "\n";
}

// template <class T>
// void Binary_tree<T>::delete_tree(Node<T>* node) 
// {
//     if (node == nullptr) return;
//     delete_tree(node->Lchild);
//     delete_tree(node->Rchild);
//     delete node;
// }

template <class T>
Binary_tree<T>::~Binary_tree() 
{
    // delete_tree(root);
}

#endif