#pragma once
template <typename T>
class Node
{
public:
    T data;
    Node* left;
    Node* right;
    Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
};
