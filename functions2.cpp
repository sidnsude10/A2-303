#include "functions.h"

// Constructor
template<typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor
template<typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
		while (!empty()) {
				pop_front();
		}
}

// Push front
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
		head = new Node(item, head);
		if (tail == nullptr) {
				tail = head;
		}
		++num_items;
}

// Push back
template<typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
		Node* new_node = new Node(item, nullptr);
		if (tail != nullptr) {
				tail->next = new_node;
		}
		tail = new_node;
		if (head == nullptr) {
				head = tail;
		}
		++num_items;
}

// Pop front
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
		if (empty()) {
				throw std::runtime_error("pop_front on empty list");
		}
		Node* old_head = head;
		head = head->next;
		delete old_head;
		if (head == nullptr) {
				tail = nullptr;
		}
		--num_items;
}

// Pop back
template<typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
		if (empty()) {
				throw std::runtime_error("pop_back on empty list");
		}
		if (head == tail) {
				delete head;
				head = tail = nullptr;
		} else {
				Node* temp = head;
				while (temp->next != tail) {
						temp = temp->next;
				}
				delete tail;
				tail = temp;
				tail->next = nullptr;
		}
		--num_items;
}

// Front
template<typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::front() {
		if (empty()) {
				throw std::runtime_error("front on empty list");
		}
		return head->data;
}

// Back
template<typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::back() {
		if (empty()) {
				throw std::runtime_error("back on empty list");
		}
		return tail->data;
}

// Empty
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
		return head == nullptr;
}

// Insert
template<typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
		if (index > num_items) {
				throw std::out_of_range("index out of range");
		}
		if (index == 0) {
				push_front(item);
		} else if (index == num_items) {
				push_back(item);
		} else {
				Node* temp = head;
				for (size_t i = 1; i < index; ++i) {
						temp = temp->next;
				}
				temp->next = new Node(item, temp->next);
				++num_items;
		}
}

// Remove
template<typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
		if (index >= num_items) {
				return false;
		}
		if (index == 0) {
				pop_front();
		} else {
				Node* temp = head;
				for (size_t i = 1; i < index; ++i) {
						temp = temp->next;
				}
				Node* to_delete = temp->next;
				temp->next = to_delete->next;
				if (to_delete == tail) {
						tail = temp;
				}
				delete to_delete;
				--num_items;
		}
		return true;
}

// Find
template<typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
		Node* temp = head;
		size_t index = 0;
		while (temp != nullptr) {
				if (temp->data == item) {
						return index;
				}
				temp = temp->next;
				++index;
		}
		return num_items; // Item not found
}

// Size
template<typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
		return num_items;
}

// Explicit instantiation of the template for int
template class Single_Linked_List<int>;

// Stack class implementations
void Stack::push(int value) {
		elements.push_back(value);
}

void Stack::pop() {
		if (is_empty()) {
				throw runtime_error("pop from empty stack");
		}
		elements.pop_back();
}

int Stack::top() const {
		if (is_empty()) {
				throw runtime_error("top from empty stack");
		}
		return elements.back();
}

bool Stack::is_empty() const {
		return elements.empty();
}

double Stack::average() const {
		if (is_empty()) {
				throw runtime_error("average of empty stack");
		}
		double sum = 0;
		for (int value : elements) {
				sum += value;
		}
		return sum / elements.size();
}