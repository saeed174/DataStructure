#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <iostream>
using namespace std;

template <class T>
class Node
{
    public :
        Node<T>* Lchild;
        Node<T>* Rchild;
        int height;
        T data;
};

template <class T>
class AVL_Tree
{
    private : 
        // Node<T>* root;
        Node<T>* insert(Node<T>* p , T element);
        void in_order(Node<T>* p);
        int get_height(Node<T>* p);
        int Node_height(Node<T>* p);
        int balance_factor(Node<T>* p);
        Node<T>* LLRotation(Node<T>* p);
        Node<T>* LRRotation(Node<T>* p);
        Node<T>* RRRotation(Node<T>* p);
        Node<T>* RLRotation(Node<T>* p);
        Node<T>* RDelete(Node<T>* p,T key);
        Node<T>* InPre(Node<T>* p);
        Node<T>* InSucc(Node<T>* p);
    public :
        Node<T>* root;
        AVL_Tree();
        void insert(T element);
        void Display();
        int height();
        bool search(T key);
        void Delete(T key);
        ~AVL_Tree();  
};

template <class T>
AVL_Tree<T>::AVL_Tree()
{
    root = nullptr;
}

template <class T>
int AVL_Tree<T>::get_height(Node<T>* p)
{
    int x = 0 ,y = 0;
    if(p == nullptr)
        return 0;
    
    x = get_height(p->Lchild);
    y = get_height(p->Rchild);

    if(x>y)
        return x+1;
    else
        return y+1;
}

template <class T>
int AVL_Tree<T>::height()
{
    return get_hight(root);
}

template <class T>
int AVL_Tree<T>::balance_factor(Node<T>* p)
{
    int hl,hr;
    hl = (p != nullptr && p->Lchild != nullptr)? p->Lchild->height:0;
    hr = (p != nullptr && p->Rchild != nullptr)? p->Rchild->height:0;

    return (hl - hr);
}

template <class T>
int AVL_Tree<T>::Node_height(Node<T>* p)
{
    int hl,hr;
    hl = (p != nullptr && p->Lchild != nullptr)? p->Lchild->height:0;
    hr = (p != nullptr && p->Rchild != nullptr)? p->Rchild->height:0;

    return (hl > hr)? hl+1 : hr+1;

}

template <class T>
Node<T>* AVL_Tree<T>::LLRotation(Node<T>* p)
{
    Node<T>* pl = p->Lchild;
    Node<T>* plr = pl->Rchild;
    
    pl->Rchild = p;
    p->Lchild = plr;
    p->height = Node_height(p);
    pl->height = Node_height(pl);

    if(root == p)
        root = pl;

    return pl;
}

template <class T>
Node<T>* AVL_Tree<T>::LRRotation(Node<T>* p)
{
    Node<T>* pl = p->Lchild;
    Node<T>* plr = pl->Rchild;

    p->Lchild = plr->Lchild;
    pl->Rchild = plr->Rchild;
    plr->Rchild = p;
    plr->Lchild = pl;

    p->height = Node_height(p);
    plr->height = Node_height(plr);
    pl->height = Node_height(pl);

    if(root == p)
        root = plr;
    return plr;
}

template <class T>
Node<T>* AVL_Tree<T>::RRRotation(Node<T>* p)
{
    Node<T>* pr = p->Rchild;
    Node<T>* prl = pr->Lchild;

    pr->Lchild = p;
    p->Rchild = prl;
    p->height = Node_height(p);
    pr->height = Node_height(pr);

    if(root == p)
        root = pr;
    
    return pr;
    
}

template <class T>
Node<T>* AVL_Tree<T>::RLRotation(Node<T>* p)
{
    Node<T>* pr = p->Rchild;
    Node<T>* prl = pr->Lchild;

    p->Rchild = prl->Rchild;
    pr->Lchild = prl->Lchild;
    prl->Lchild = p;
    prl->Rchild = pr;

    p->height = Node_height(p);
    prl->height = Node_height(prl);
    pr->height = Node_height(pr);

    if(root == p)
        root = prl;
    
    return prl;
}


template <class T>
Node<T>* AVL_Tree<T>::insert(Node<T>* p , T element)
{
    if(p == nullptr)
    {
        Node<T>* add = new Node<T>;
        add->data = element;
        add->height = 1;
        add->Lchild = add->Rchild = nullptr;
        return add;
    }
    if(element < p->data)
    {
        p->Lchild = insert(p->Lchild,element);
    }
    else if(element > p->data)
    {
        p->Rchild = insert(p->Rchild,element);
    }
    p->height = Node_height(p);

    if(balance_factor(p) == 2 && balance_factor(p->Lchild) == 1)
        return LLRotation(p);
    else if(balance_factor(p) == 2 && balance_factor(p->Lchild) == -1)
        return LRRotation(p);
    else if(balance_factor(p) == -2 && balance_factor(p->Rchild) == -1)
        return RRRotation(p);
    else if(balance_factor(p) == -2 && balance_factor(p->Rchild) == 1)
        return RLRotation(p);

    return p;
}

template <class T>
void AVL_Tree<T>::insert(T element)
{
    root = insert(root,element);
}

template <class T>
void AVL_Tree<T>::in_order(Node<T>* p)
{
    if(p != nullptr)
    {
        in_order(p->Lchild);
        cout << p->data << " ";
        in_order(p->Rchild);
    }
}

template <class T>
void AVL_Tree<T>::Display()
{
    in_order(root);
    cout << "\n";
}

template <class T>
bool AVL_Tree<T>::search(T key)
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
Node<T>* AVL_Tree<T>::InPre(Node<T>* p)
{
    while(p != nullptr && p->Rchild != nullptr)
        p = p->Rchild;

        return p;
}

template <class T>
Node<T>* AVL_Tree<T>::InSucc(Node<T>* p)
{
    while(p != nullptr && p->Lchild != nullptr)
        p = p->Lchild;

        return p;
}

template <class T>
void AVL_Tree<T>::Delete(T key)
{
    RDelete(root,key);
}


template <class T>
Node<T>*  AVL_Tree<T>::RDelete(Node<T>* p,T key)
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
        if(get_height(p->Lchild) > get_height(p->Rchild))
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

    if(balance_factor(p) == 2 && (balance_factor(p->Lchild) == 1 || balance_factor(p->Lchild) == 0))
        return LLRotation(p);
    else if(balance_factor(p) == 2 && balance_factor(p->Lchild) == -1)
        return LRRotation(p);
    else if(balance_factor(p) == -2 && (balance_factor(p->Rchild) == -1 || balance_factor(p->Rchild) == 0))
        return RRRotation(p);
    else if(balance_factor(p) == -2 && balance_factor(p->Rchild) == 1)
        return RLRotation(p);
    
    return p;
}

template <class T>
AVL_Tree<T>::~AVL_Tree()
{
    delete root;
}
#endif