# 🧮 Data Structures and Algorithms in C++

A complete, modular, and educational implementation of **core data structures** and **sorting algorithms** using **C++17**, written from scratch for learning, performance analysis, and algorithmic understanding.

This repository provides fully functional and optimized implementations with clear method definitions, object-oriented design, and thorough documentation.

---

## 📂 Project Overview

This project contains implementations of:
- **Linear Data Structures:** Array, Linked List, Stack, Queue  
- **Non-Linear Data Structures:** Binary Search Tree, AVL Tree, Heap  
- **Sorting Algorithms:** From O(n²) simple sorts to O(n log n) advanced sorts  

Each structure includes:
- Constructor & Destructor  
- Insertion, Deletion, and Searching operations  
- Utility functions (traversal, reverse, merge, sorting, etc.)  
- Clean, readable, and commented C++17 code  

---

## 🧩 Implemented Data Structures

---

### 🧱 1. Array Class (`Array<T>`)

**Header:** `Array.h`  
**Purpose:** Dynamic array implementation supporting insertions, deletions, and sorting.

#### 🔧 Methods
| Method | Description |
|--------|-------------|
| `Array()` | Default constructor |
| `Array(int siz)` | Create array of specific size |
| `~Array()` | Destructor |
| `void Display()` | Display array elements |
| `bool Is_empty()` | Check if array is empty |
| `void Fill(int len)` | Fill array with user input |
| `void Append(T data)` | Add element to end |
| `void Insert(int index, T data)` | Insert element at position |
| `void Delete(int index)` | Delete element at position |
| `bool Search(T data)` | Search element linearly |
| `int  Get_length()` | Current length of array |
| `int  Get_size()` | Capacity of array |
| `int  Get_index(T data)` | Find index of element |
| `T    Get(int index)` | Get value at index |
| `void Set(int index, T data)` | Set value at index |
| `T Max(), T Min()` | Get maximum / minimum element |
| `T Sum(), T Average()` | Sum or average of elements |
| `void Reverse()` | Reverse array |
| `void Sort()` | Sort using chosen algorithm |
| `void Swap(int i1, int i2)` | Swap two elements |
| `bool Binary_search(T key)` | Binary search (sorted arrays) |
| `int Binary_search_index(T key)` | Return index if found |
| `void Left_shift(), Right_shift()` | Shift array elements |
| `void Insert_in_sorted(T data)` | Insert while maintaining sort order |
| `void Resize(int new_size)` | Change array size dynamically |
| `bool Is_sorted()` | Check if sorted |
| `void Merge(Array a, Array b)` | Merge two arrays |
| `void Union(Array a, Array b)` | Union of two arrays |
| `Array<T>& operator=(const Array<T>& other)` | Assignment operator overload |

---

### 🔗 2. Linked List (`Linkedlist<T>`)

**Header:** `Linkedlist.h`  
**Purpose:** Generic singly linked list with advanced operations.

#### 🔧 Methods
| Method | Description |
|--------|-------------|
| `Linkedlist()` | Constructor |
| `bool is_empty()` | Check if list is empty |
| `void push_front(T element)` | Insert at front |
| `void push_back(T element)` | Insert at end |
| `void Display()` | Display list in normal order |
| `void reverse_Display()` | Display list in reverse |
| `int size()` | Get list length |
| `T sum()` | Sum of all elements |
| `T max(), T min()` | Get maximum / minimum node value |
| `bool search(T key)` | Search for an element |
| `void insert_before(T element, T key)` | Insert before a specific key |
| `void insert_after(T element, T key)` | Insert after a specific key |
| `void insert_at(int index, T key)` | Insert at index |
| `void sort()` | Sort list |
| `void insert_in_sorted(T key)` | Insert maintaining sorted order |
| `void Delete(T key)` | Delete by key |
| `void Delete_at(int index)` | Delete at index |
| `bool is_sorted()` | Check if list is sorted |
| `void reverse()` | Reverse list order |
| `void merge(Linkedlist &l1)` | Merge two linked lists |
| `~Linkedlist()` | Destructor |

---

### 🧮 3. Stack (`Stack<T>`)

**Header:** `Stack.h`  
**Purpose:** LIFO stack implementation using array or linked list.

