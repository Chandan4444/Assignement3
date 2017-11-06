#pragma once
#include <iostream>
/*
			Complete
Two versions of the constructor exist
isEmpty
Size (return _numElems or _capacity)
popBack
pushBack
clear
extend
			Incomplete
Extend needs to be made private
Make Destructors and handle free pointers
Insert
Reverse
Comments
*/
class SimpleVector {
private:
	int* _array;
	int _numElements;
	int _capacity;
	//use destructors
	void extend() {
		int *temp = new int[_capacity * 2];
		for (int i = 0; i < _capacity; i++) {
			temp[i] = _array[i];
		}
		_array = temp;
		_capacity = _capacity * 2;
	}
public:
	SimpleVector() {
		_capacity = 10;
		_array = new int[_capacity];
	}
	SimpleVector(int presize) {
		_capacity = presize;
		_array = new int[_capacity];
	}
	//Put a Destructor in here. Destructors cannot be overloaded, because destructors take no arguments, no return type.
	~SimpleVector() {

	}
	int isEmpty() {
		if (_numElements == 0) { return 1; }
		else return 0;
	}
	int Size() {
		return _numElements;
	}
	void Pop_back() {
		_array[_numElements-1] = 0;
		-_numElements--;
	}

	//thoretically Push_back should be good now.
	void Push_back(int x) {
		if (_numElements < _capacity) {
			_array[_numElements] = x;
			_numElements++;

		}
		else {
			int *temp = new int[_capacity];
			for (int i = 0; i < _capacity; i++) {
				temp[i] = _array[i];
			}
			_capacity++;
			_array = new int[_capacity];
			for (int i = 0; i < _capacity - 1; i++) {
				_array[i] = temp[i];
			}
			_array[_capacity] = x;
		}
	}

	void clear() {
		_array = new int[_capacity];
		_numElements = 0;
	}
	int insert(int x, int i) {
		if (x > _capacity) {
			return 1;
		}
		else {
			for (int j = i; j > 0; j--)
				Push_back(_numElements + j);
			return 0;
		}

	}
	//provided code
	int& operator[](int i) { if (i < 0 || i >= _numElements) { std::cout << "Index out of bounds" << std::endl; return _array[0]; } return _array[i]; }
	const int& operator[](int i) const { if (i < 0 || i >= _numElements) { std::cout << "Index out of bounds" << std::endl; return _array[0]; } return _array[i]; }


};
