#include "avl.hpp"

// === PRIVATE INTERFACE ===

template<class K, class V>
Avltree<K, V>::Avltree::Node::Node(const K& key, const V& value) :
		_key(key), _value(value), _left(nullptr), _right(nullptr) {}


// === PUBLIC INTERFACE ===

template<class K, class V>
Avltree<K, V>::Avltree() :
		_root(nullptr) {}

// Copy content from given tree to *this
template<class K, class V>
Avltree<K, V>::Avltree(const Avltree& avl) 
{}

template<class K, class V>
Avltree<K, V>::~Avltree()
{}