#### 🔧 Methods
| Method | Description |
|--------|-------------|
| `Stack()` | Constructor |
| `void push(T key)` | Push element on top |
| `T Top()` | Peek at top element |
| `void pop()` | Pop element from top |
| `bool empty()` | Check if empty |
| `bool full()` | Check if full |
| `T peek(int pos)` | Peek element at position |
| `int size()` | Number of elements |
| `~Stack()` | Destructor |

---

### 🔁 4. Queue (`Queue<T>`)

**Header:** `Queue.h`  
**Purpose:** FIFO queue implementation.

#### 🔧 Methods
| Method | Description |
|--------|-------------|
| `Queue()` | Constructor |
| `void push(T element)` | Enqueue element |
| `T Top()` | Get front element |
| `void pop()` | Dequeue element |
| `bool empty()` | Check if empty |
| `bool full()` | Check if full |
| `~Queue()` | Destructor |

---

### 🌳 5. Binary Search Tree (`Binary_Search_Tree<T>`)

**Header:** `BST.h`  
**Purpose:** Classic BST supporting insertion, deletion, and traversal.

#### 🔧 Methods
| Method | Description |
|--------|-------------|
| `Binary_Search_Tree()` | Default constructor |
| `Binary_Search_Tree(int sz)` | Construct with predefined size |
| `Binary_Search_Tree(T arr[], int sz)` | Construct from array |
| `Binary_Search_Tree(vector<T> arr)` | Construct from vector |
| `Binary_Search_Tree(deque<T> arr)` | Construct from deque |
| `void insert(T element)` | Insert node |
| `bool search(T key)` | Search for a value |
| `void Display()` | In-order display |
| `void Delete(T key)` | Delete node |
| `int hight()` | Tree height |
| `void pre_create(T arr[], int sz)` | Create tree from preorder traversal |
| `~Binary_Search_Tree()` | Destructor |

---

### 🌲 6. AVL Tree (`AVL_Tree<T>`)

**Header:** `AVL_Tree.h`  
**Purpose:** Self-balancing binary search tree ensuring O(log n) operations.

#### 🔧 Methods
| Method | Description |
|--------|-------------|
| `AVL_Tree()` | Constructor |
| `void insert(T element)` | Insert node and rebalance |
| `void Display()` | In-order traversal |
| `int height()` | Height of tree |
| `bool search(T key)` | Search for element |
| `void Delete(T key)` | Delete node and rebalance |
| `~AVL_Tree()` | Destructor |

---

### ⚙️ 7. Heap (`Heap<T>`)

**Header:** `Heap.h`  
**Purpose:** Binary max-heap implementation.

#### 🔧 Methods
| Method | Description |
|--------|-------------|
| `Heap()` | Constructor |
| `Heap(int sz)` | Constructor with capacity |
| `void set_size(int sz)` | Resize heap |
| `void insert(T data)` | Insert new element |
| `void Display()` | Print heap elements |
| `bool Search(T key)` | Search for element |
| `void Delete()` | Delete root (max element) |
| `void another_Delete()` | Alternative delete method |
| `~Heap()` | Destructor |

---

## 🔢 Sorting Algorithms

| Algorithm | Time Complexity | Description |
|------------|----------------|--------------|
| **Bubble Sort** | O(n²) | Repeatedly swaps adjacent elements |
| **Insertion Sort** | O(n²) | Builds sorted array one item at a time |
| **Selection Sort** | O(n²) | Selects smallest and places it in order |
| **Heap Sort** | O(n log n) | Uses heap property to sort efficiently |
| **Merge Sort** | O(n log n) | Divide and conquer sorting |
| **Quick Sort** | O(n log n) average | Partition-based divide and conquer |
| **Tree Sort** | O(n log n) | Inserts elements into BST and traverses |
| **Shell Sort** | O(n^1.5) | Improved insertion using gap sequences |
| **Count Sort** | O(n + k) | Non-comparison, integer-based sort |
| **Radix Sort** | O(n·k) | Sorts integers by digit position |

---

## 🧠 Learning Outcomes

By exploring this repository, you will:
- Understand **internal mechanics** of all fundamental data structures  
- Analyze **time and space complexities**  
- Learn **memory management and pointer-based structures**  
- Build a foundation for **competitive programming and technical interviews**

---

## 🧪 Compilation & Execution

### Clone the repository
```bash
git clone https://github.com/<your-username>/Data-Structures.git
cd Data-Structures
