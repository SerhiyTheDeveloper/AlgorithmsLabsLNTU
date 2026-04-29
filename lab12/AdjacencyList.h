#pragma once
#include <iostream>
#include <list>
#include <unordered_map>

class AdjacencyList {
private:
    std::vector<std::vector<int>> list;
    int size;

public:
    AdjacencyList(int n) : size(n), list(n) {}

    void addEdge(int u, int v) {
        list[u].push_back(v);
        list[v].push_back(u);
    }

    void removeEdge(int u, int v) {
        if (u >= size || v >= size) {
            throw std::out_of_range("Vertex index out of bounds.");
        }

        auto& v1 = list[u];
        v1.erase(remove(v1.begin(), v1.end(), v), v1.end());

        auto& v2 = list[v];
        v2.erase(remove(v2.begin(), v2.end(), u), v2.end());
    }

    bool hasEdge(int u, int v) const {
        return std::find(list[u].begin(), list[u].end(), v) != list[u].end();
    }

    std::vector<int> getNeighbors(int u) const {
        if (u < 0 || u >= size) throw std::out_of_range("Vertex index out of bounds.");
        return list[u];
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << i << ": ";
            for (int neighbor : list[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
	}
};
