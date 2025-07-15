#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;
struct node
{
	int key, val;
	node* prev;
	node* next;
	node() : key(0), val(0), prev(nullptr), next(nullptr) {};
	node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {};
};
class lru {
private:
	unordered_map<int, node*> cache;
	node* fake_head;
	node* fake_tail;
	int size;
	int cap;
	lru() {
		fake_head = new node();
		fake_tail = new node();
		fake_head -> next = fake_tail;
		fake_tail -> prev = fake_head;
	}
	void addhead(node* demo) {
		demo->prev = fake_head;
		demo->next = fake_head->next;

		fake_head -> next ->prev = demo;

		fake_head->next = demo;
	}
};