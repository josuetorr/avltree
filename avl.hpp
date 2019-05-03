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

template<class K, class V>
int avltree<K, V>::Node::height() const
{
	if (!this)
		return -1;

	return max(_left -> height(), _right -> height()) + 1;
}

template<class K, class V>
int avltree<K, V>::Node::eqFactor() const
{
	return this -> _right -> height() - this -> _left -> height();
}

// === PRIVATE FUNCTIONS ===

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
	// I'm here
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
void avltree<K, V>::print(Node*& node) const
{
	if (node -> _left)
		print(node -> _left);
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
void avltree<K, V>::print()
{
	print(_root);
}

#endif
