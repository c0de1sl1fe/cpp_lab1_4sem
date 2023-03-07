#pragma once
#include <iostream>
#include <string>
#include <typeinfo>
#include <limits>
#include <vector>

class set
{
private:
	struct Node
	{
		int data;
		Node* left; 
		Node* right;
		Node(int value)
		{
			data = value;
			left = right = NULL;
		}
	};
	Node* root;

	Node* insert_(Node* root, int value)
	{
		if (!root)
		{
			root = new Node(value);
		}

	}




public:
	set(const set& a);
	~set();
	set& operator=(const set& a);
	void print();
	bool insert(int key);
	bool contains(int key);
	bool erase(int key);

};

bool set::insert(int key)
{

}
bool set::contains
(int key)
{

}


bool set::erase(int key)
{

}

