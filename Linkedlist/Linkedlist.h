#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <class T>
class Node
{
public :
    T  data;
    Node* next;
    Node()
    {
        next = nullptr;
    }
};

template <class T>
class Linkedlist
{
private :
    Node<T>* head;
    Node<T>* end;
    int length;
public :
    Linkedlist();
    bool is_empty();
    void push_front(T element);
    void push_back(T element);
    void Display();
    void reverse_Display();
    int  size();
    T    sum();
    T    max();
    T    min();
    bool search(T key);
    void insert_before(T element , T key);
    void insert_after(T element , T key);
    void insert_at(int index , T key);
    void sort();
    void insert_in_sorted(T key);
    void Delete(T key);
    void Delete_at(int index);
    bool is_sorted();
    void reverse();
    void merge(Linkedlist &l1);
    ~Linkedlist();
};

template <class T>
Linkedlist<T>::Linkedlist()
{
    head = nullptr;
    end  = nullptr;
    length = 0;
}

template <class T>
bool Linkedlist<T>::is_empty()
{
    if(head == nullptr)
        return true;
    else
        return false;
}

template <class T>
void Linkedlist<T>::push_front(T element)
{
    Node<T>* temp = new Node<T>;
    temp.data = element;
    if(head == nullptr)
    {
        head = temp;
        end  = temp;
        temp.next = nullptr;
    }
    else
    {
        temp.next = head;
        head = temp;
    }
    length++;
}

template <class T>
void Linkedlist<T>::push_back(T element)
{
    Node<T>* temp = new Node<T>;
    temp->data = element;
    if(head == nullptr)
    {
        head = temp;
        end  = temp;
        temp->next = nullptr;
    }
    else
    {
        end->next = temp;
        end = temp;
        temp->next = nullptr;
    }
    length++;
}

template <class T>
void Linkedlist<T>::Display()
{
    Node<T>* trans = head; 
    while (trans != nullptr)
    {
        cout << trans->data << " ";
        trans = trans->next;
    }
    cout << "\n";
}

template <class T>
void Linkedlist<T>::reverse_Display()
{
    static Node<T>* rev_trans = head;
    if(rev_trans != end->next)
    {
        T data = rev_trans->data;
        rev_trans = rev_trans->next;
        reverse_Display();
        cout << data << " ";
    }
    else
    {
        return;
    }
}
template <class T>
T  Linkedlist<T>::sum()
{
    T result = head->data;
    Node<T>* temp = head->next;
    while(temp != nullptr)
    {
        result += temp->data;
        temp = temp->next;
    }
    return result;
}

template <class T>
T  Linkedlist<T>::max()
{
    T mx = head->data;
    Node<T>* temp = head->next;
    while(temp != nullptr)
    {
        if(temp->data > mx)
            mx = temp->data;
        temp = temp->next;
    }
    return mx;
}

template <class T>
T  Linkedlist<T>::min()
{
    T mn = head->data;
    Node<T>* temp = head->next;
    while(temp != nullptr)
    {
        if(temp->data < mn)
            mn = temp->data;
        temp = temp->next;
    }
    return mn;
}

template <class T>
bool Linkedlist<T>::search(T key)
{
    if(head == nullptr)
        return false;
    bool srch = 0;
    Node<T>* trav = head;
    while(trav != nullptr)
    {
        if(trav->data == key)
        {
            srch = true;
            break;
        }
        trav = trav->next;
    }
    return srch;
}

template <class T>
int Linkedlist<T>::size()
{
    return length;
}

template <class T>
void Linkedlist<T>::insert_before(T element , T key)
{
    if(!search(element))
    {
        cout << "This element is not exist\n";
        return;
    }
    Node<T>* add = new Node<T>;
    add->data = key;
    Node<T>* temp = head;
    if(head->data == element)
    {
        add->next = head;
        head = add;
        length++;
        return;
    }
    while(temp->next != nullptr && temp->next->data != element)
    {
        temp = temp->next;
    }

    add->next = temp->next;
    temp->next = add;
    length++;
}

template <class T>
void Linkedlist<T>::insert_after(T element , T key)
{
    if(!search(element))
    {
        cout << "This element is not exist\n";
        return;
    }
    else if(element == end->data)
    {
        Node<T>* add = new Node<T>;
        add->data = key;

        end->next = add;
        end = add;
        add->next = nullptr;
        length++;
        return;
    }
    Node<T>* add = new Node<T>;
    add->data = key;
    Node<T>* temp = head;
    while(temp->data != element)
    {
        temp = temp->next;
    }

    add->next = temp->next;
    temp->next = add;
    length++;
}

