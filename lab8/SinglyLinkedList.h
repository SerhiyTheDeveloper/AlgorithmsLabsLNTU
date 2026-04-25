#pragma once
#include "Node.h"

template <typename T>
class SinglyLinkedList
{
private:
	Node<T>* head;

public:
	SinglyLinkedList() : head(nullptr) {}

	void addToBeginning(T value) {
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		head = newNode;
	}

	void addToEnd(T value) {
		Node<T>* newNode = new Node<T>(value);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node<T>* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}

	void remove(T value) {
		if (head == nullptr) return;
		if (head->data == value) {
			Node<T>* targetNode = head;
			head = head->next;
			delete targetNode;
			return;
		}
		Node<T>* current = head;
		while (current->next != nullptr && current->next->data != value) {
			current = current->next;
		}
		if (current->next != nullptr) {
			Node<T>* targetNode = current->next;
			current->next = current->next->next;
			delete targetNode;
		}
	}

	void removeFirst() {
		if (head == nullptr) return;
		Node<T>* targetNode = head;
		head = head->next;
		delete targetNode;
	}

	void removeLast() {
		if (head == nullptr) return;
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
			return;
		}
		Node<T>* current = head;
		while (current->next->next != nullptr) {
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
	}

	~SinglyLinkedList() {
		Node<T>* current = head;
		while (current != nullptr) {
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
	}
};
