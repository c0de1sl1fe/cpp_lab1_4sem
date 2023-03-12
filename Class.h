#pragma once
#include <iostream>
#include <string>
#include <typeinfo>
#include <limits>
#include <vector>

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int value = 0)
	{
		data = value;
		left = right = NULL;
	}
};

class set
{
private:

	Node* root_;

	//Node* insert_(Node* root, int value)
	//{
	//	if (!root)
	//		return new Node(value);
	//	if (value == root->data)
	//	{
	//		return NULL;
	//	}
	//	if (value > root->data)
	//	{
	//		root->right = insert_(root->right, value);
	//	}
	//	else
	//	{
	//		root->left = insert_(root->left, value);
	//	}

	//}

	Node* FindMin_(Node* root)
	{
		while (root->left != NULL) root = root->left;
		return root;
	}

	Node* erase_(Node* root, int key) {
		if (root == NULL) return root;
		else if (key < root->data) root->left = erase_(root->left, key);
		else if (key > root->data) root->right = erase_(root->right, key);
		// Wohoo... I found you, Get ready to be deleted	
		else {
			// Case 1:  No child
			if (root->left == NULL && root->right == NULL) {
				delete root;
				root = NULL;
			}
			//Case 2: One child 
			else if (root->left == NULL) {
				struct Node* temp = root;
				root = root->right;
				delete temp;
			}
			else if (root->right == NULL) {
				struct Node* temp = root;
				root = root->left;
				delete temp;
			}
			// case 3: 2 children
			else {
				struct Node* temp = FindMin_(root->right);
				root->data = temp->data;
				root->right = erase_(root->right, temp->data);
			}
		}
		return root;
	}
	bool insert_(Node*& root, int value)
	{
		if (!root)
		{
			root = new Node(value);
			return true;
		}

		if (root->data == value)
		{
			return false;
		}
		if (root->data > value)
		{
			insert_(root->left, value);
		}
		else
		{
			insert_(root->right, value);
		}

	}
	void clear_(Node*& root)
	{
		if (!root)
		{
			return;
		}
		clear_(root->left);
		clear_(root->right);
		delete root;
		root = NULL;
	}
	void print_(const std::string& prefix, const Node* node, bool isLeft) const
	{
		if (node != nullptr)
		{
			std::cout << prefix;
			std::cout << (isLeft ? "ÃÄÄ" : "ÀÄÄ");
			// print the value of the node
			std::cout << node->data << std::endl;

			// enter the next tree level - left and right branch
			print_(prefix + (isLeft ? "|   " : "    "), node->left, true);
			print_(prefix + (isLeft ? "|   " : "    "), node->right, false);
		}
	}
	void copy_(Node*& dst, const Node* src)
	{
		if (!src)
		{
			dst = NULL;
			return;
		}
		dst = new Node(src->data);
		copy_(dst->left, src->left);
		copy_(dst->right, src->right);		
	}

	Node* contains_(Node* root, int value) const
	{
		while (root != NULL && root->data != value) {
			if (value == root->data) {
				return root;
			}
			else if (value < root->data) {
				root = root->left;
			}
			else {
				root = root->right;
			}
		}
		return root;
		//if (!root)
		//{
		//	return NULL;
		//}
		//if (root->data == value)
		//{
		//	return root;
		//}
		//if (root->data > value)
		//{
		//	contains_(root->left, value);
		//}
		//else 
		//{
		//	contains_(root->right, value);
		//}
	}
	
public:
	set();
	set(const set& a);
	~set();
	set& operator=(const set& src);
	void print() const;
	bool insert(int key);
	bool contains(int key) const;
	bool erase(int key);
	Node* getRoot() const;
};
Node* set::getRoot() const
{
	return root_;
}

set::set()
{
	root_ = NULL;
}

set::set(const set& src)
{
	root_ = NULL;
	copy_(root_, src.root_);
}
set::~set()
{
	clear_(root_);
}
set& set::operator=(const set& src)
{
	if (this == (&src)) { return *this; }
	if (!src.root_)
	{
		clear_(root_);
	}
	copy_(root_, src.root_);
	return *this;
}
void set::print() const
{
	print_("", root_, false);
}

bool set::insert(int key)
{
	return insert_(root_, key);
}

bool set::contains(int key) const
{
	return contains_(root_, key) ? true : false;
}


bool set::erase(int key)
{
	if (!contains_(root_, key))
	{
		return false;
	}
	erase_(root_, key);
	return true;
}



class EClassException
{
protected:
	char _err[256];
public:
	EClassException(const char* err);
	virtual void Print();
	virtual ~EClassException();
};


EClassException::EClassException(const char* err)
{
	strncpy_s(_err, err, 255);
	_err[255] = 0;
}
void EClassException::Print()
{
	std::cout << _err << std::endl;
}
EClassException::~EClassException() {}