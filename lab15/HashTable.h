#pragma once
#include<vector>
#include<list>

using namespace std;

template<typename T1, typename T2>
class HashTable
{
private:
	struct Node {
		T1 key;
		T2 value;
	};
	int size;
	vector<list<Node>> table;

	int HashFunction(const T1& key) const {
		hash<T1> hasher;
		return hasher(key) % size;
	}

public:
	HashTable(int size) : size(size) { table.resize(size); }

	void insert(const T1& key, const T2& value) {
		int index = HashFunction(key);
		for (auto& node : table[index]) {
			if (node.key == key) {
				node.value = value;
				return;
			}
		}
		table[index].push_back({ key, value });
	}

	T2 get(const T1& key) const {
		int index = HashFunction(key);
		for (const auto& node : table[index]) {
			if (node.key == key) {
				return node.value;
			}
		}
		throw std::out_of_range("Key not found");
	}

	bool remove(const T1& key) {
		int index = HashFunction(key);
		int oldSize = table[index].size();
		table[index].remove_if([&](const Node& node) { return node.key == key; });
		return table[index].size() < oldSize;
	}
};
