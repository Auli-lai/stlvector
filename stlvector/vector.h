#pragma once
#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;
template<typename T>
class myvector {
private:
	T* data;
	size_t len;
	size_t cap;
	void resize(size_t new_cap) {
		T* new_data = new T[new_cap];
		
		for (int i = 0; i < len; ++i) {
			new_data[i] = data[i];
		}
		
		delete[] data;
		data = new_data;
		cap = new_cap;
	}
public:
	myvector() : data[nullptr], cap(0), len(0){};
	myvector(size_t _cap) : cap(_cap) , len(0){
		data = new T[cap];
	}
	~myvector() {
		delete[] data;
	}
	myvector(initializer_list<T> list) : len(list.size()), cap(list.size()) {
		data = new T[cap];
		size_t i = 0;
		for (const auto& item : list) {
			data[i++] = item;
		}

	}
	myvector(const myvector& other) : len(other.len), cap(other.cap) {
		data = new T[cap];
		for (size_t i = 0; i < len; ++i) {
			data[i] = other.data[i];
		}
	}
	myvector& operator=(const myvector& other) {
		if (this == &other) return *this;
		
		delete[] data;

		len = other.len;
		cap = other.cap;
		data = new T[cap];

		for (size_t i = 0; i < len; ++i) {
			data[i] = other.data[i];
		}
		return *this;
	}
	/*
	* 这里的运算符重载有特殊含义，和上面的不同，上面的是构造函数特有的性质，即使没有运算符重载(=)也可以使用。
	* 一个是vector刚开始定义一个变量的时候进行赋值
	* 一个是定义变量之后进行的赋值
	*/
	void push_back(const T& val){
		if (len >= cap) {
			size_t new_cap = (cap == 0) ? 2 : cap * 2;
			resize(new_cap);
		}
		
		data[len] = val;
		len++;
	}
	void pop_back() {
		if (len > 0) {
			len--;
		}
	}
	T& operator[](size_t index) {
		return data[index];

	}
	T& at(size_t index) {
		if (index >= len) {
			throw out_of_range("Index out of range, you dumbass!");
		}
		return data[index];

	}
	
	size_t get_size() const { return len; }

	size_t get_cap() const { return cap; }
	
	bool empty() const{
		if (len <= 0) {
			return true;
		}
		return false;
	}
	void reserve(size_t new_cap) {
		if (new_cap > cap) {
			resize(new_cap);
		}
	}


};
