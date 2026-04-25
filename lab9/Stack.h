#pragma once
template <typename T>
class Stack
{
private:
	T* array;
	int peekIndex;
	int capacity;

public:
	Stack(int size) : array(new T[size]), peekIndex(-1), capacity(size) {}

	void push(const T& value) {
		if (peekIndex >= capacity - 1) throw std::overflow_error("Stack overflow");
		array[++peekIndex] = value;
	}

	T pop() {
		if (peekIndex < 0) throw std::underflow_error("Stack is empty");
		T value = array[peekIndex];
		array[peekIndex--] = T();
		return value;
	}

	T peek() const {
		if (peekIndex < 0) throw std::out_of_range("Stack is empty");
		return array[peekIndex];
	}

	bool isEmpty() const {
		return peekIndex < 0;
	}

	~Stack() { delete[] array; }
};
