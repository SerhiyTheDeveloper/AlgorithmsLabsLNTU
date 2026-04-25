#pragma once
#include "DoublyNode.h"

template <typename T>
class DoublyLinkedList
{
private:
	DoublyNode<T>* head;
	DoublyNode<T>* tail;

public:
	DoublyLinkedList() : head(nullptr), tail(nullptr) {}

	void addToBeginning(T value) {
		DoublyNode<T>* newNode = new DoublyNode<T>(value);
		if (head == nullptr) {
			head = tail = newNode;
			return;
		}
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	void addToEnd(T value) {
		DoublyNode<T>* newNode = new DoublyNode<T>(value);
		if (tail == nullptr) {
			head = tail = newNode;
			return;
		}
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

	void remove(T value) {
		DoublyNode<T>* current = head;
		while (current != nullptr && current->data != value) {
			current = current->next;
		}
		if (current == nullptr) return;
		if (current->prev != nullptr) {
			current->prev->next = current->next;
		}
		else {
			head = current->next;
		}
		if (current->next != nullptr) {
			current->next->prev = current->prev;
		}
		else {
			tail = current->prev;
		}
		delete current;
	}

	void removeFirst() {
		if (head == nullptr) return;
		DoublyNode<T>* targetNode = head;
		head = head->next;
		if (head != nullptr) head->prev = nullptr;
		else tail = nullptr;
		delete targetNode;
	}

	void removeLast() {
		if (tail == nullptr) return;
		DoublyNode<T>* targetNode = tail;
		tail = tail->prev;
		if (tail != nullptr) tail->next = nullptr;
		else head = nullptr;
		delete targetNode;
	}

	~DoublyLinkedList() {
		DoublyNode<T>* current = head;
		while (current != nullptr) {
			DoublyNode<T>* next = current->next;
			delete current;
			current = next;
		}
	}
};
