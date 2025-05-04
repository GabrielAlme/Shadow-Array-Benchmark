#pragma once

template <typename T>
class ShadowArray {
private: //creating private vars
	int size;
	int capacity;
	int threshold;
	T* arr = nullptr;
	T* shadowArray = nullptr;
	bool odd = false;

public:
	ShadowArray(int size) { //constructor with variable size
		capacity = size;
		if (size% 2 == 1) {
			threshold = (size / 2) + 1;
			odd = true;
		}
		else {
			threshold = (size / 2);
			odd = false;
		}
		arr = new T[size];
		shadowArray = new T[size*2];
	}
	ShadowArray() { //basic constructor
		size = 0;
		threshold = 0;
		capacity = 1;
		arr = new T[1];
		shadowArray = new T[capacity*2];
	}
	void tooBig() { //deletes old array and creates new shadow
		T* foo = arr;
		arr = shadowArray;
		capacity = capacity * 2;
		shadowArray = new T[capacity * 2];
		threshold = capacity / 2;
		odd = false;
	}
	void add(T data) { //adds an item to the end of the array
		if (size >= capacity) // checks if the array is full
			tooBig();
		arr[size] = data;
		if (size >= threshold){ 
			if (size != 0) {
				shadowArray[size] = arr[size];
				shadowArray[size - (capacity / 2)] = arr[size - (capacity / 2)];
			}
			else
				shadowArray[size] = arr[size];
		}
		size++;
	}
	void remove(int index) { //removes the item at current index for the array and shadow array
		T* temp = arr;
		arr = new T[capacity];
		for (int i = 0; i < index; i++)
			arr[i] = temp[i];
		for (int i = index; i < size; i++)
			arr[i] = temp[i + 1];
		delete[] temp;
		T* pemt = shadowArray;
		shadowArray = new T[capacity * 2];
		for (int i = 0; i < index; i++)
			shadowArray[i] = pemt[i];
		for (int i = index; i < capacity; i++)
			shadowArray[i] = pemt[i + 1];
		delete[] pemt;
	}

	T get(int index) {
		T data = arr[index];
		return data;
	}
};