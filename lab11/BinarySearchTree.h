#pragma once
template <typename T>
class BinarySearchTree
{
private:
	Node<T>* root;

	void clear(Node<T>* node) {
		if (node == nullptr) return;
		clear(node->left);
		clear(node->right);
		delete node;
	}

public:
	BinarySearchTree() : root(nullptr) {}

	void insert(const T& value) {
		if (root == nullptr) {
			root = new Node<T>(value);
			return;
		}

		Node<T>* baseNode = root;
		while (true) {
			if (value <= baseNode->data) {
				if (baseNode->left == nullptr) {
					baseNode->left = new Node<T>(value)
						return;
				}
				baseNode = baseNode->left;
			}
			else {
				if (baseNode->right == nullptr) {
					baseNode->right = new Node<T>(value)
						return;
				}
				baseNode = baseNode->right;
			}
		}
	}

	Node<T>* search(const T& value) const {
		Node<T>* targetNode = root;
		while (targetNode != nullptr && targetNode->data != value) {
			if (value < targetNode->data) {
				targetNode = targetNode->left;
			}
			else targetNode = targetNode->right;
		}
		return targetNode;
	}

	void remove(const T& value) {
		Node<T>* targetNodeParent = nullptr;
		Node<T>* targetNode = root;

		while (targetNode != nullptr && targetNode->data != value) {
			targetNodeParent = targetNode;
			targetNode = (value < targetNode->data) ? targetNode->left : targetNode->right;
		}

		if (targetNode == nullptr) return;

		if (targetNode->right != nullptr && targetNode->left != nullptr) {
			Node<T>* maxNodeParent = targetNode;
			Node<T>* maxNode = targetNode->left;
			while (maxNode->right != nullptr) {
				maxNodeParent = maxNode;
				maxNode = maxNode->right;
			}
			targetNode->data = maxNode->data;
			if (maxNodeParent->right == maxNode) {
				maxNodeParent->right = maxNode->left;
			}
			else {
				maxNodeParent->left = maxNode->left;
			}
			delete maxNode;
		}
		else {
			Node<T>* child = (targetNode->left != nullptr) ? targetNode->left : targetNode->right;

			if (targetNodeParent == nullptr) {
				root = child; 
			}
			else {
				if (targetNodeParent->left == targetNode) targetNodeParent->left = child;
				else targetNodeParent->right = child;
			}
			delete targetNode;
		}
	}

	~BinarySearchTree() {
		clear(root); 
		root = nullptr;
	}
};
