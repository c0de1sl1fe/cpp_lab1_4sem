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
	void clear_(Node* root)
	{
		if (!root)
		{
			return;
		}
		clear_(root->left);
		clear_(root->right);
		delete root;
	}
	void print_(const std::string& prefix, const Node* node, bool isLeft)
	{
		if (node != nullptr)
		{
			std::cout << prefix;
			std::cout << (isLeft ? "|--: " : "L--: ");

			// print the value of the node
			std::cout << node->data << std::endl;

			// enter the next tree level - left and right branch
			print_(prefix + (isLeft ? "|   " : "    "), node->left, true);
			print_(prefix + (isLeft ? "|   " : "    "), node->right, false);
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
set::set(const set& a)
{

}
set::~set()
{
	clear_(root);
}
set& set::operator=(const set& a)
{

}
void set::print()
{
	print_("", root, false);
}

bool set::insert(int key)
{
	
}

bool set::contains(int key)
{

}


bool set::erase(int key)
{

}

