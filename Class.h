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
		Node(int value = 0)
		{
			data = value;
			left = right = NULL;
		}
	};
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
	void print_(const std::string& prefix, const Node* node, bool isLeft)
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
	void erase(Node*& root, int value)
	{

	}
	Node* contains_(Node* root, int value)
	{
		if (!root)
		{
			return NULL;
		}
		if (root->data < value)
		{
			contains_(root->right, value);
		}
		if (root->data > value)
		{
			contains_(root->left, value);
		}
		if (root->data == value)
		{
			return root;
		}
	}
	
public:
	set();
	set(const set& a);
	~set();
	set& operator=(const set& src);
	void print();
	bool insert(int key);
	bool contains(int key);
	bool erase(int key);

};
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
void set::print()
{
	print_("", root_, false);
}

bool set::insert(int key)
{
	return insert_(root_, key);
}

bool set::contains(int key)
{
	return contains_(root_, key) ? true : false;
}


bool set::erase(int key)
{
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