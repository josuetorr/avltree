#include "avl.hpp"

// === PRIVATE INTERFACE ===

template<class K, class V>
avltree<K, V>::node::node(const K& key, const V& value) :
	_key(key), _value(value), _left(nullptr), _right(nullptr) {}

template<class K,class V>
int avltree<K, V>::node::height() const
{
	if (_left == nullptr && _right == nullptr)
		return 0;			
	else if (_left == nullptr)
		return _right -> height();
	else if (_right == nullptr)
		return _left -> height();
	else
		return max(_left -> height(), _right -> height()) + 1;
}

template<class K, class V>
int avltree<K, V>::node::eqFactor() const
{
	return _right -> height() - _left -> height();	
}

template<class K, class V>
int avltree<K, V>::max(const int& n, const int& m) const
{
	return n > m ? n : m;	
}

template<class K, class V>
void alvtree<K, V>::rotateRight(node*& rootSubTree)
{
	node* temp = rootSubTree -> _left;
	rootSubTree -> _left = temp -> _right;
	temp -> _right = rootSubTree;
	rootSubTree = temp;
}

template<class K, class V>
void alvtree<K, V>::rotateLeft(node*& rootSubTree)
{
	node* temp = rootSubTree -> _right;
	rootSubTree -> _right = temp -> _left;
	temp -> _left = rootSubTree;
	rootSubTree = temp;
}

template<class K, class V>
void avltree<K, V>::insert(node*&, const K& key, const T& value)
{
	if (node == nullptr)
	{
		node = new node(key, value);
	}	
	else
	{
		// I AM HERE
		// CORE PART OF THE ALGORITHM
	}
}

// === PUBLIC INTERFACE ===

template<class K, class V>
avltree<K, V>::avltree() :
	_root(nullptr) {}

// Copy content from given tree to *this
template<class K, class V>
avltree<K, V>::avltree(const avltree& avl) 
{}

template<class K, class V>
avltree<K, V>::~avltree()
{}

