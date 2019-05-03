#ifndef _AVL_HPP_
#define _AVHL_HPP_

#include <iostream> // cout 

int max (const int& n, const int& m)
{
	return n > m ? n : m;
}

// === NODE FUNCTIONS ===

template<class K, class V>
avltree<K, V>::Node::Node(const K& key, const V& value) :
	_key(key), _value(value), _left(nullptr), _right(nullptr) {}

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
void avltreee<K, V>::rotateRight(Node*& subTreeRoot)
{
	Node* temp = subTreeRoot -> _left;
	// im here			
}

template<class K, class V>
void avltree<K, V>::empty(Node*& node)
{
	if (!node -> _left)
		empty(node -> _left);
	delete node;
	if (!node -> _right)
		empty(node -> _right);
}

// === PUBLIC FUNCTIONS ===

template<class K, class V>
avltree<K, V>::avltree() :
	_root(nullptr) {}

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

#endif

