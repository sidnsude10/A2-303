#include "functions.h"

int main() {
    using namespace std;

    // Part 1: Single Linked List
    Single_Linked_List<int> list;
    list.push_front(10);
    list.push_back(20);
    list.push_front(5);

    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;

    while (!list.empty()) {
        cout << "Removing: " << list.front() << endl;
        list.pop_front();
    }

    // Part 2: Stack Implementation
    Stack stack;

    // Check if the stack is empty
    cout << "Is stack empty? " << (stack.is_empty() ? "Yes" : "No") << endl;

    // Insert values onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top of stack: " << stack.top() << endl;

    // Average value of stack elements
    cout << "Average of stack: " << stack.average() << endl;

    // Remove an element from the stack
    stack.pop();
    cout << "Top after pop: " << stack.top() << endl;

    return 0;
}
