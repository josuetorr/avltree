#include "avl.hpp"

// === PRIVATE INTERFACE ===

template<class K, class V>
avltree<K, V>::avltree::node::node(const K& key, const V& value) :
		_key(key), _value(value), _left(nullptr), _right(nullptr) {}


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
