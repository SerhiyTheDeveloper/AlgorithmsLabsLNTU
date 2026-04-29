#include <iostream>
#include <chrono>
#include <functional>
#include "AdjacencyMatrix.h"
#include "AdjacencyList.h"

using namespace std;
using namespace chrono;

static void measureTime(const string& title, function<void()> func) {
	auto start = high_resolution_clock::now();
	func();
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	cout << title << ": " << duration.count() << " microseconds" << endl;
}

static void runTest(int numVertices, int numEdges, string label) {
	cout << "\n--- Testing " << label << " Graph (Vertices: " << numVertices << ", Edges: " << numEdges << ") ---\n";

	AdjacencyMatrix mat(numVertices);
	AdjacencyList lst(numVertices);

	measureTime("Matrix - Add Edges", [&]() {
		int count = 0;
		for (int i = 0; i < numVertices && count < numEdges; i++) {
			for (int j = i + 1; j < numVertices && count < numEdges; j++) {
				mat.addEdge(i, j);
				count++;
			}
		}
	});
	measureTime("List - Add Edges  ", [&]() {
		int count = 0;
		for (int i = 0; i < numVertices && count < numEdges; i++) {
			for (int j = i + 1; j < numVertices && count < numEdges; j++) {
				lst.addEdge(i, j);
				count++;
			}
		}
	});

	measureTime("Matrix - Has Edge", [&]() {
		for (int i = 0; i < numVertices; i++) {
			for (int j = 0; j < numVertices; j++) {
				mat.hasEdge(i, j);
			}
		}
	});
	measureTime("List - Has Edge  ", [&]() {
		for (int i = 0; i < numVertices; i++) {
			for (int j = 0; j < numVertices; j++) {
				lst.hasEdge(i, j);
			}
		}
	});

	measureTime("Matrix - Remove Edges", [&]() {
		int count = 0;
		for (int i = 0; i < numVertices && count < numEdges; i++) {
			for (int j = i + 1; j < numVertices && count < numEdges; j++) {
				mat.removeEdge(i, j);
				count++;
			}
		}
	});
	measureTime("List - Remove Edges  ", [&]() {
		int count = 0;
		for (int i = 0; i < numVertices && count < numEdges; i++) {
			for (int j = i + 1; j < numVertices && count < numEdges; j++) {
				lst.removeEdge(i, j);
				count++;
			}
		}
	});

	measureTime("Matrix - Get Neighbors", [&]() {
		for (int i = 0; i < numVertices; i++) {
			mat.getNeighbors(i);
		}
	});
	measureTime("List - Get Neighbors  ", [&]() {
		for (int i = 0; i < numVertices; i++) {
			lst.getNeighbors(i);
		}
	});
}

int main()
{
    // Перевірка коректності роботи
	AdjacencyMatrix matrix(5);
	matrix.addEdge(0, 1);
	matrix.addEdge(0, 2);
	matrix.addEdge(1, 3);
	matrix.addEdge(3, 4);

	AdjacencyList list(5);
	list.addEdge(0, 1);
	list.addEdge(0, 2);
	list.addEdge(1, 3);
	list.addEdge(3, 4);

	cout << "Initial Matrix:" << endl;
	matrix.print();
	cout << endl << "Initial List:" << endl;
	list.print();

	cout << "\nRemoving edge 0-2...\n" << endl;
	matrix.removeEdge(0, 2);
	list.removeEdge(0, 2);

	cout << "Matrix has edge 0-1: " << 
		(matrix.hasEdge(0, 1) ? "Yes" : "No") << endl;
	cout << "List has edge 0-2: " << 
		(list.hasEdge(0, 2) ? "Yes" : "No") << endl;

	cout << endl << "Updated Matrix:" << endl;
	matrix.print();
	cout << endl << "Updated List:" << endl;
	list.print();

	// Заміри часу для великих графів
	runTest(100, 500, "Sparse");
	runTest(100, 2000, "Dense");
}
