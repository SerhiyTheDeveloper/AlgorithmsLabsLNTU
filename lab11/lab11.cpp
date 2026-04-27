#include <iostream>
#include "Node.h"
#include "BinarySearchTree.h"
#include <chrono>
#include <functional>

using namespace std;
using namespace chrono;

static void measureTime(const string& title, function<void()> func) {
	auto start = high_resolution_clock::now();
	func();
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<nanoseconds>(stop - start);
	cout << title << ": " << duration.count() << " nanoseconds" << endl;
}

template <typename T>
static void preorderConsole(Node<T>* node) {
    if (node == nullptr) return;
	cout << node->data << " ";
	preorderConsole(node->left);
	preorderConsole(node->right);
}

template <typename T>
static void inorderConsole(Node<T>* node) {
	if (node == nullptr) return;
	inorderConsole(node->left);
	cout << node->data << " ";
	inorderConsole(node->right);
}

template <typename T>
static void postorderConsole(Node<T>* node) {
	if (node == nullptr) return;
	postorderConsole(node->left);
	postorderConsole(node->right);
	cout << node->data << " ";
}

static void preorder(Node<int>* node) {
	long long sum = 0;
	if (node == nullptr) return;
	sum += node->data;
	preorder(node->left);
	preorder(node->right);
}

static void inorder(Node<int>* node) {
	long long sum = 0;
	if (node == nullptr) return;
	inorder(node->left);
	sum += node->data;
	inorder(node->right);
}

static void postorder(Node<int>* node) {
	long long sum = 0;
	if (node == nullptr) return;
	postorder(node->left);
	postorder(node->right);
	sum += node->data;
}

int main()
{
	srand(time(0));

	BinarySearchTree<int> smallTree;
	BinarySearchTree<int> bigTree;

	// Заміри для малого дерева (10 елементів)
	cout << "----- Small tree (10 elements) -----" << endl;

	measureTime("Insert 10 elements", [&]() {
		for (int i = 0; i < 9; i++) {
			smallTree.insert(rand() % 100);
		}
		smallTree.insert(50);
	});

	cout << endl;
	measureTime("- Preorder in Console", [&]() {
		preorderConsole(smallTree.getRoot());
	});
	measureTime("- Inorder in Console", [&]() {
		inorderConsole(smallTree.getRoot());
	});
	measureTime("- Postorder in Console", [&]() {
		postorderConsole(smallTree.getRoot());
	});
	measureTime("Preorder Traversal", [&]() {
		preorder(smallTree.getRoot());
	});
	measureTime("Inorder Traversal", [&]() {
		inorder(smallTree.getRoot());
	});
	measureTime("Postorder Traversal", [&]() {
		postorder(smallTree.getRoot());
	});
	cout << endl;

	measureTime("Search for 50", [&]() {
		smallTree.search(50);
	});
	measureTime("Remove 50", [&]() {
		smallTree.remove(50);
	});

	// Заміри для великого дерева (10000 елементів)
	cout << endl << "----- Big tree (10000 elements) -----" << endl;

	measureTime("Insert 10000 elements", [&]() {
		for (int i = 0; i < 9999; i++) {
			bigTree.insert(rand() % 10000);
		}
		bigTree.insert(5001);
	});

	cout << endl;
	measureTime("Preorder Traversal", [&]() {
		preorder(bigTree.getRoot());
	});
	measureTime("Inorder Traversal", [&]() {
		inorder(bigTree.getRoot());
	});
	measureTime("Postorder Traversal", [&]() {
		postorder(bigTree.getRoot());
	});
	cout << endl;

	measureTime("Search for 5001", [&]() {
		bigTree.search(5001);
	});
	measureTime("Remove 5001", [&]() {
		bigTree.remove(5001);
	});

	return 0;
}
