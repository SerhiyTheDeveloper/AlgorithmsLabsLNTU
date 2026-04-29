#include <iostream>
#include <chrono>
#include <functional>
#include <vector>
#include <queue>
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

static void DFS(int startNode, AdjacencyList& list, vector<bool>& visited) {
    visited[startNode] = true;
	//cout << startNode << " ";
    for (int neighbor : list.getNeighbors(startNode)) {
        if (!visited[neighbor]) {
            DFS(neighbor, list, visited);
        }
    }
}

static void BFS(int startNode, const AdjacencyList& list, int numVertices) {
    vector<bool> visited(numVertices, false);
    queue<int> queue;

    visited[startNode] = true;
    queue.push(startNode);

    while (!queue.empty()) {
        int u = queue.front();
		//cout << u << " ";
        queue.pop();

        const vector<int>& neighbors = list.getNeighbors(u);

        for (int v : neighbors) {
            if (!visited[v]) {
                visited[v] = true;
                queue.push(v);
            }
        }
    }
}

static AdjacencyList initAdjList(int vertices, int edges) {
    AdjacencyList list(vertices);

    int count = 0;
    while (count < edges) {
        int u = rand() % vertices;
        int v = rand() % vertices;
        if (u != v) {
            list.addEdge(u, v);
            count++;
        }
    }
	return list;
}

int main()
{
    srand(time(0));

    AdjacencyList list1 = initAdjList(100, 200);
	AdjacencyList list2 = initAdjList(100, 2000);
	AdjacencyList list3 = initAdjList(500, 1000);
	AdjacencyList list4 = initAdjList(500, 10000);

    vector<bool> visited1(100, false);
	vector<bool> visited2(100, false);
	vector<bool> visited3(500, false);
	vector<bool> visited4(500, false);

    measureTime("DFS ( 100 Vertices, 200 Edges)", [&]() { DFS(0, list1, visited1); });
    measureTime("BFS ( 100 Vertices, 200 Edges)", [&]() { BFS(0, list1, 100); });
	measureTime("DFS ( 100 Vertices, 2000 Edges)", [&]() { DFS(0, list2, visited2); });
    measureTime("BFS ( 100 Vertices, 2000 Edges)", [&]() { BFS(0, list2, 100); });
	cout << endl;
	measureTime("DFS ( 500 Vertices, 1000 Edges)", [&]() { DFS(0, list3, visited3); });
	measureTime("BFS ( 500 Vertices, 1000 Edges)", [&]() { BFS(0, list3, 500); });
	measureTime("DFS ( 500 Vertices, 10000 Edges)", [&]() { DFS(0, list4, visited4); });
	measureTime("BFS ( 500 Vertices, 10000 Edges)", [&]() { BFS(0, list4, 500); });

	return 0;
}
