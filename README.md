# 🔄 Dynamic Undo/Redo System in C++

## 📌 Overview.   

A high-performance, object-oriented C++ implementation featuring a generic Doubly Linked List (`clsDblLinkedList`), a custom Stack (`clsMyStack`) data structure built on top of it, and a practical application: a String Class (`clsMyString`) with full Undo / Redo operational history support.

This project demonstrates how low-level memory management and template programming can be composed into clean, reusable high-level data abstractions.

## 🏗 Architecture & Design.          

The project follows a layered architectural design pattern:

    +-------------------------------------------------------+
    |                    clsMyString                        |
    |   (Manages Undo/Redo stack-driven string state)       |
    +---------------------------+---------------------------+
                                |
                                v
    +-------------------------------------------------------+
    |                    clsMyStack<T>                      |
    |       (LIFO Stack abstraction built on list)          |
    +---------------------------+---------------------------+
                                |
                                v
    +-------------------------------------------------------+
    |                 clsDblLinkedList<T>                   |
    |  (Doubly Linked List managing raw Node pointers)      |
    +-------------------------------------------------------+

1. `clsDblLinkedList<T>` forms the foundational storage tier, exposing raw node handling and link updating routines.

2. `clsMyStack<T>` encapsulates list methods to enforce strict LIFO semantics.

3. `clsMyString` utilizes two instance stacks to deliver robust state manipulation.


## ⌨ Core Operations

### 1. Doubly Linked List (`clsDblLinkedList<T>`)

A templated list container supporting bidirectional traversal and constant-time dynamic insertions/deletions at designated boundaries.

### 1. Element Access & Information
* `T Size()`: Returns the total number of nodes in the list in $O(1)$ time.
* `bool IsEmpty()`: Checks if the list contains any elements.
* `Node* Find(T Value)`: Searches for a specific value and returns a pointer to its node (or `nullptr` if not found).
* `Node* GetNode(unsigned int Order)`: Retrieves a node by its zero-based index.
* `T GetItem(unsigned int Order)`: Returns the value stored at a specific index.

### 2. Insertion Operations
* `void InsertAtBeginning(T value)`: Adds a new node at the head of the list.
* `void InsertAtEnd(T value)`: Appends a new node to the tail of the list.
* `void InsertAfter(Node* current, T value)`: Inserts a new node directly after a specified node pointer.
* `void InsertAfter(unsigned int Order, T value)`: Inserts a new node after a specified index order.

### 3. Deletion Operations
* `void DeleteFirstNode()`: Removes the head node and frees memory.
* `void DeleteLastNode()`: Removes the tail node and frees memory.
* `void DeleteNode(Node*& NodeToDelete)`: Safely unlinks and deletes an arbitrary node pointer.
* `void Clear()`: Deallocates the entire list, resetting it to an empty state.

### 4. Utilities & Manipulation
* `void PrintList()`: Traverses and prints all elements sequentially.
* `void Reverse()`: Reverses the entire doubly linked list in-place.
* `void UpdateItem(unsigned int Order, T Value)`: Updates the value of an item at a specific index.

---

### 2. Stack Implementation (`clsMyStack<T>`)

| Method | Complexity |	Description |
| :--- | :--- | :--- |
| `push(T Item)` | O(1) | Inserts a new element onto the top of the stack by prepending it to the underlying doubly linked list. |
| `pop()` | O(1) | Removes the top element from the stack by deleting the head node of the underlying list. |
| `Top()` | O(1) | Retrieves the element at the top of the stack without removing it. |
| `Size()` | O(1) | Returns the total number of elements currently stored in the stack. | 
| `IsEmpty()` | O(1) | Returns `true` if the stack contains no elements, otherwise `false`. |
| `Clear()` | O(N) | Deallocates all memory and resets the stack to an empty state. |
| `Reverse()` | O(N) | Reverses the internal sequence of elements in the stack in-place. |
| `Print()` | O(N) | Outputs all elements of the stack sequentially to the standard output. |

### 3. Undo/Redo String Manager (`clsMyString`)

  A state-tracking string wrapper class leveraging two internal stack instances (`_Undo` and `_Redo`).

  `SetValue(const string &Value)`: Sets a new string value and pushes it onto the `_Undo` stack.

  `GetValue()`: Returns the current active state from the top of the `_Undo` stack.

  `Undo()`: Rolls back to the previous string state by popping from `_Undo` and pushing onto `_Redo`.

  `Redo()`: Reinstates the previously undone string state by popping from `_Redo` and pushing onto `_Undo`.

## 🔑 Key Concepts Demonstrated

Template Metaprogramming: Generic class construction using C++ templates (`template <class T>`) for universal type support.

Dynamic Memory Management: Manual memory allocation (`new`) and pointer cleanup (`delete`) to prevent memory leaks.

Composition & Encapsulation: Building high-level primitives (`clsMyStack`, `clsMyString`) on top of underlying data structures (`clsDblLinkedList`).

In-Place Pointer Swapping: Bidirectional node pointer inversion algorithms used in linked list reversal.

Static Class Members: Static size tracking (`inline static long long _Size`) shared across list instances.

## 🛠 Technologies

Language: C++ (C++17 or higher recommended)

Standard Library: Standard IO Streams (`<iostream>`), Standard String (`<string>`)

Paradigm: Object-Oriented Programming (OOP) & Generic Programming

## 👨‍🏫 Instructor

Dr. Mohammed Abu-Hadhoud
Founder & Instructor — Programming Advices

Programming Advices
https://programmingadvices.com
