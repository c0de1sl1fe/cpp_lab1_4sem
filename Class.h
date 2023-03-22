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
	unsigned char height;
	Node(int value = 0)
	{
		data = value;
		left = right = NULL;
		height = 1;
	}
};

class set
{
private:
	Node* root_;

	unsigned char height(Node* p)
	{
		return p ? p->height : 0;
	}

	int bfactor(Node* p)
	{
		return height(p->right) - height(p->left);
	}

	void fixheight(Node* p)
	{
		unsigned char hl = height(p->left);
		unsigned char hr = height(p->right);
		p->height = (hl > hr ? hl : hr) + 1;
	}

	Node* rotateright(Node* p) // правый поворот вокруг p
	{
		Node* q = p->left;
		p->left = q->right;
		q->right = p;
		fixheight(p);
		fixheight(q);
		return q;
	}

	Node* rotateleft(Node* q) // левый поворот вокруг q
	{
		Node* p = q->right;
		q->right = p->left;
		p->left = q;
		fixheight(q);
		fixheight(p);
		return p;
	}
	Node* balance(Node* p) // балансировка узла p
	{
		fixheight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->right) < 0)
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->left) > 0)
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p; // балансировка не нужна
	}



	

	Node* findmin(Node* root) // поиск узла с минимальным ключом в дереве p 
	{
		return root->left ? findmin(root->left) : root;
	}
	Node* removemin(Node* root) // удаление узла с минимальным ключом из дерева p
	{
		if (root->left == 0)
			return root->right;
		root->left = removemin(root->left);
		return balance(root);
	}
	Node* balanced_(Node* root)
	{
		if (!root)
		{
			return NULL;
		}
		root = balance(root);
		root->left = balanced_(root->left);
		root->right = balanced_(root->right);
		return balance(root);
	}

	Node* FindMin_(Node* root)
	{
		while (root->left != NULL) root = root->left;
		return root;
	}

	Node* erase_(Node* root, int key) {
		if (root == NULL) return root;
		else if (key < root->data) root->left = erase_(root->left, key);
		else if (key > root->data) root->right = erase_(root->right, key);
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
	//Node* erase_(Node* root, int key) // erase for AVL
	//{
	//	if (!root) return 0;
	//	if (key < root->data)
	//		root->left = erase_(root->left, key);
	//	else if (key > root->data)
	//		root->right = erase_(root->right, key);
	//	else //  k == p->key 
	//	{
	//		Node* q = root->left;
	//		Node* r = root->right;
	//		delete root;
	//		if (!r) return q;
	//		Node* min = findmin(r);
	//		min->right = removemin(r);
	//		min->left = q;
	//		return balance(min);
	//	}
	//	return balance(root);
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
			return insert_(root->left, value);
		}
		else
		{
			return insert_(root->right, value);
		}
	}

	//Node* insert_(Node*& root, int k) // insert avl
	//{
	//	if (!root) return new Node(k);
	//	if (k == root->data)
	//	{
	//		return NULL;
	//	}
	//	if (k < root->data)
	//		root->left = insert_(root->left, k);
	//	else
	//		root->right = insert_(root->right, k);
	//	return balance(root);
	//}

	
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
			std::cout << (isLeft ? "ГДД" : "АДД");
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
	Node* const getRoot() const;

};
Node* const set::getRoot() const
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
	if (contains_(root_, key))
		return false;
	root_ = insert_(root_, key);
	return true;
	//return insert_(root_, key);
	
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
	root_ = erase_(root_, key);
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