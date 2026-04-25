#pragma once
template <typename T>
class ArrayQueue
{
private:
	T* array;
	int head;
	int tail;
	int capacity;
	int count;

public:
	ArrayQueue(int size) : array(new T[size]), head(-1), tail(-1), capacity(size), count(0) {}

	void enqueue(const T& value) {
		if (count == capacity) throw std::overflow_error("Queue is full");
		if (head < 0) head = 0;
		tail = (tail + 1) % capacity;
		array[tail] = value;
		count++;
	}

	T dequeue() {
		if (isEmpty()) throw std::underflow_error("Queue is empty");
		T value = array[head];
		if (head == tail) {
			array[head] = T();
			head = -1;
			tail = -1;
		}
		else {
			array[head] = T();
			head = (head + 1) % capacity;
		}
		count--;
		return value;
	}

	T peek() const {
		if (isEmpty()) throw std::out_of_range("Queue is empty");
		return array[head];
	}

	bool isEmpty() const {
		return count == 0;
	}

	int size() const {
		return count;
	}

	~ArrayQueue() { delete[] array; }
};
