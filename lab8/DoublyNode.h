#pragma once
template <typename T>
class DoublyNode
{
public:
	T data;
	DoublyNode* next;
	DoublyNode* prev;
	DoublyNode(T val) : data(val), next(nullptr), prev(nullptr) {}
};

