#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;

class AdjacencyMatrix {
    vector<vector<int>> matrix;
    int size;

public:
    AdjacencyMatrix(int n) : size(n), matrix(n, vector<int>(n, 0)) {}

    void addEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    void removeEdge(int u, int v) {
        matrix[u][v] = 0;
        matrix[v][u] = 0;
    }

    bool hasEdge(int u, int v) const { return matrix[u][v] == 1; }

    vector<int> getNeighbors(int u) const {
        if (u < 0 || u >= size) throw out_of_range("Vertex not found");

        vector<int> neighbors;
        for (int v = 0; v < size; ++v) {
            if (matrix[u][v] == 1) {
                neighbors.push_back(v);
            }
        }
        return neighbors;
    }

    void print() {
        if (size > 10) return;
        cout << "  ";
        for (int i = 0; i < size; i++) cout << i << " ";
        cout << endl;
        for (int i = 0; i < size; i++) {
            cout << i << " ";
            for (int j = 0; j < size; j++) cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
};
