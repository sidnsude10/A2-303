#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Declaration of the Single_Linked_List class
template<typename Item_Type>
class Single_Linked_List {
public:
    Single_Linked_List();
    ~Single_Linked_List();
    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type& front();
    Item_Type& back();
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;
    size_t size() const;

private:
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& item, Node* next_node) : data(item), next(next_node) {}
    };
    Node* head;
    Node* tail;
    size_t num_items;
};

// Declaration of the Stack class
class Stack {
public:
    void push(int value);
    void pop();
    int top() const;
    bool is_empty() const;
    double average() const;

private:
    vector<int> elements;
};

#endif