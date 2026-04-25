#pragma once
#include "Node.h"
template <typename T>
class LinkedListQueue
{
private:
	Node<T>* head;
	Node<T>* tail;
	int count;

public:
	LinkedListQueue() : head(nullptr), tail(nullptr), count(0) {}

	void enqueue(const T& value) {
		Node<T>* newNode = new Node<T>(value);
		if (isEmpty()) {
			head = tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
		count++;
	}

	T dequeue() {
		if (isEmpty()) throw std::underflow_error("Queue is empty");
		Node<T>* targetNode = head;
		T value = head->data;
		head = head->next;
		delete targetNode;
		count--;
		if (isEmpty()) tail = nullptr;
		return value;
	}

	T peek() const {
		if (isEmpty()) throw std::out_of_range("Queue is empty");
		return head->data;
	}

	bool isEmpty() const {
		return count == 0;
	}

	int size() const {
		return count;
	}
	
	~LinkedListQueue() {
		Node<T>* current = head;
		while (current != nullptr) {
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
	}
};
