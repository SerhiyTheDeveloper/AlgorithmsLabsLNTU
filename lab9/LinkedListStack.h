#pragma once
#include "Node.h"
template <typename T>
class LinkedListStack
{
private:
	Node<T>* top;

public:
	LinkedListStack() : top(nullptr) {}

	void push(const T& value) {
		Node<T>* newNode = new Node<T>(value);
		newNode->next = top;
		top = newNode;
	}

	T pop() {
		if (top == nullptr) throw std::underflow_error("Stack is empty");
		T value = top->data;
		Node<T>* targetNode = top;
		top = top->next;
		delete targetNode;
		return value;
	}

	T peek() const {
		if (top == nullptr) throw std::out_of_range("Stack is empty");
		return top->data;
	}

	bool isEmpty() const {
		return top == nullptr;
	}

	~LinkedListStack() {
		Node<T>* current = top;
		while (current != nullptr) {
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
	}
};

