#ifndef _AVL_HPP_
#define _AVHL_HPP_

#include <iostream> // cout 
using namespace std;

int max (const int& n, const int& m)
{
	return n > m ? n : m;
}

// === NODE FUNCTIONS ===

template<class K, class V>
avltree<K, V>::Node::Node(const K& key, const V& value) :
	_key(key), _value(value), _left(NULL), _right(NULL) {}

// === PRIVATE FUNCTIONS ===

template<class K, class V>
int avltree<K, V>::height(Node*& node) const
{
	if (!node)
		return -1;

	return max(height(node -> _left), height(node -> _right)) + 1;
}

template<class K, class V>
int avltree<K, V>::eqFactor(Node*& node) const
{
	return height(node -> _right) - height(node -> _left);
}

template <class K, class V>
void avltree<K, V>::rotateRight(Node*& subTreeRoot)
{
	Node* temp = subTreeRoot -> _left;
	subTreeRoot -> _left = temp -> _right;
	temp -> _right = subTreeRoot;
	subTreeRoot = temp;
}

template <class K, class V>
void avltree<K, V>::rotateLeft(Node*& subTreeRoot)
{
	Node* temp = subTreeRoot -> _right;
	subTreeRoot -> _right = temp -> _left;
	temp -> _left = subTreeRoot;
	subTreeRoot = temp;
}

template<class K, class V>
void avltree<K, V>::rebalance(Node*& node)
{
	// left side
	if (eqFactor(node) < -1)
	{
		if (eqFactor(node -> _left) > 0)
			rotateLeft(node -> _left);
		rotateRight(node);
	}
	else if (eqFactor(node) > 1)
	{
		if (eqFactor(node -> _right) < 0)
			rotateRight(node -> _right);
		rotateLeft(node);
	}
}

template<class K, class V>
void avltree<K, V>::insert(Node*& node, const K& key, const V& value)
{
	if (!node)
	{
		node = new Node(key, value);
	}
	else
	{
		if (key > node -> _key)
			insert(node -> _right, key, value);
		else if (key < node -> _key)
			insert(node -> _left, key, value);
		rebalance(node);
	}
}

template<class K, class V>
void avltree<K, V>::empty(Node*& node)
{
	if (node -> _left)
		empty(node -> _left);
	delete node;
	if (node -> _right)
		empty(node -> _right);
}

template<class K, class V>
bool avltree<K, V>::contains(Node*& node, const K& key) const
{
	if (!node)
		return false;
	else if (key == node -> _key)
		return true;
	else if (key > node -> _key)
		return contains(node -> _right, key);
	else 
		return contains(node -> _left, key);	
}

template<class K, class V>
V& avltree<K, V>::getValue(Node*& node, const K& key) const
{
	// replace this function with the operatot []
}

template<class K, class V>
void avltree<K, V>::print(Node*& node) const
{
	if (node -> _left)
		print(node -> _left);
	if (node == _root)
		cout << "(ROOT) ";
	cout << "key: " 
		 << node -> _key 
		 << ", value: "
		 << node -> _value
		 << endl;
	if (node -> _right)
		print(node -> _right);	
}

// === PUBLIC FUNCTIONS ===

template<class K, class V>
avltree<K, V>::avltree() :
	_root(NULL) {}

template<class K, class V>
avltree<K, V>::avltree(const avltree& a)
{
	copy(a);	
}

template<class K, class V>
avltree<K, V>::~avltree()
{
	empty(_root);
}

template<class K, class V>
void avltree<K, V>::insert(const K& key, const V& value)
{
	insert(_root, key, value);
}

template<class K, class V>
bool avltree<K, V>::isEmpty() const
{
	return !_root;
}

template <class K, class V>
bool avltree<K, V>::contains (const K& key) 
{
	return contains(_root, key);
}

template<class K, class V>
V& avltree<K, V>::getValue(const K& key)
{
	return getValue(_root, key);
}

template<class K, class V>
void avltree<K, V>::print()
{
	print(_root);
}

#endif