template <class T>
void Linkedlist<T>::insert_at(int index , T key)
{
    if(index > length)
    {
        cout << "This is large index\n";
        return;
    }

    Node<T>* add = new Node<T>;
    add->data = key;
    
    if(index == 0)
    {
        add->next = head;
        head = add;
        length++;
        return;
    }
    if(index == length)
    {
        end->next = add;
        end = add;
        add->next = nullptr;
        length++;
        return;
    }

    Node<T>* temp = head;
    for(int i = 0 ; i < index-1 ; i++)
    {
        temp = temp->next;
    }
    add->next = temp->next;
    temp->next = add;
    length++;
}

template <class T>
void Linkedlist<T>::sort()
{
    if(head == nullptr || head->next == nullptr)
    {
        return;
    }
    Node<T>* temp = head->next;
    Node<T>* before = head;
    while(temp != nullptr)
    {
        if(temp->data < head->data)
        {
            Node<T>* trns = new Node<T>;
            trns->data = temp->data;
            trns->next = head;
            head = trns;
            if(temp == end)
            {
                end = before;
            }
            before->next = temp->next;
            delete temp;
            temp = before->next;
            
        }
        else
        {
            temp = temp->next;
            before = before->next;
        }
    }
}

template <class T>
void Linkedlist<T>::insert_in_sorted(T key)
{
    if(key < head->data)
    {
        Node<T>* temp = new Node<T>;
        temp->data = key;
        temp->next = head;
        head = temp;
        length++;
        return;
    }
    else if(key >= end->data)
    {
        Node<T>* temp = new Node<T>;
        temp->data = key;

        end->next = temp;
        end = temp;
        temp->next = nullptr;
        length++;
        return;
    }

    Node<T>* temp = head;
    while(temp->next != nullptr)
    {
        if(temp->next->data > key)
        {
            Node<T>* add = new Node<T>;
            add->data = key;

            add->next = temp->next;
            temp->next = add;
            length++;
            return;
        }
        temp = temp->next;
    }
}

template <class T>
void Linkedlist<T>::Delete(T key)
{
    if (length == 0 || head == nullptr) 
        return;
    Node<T>* temp = head;
    if(head-> data == key)
    {
        head = head->next;
        delete temp;
        length--;
        return;
    }
    temp = head->next;
    Node<T>* before = head;
    
    while (temp != nullptr)
    {
        if(temp->data == key)
        {
            before->next = temp->next;
            if(temp == end)
            {
                end = before;
            }
            delete temp;
            length--;
            return;
        }
        temp = temp->next;
        before = before->next;
    }
}

template <class T>
void Linkedlist<T>::Delete_at(int index)
{
    if (length == 0 || head == nullptr) 
        return;
    Node<T>* temp = head;
    if(index == 0)
    {
        head = head->next;
        delete temp;
        length--;
        return;
    }

    Node<T>* before = head;
    for(int i = 0 ; i < index ; i++)
    {
        if(i < index-1)
            before = before->next;
        temp = temp->next;
    }
    before->next = temp->next;
    if(index == length-1)
    {
        end = before;
    }
    length--;
    delete temp;
}

template <class T>
bool Linkedlist<T>::is_sorted()
{
    Node<T>* temp = head;

    while(temp->next != nullptr)
    {
        if(temp->data > temp->next->data)
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

template <class T>
void Linkedlist<T>::reverse()
{
    if (length == 0 || head == nullptr) 
        return;
    
    Node<T>* temp = head;
    T *store = new T[length];
    for(int i = 0 ; i < length ; i++)
    {
        store[i] = temp->data;
        temp = temp->next;
    }

    temp = head;
    for (int i = length-1 ; i >= 0; i--)
    {
        temp->data = store[i];
        temp = temp->next;
    }
    delete[] store;
}

template <class T>
void Linkedlist<T>::merge(Linkedlist &l1)
{
    if (l1.head == nullptr) {
        return;  // l1 is empty, nothing to do
    }

    if (this == &l1) {
        return;  // Avoid self-merge
    }
    end->next = l1.head;
    end = l1.end;
    end->next = nullptr;
    length += l1.length;
}


template <class T>
Linkedlist<T>::~Linkedlist()
{
}

#endif