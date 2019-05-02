/**
 *  Simple implementation of an AVL tree.
 *  The equilibrium factor is calculated by substracting the right height from the left
 *  EQ = H_r - H_l
 *
 *  created: 30/04/2019
 *  @author: Josue Torres
 *  @email: josue.dtorres@gmail.com
 *
 *  version 1.0
 */ 
#ifndef _AVL_HPP_
#define _AVL_HPP_

#include <string>
#include <iostream>

using namespace std;

/**
 * Return max between n and m
 */	
int max(const int& n, const int& m)
{
	return n > m ? n : m;
}

template<class K, class V>
class avltree
{
	private:
		struct Node
		{
			Node(const K&, const V&);

			/**
			 * Get the height of this node.
			 * The height is calculate recursively with the formula:
			 * 	height = max( left.height, right.height ) + 1
			 *
			 * The height of a leaf (nullptr) is 0
			 *
			 * @return height of this node
			 */
			int height() const
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

			/**
			 * Get the equilibrium factor for this node
			 * The eqFact is calculated as such:
			 *
			 * EQ = right.height - left.height
			 *
			 * If the absolute value of EQ, |EQ|, is greater than one.
			 * We rebalance the tree.
			 */
			int eqFactor() const
			{
				return _right -> height() - _left -> height();	
			}
			/**
			 * A node is a leaf if both _left and _right are null
			 */
			bool isLeaf() const
			{
				return _left == nullptr && _right == nullptr;
			}

			K _key;
			V _value;
			Node* _left;
			Node* _right;
		};

		Node* _root;


		/**
		 * Insert the k, v pair in the node. This function is used
		 * recursively. When ever we find a nullptr node, that's where
		 * we insert the k, v pair
		 *
		 * @param node	Where the pair will be inserted
		 * @param key	Key of the node
		 * @param value	Value of the node
		 */
		void insert(Node*& node, const K& key, const V& value);

		/**
		 * Remove the node with the corresponding key.
		 * Does nothing if the key does not exist
		 *
		 * @param node	to remove
		 * @param key	node's key
		 */
		void remove(Node*& node, const K& key);

		/**
		 * Rotate the tree about this node to the left
		 *
		 * @param node	Which the left rotation will be performed around
		 */
		void rotateLeft(Node*& node);

			/* Rotate the tree about this node to the right
			*
			* @param node	Which the right rotation will be performed around
			*/
		void rotateRight(Node*& node);

		/**
		 * Perform the logic for the self balancing algorithm.
		 * Rebalacing is done if the eqFactor a the node goes outside the boundaries, i.e.
		 * -1 < eqFactor < 1.
		 *
		 * @param node	Around where the rebalancing will take place, if any is needed.
		 */
		void rebalance(Node*& node);

		/**
		 * Check if the tree contains key
		 *
		 * @param node	To check
		 * @param key	To verify is tree contains
		 *
		 * @return TRUE if tree contains an element associated with key, FALSE otherwise
		 */
		bool contains(Node*& node, const K& value) const;

		/**
		 * Get the element associated with the given key
		 *
		 * @param node	Current node
		 * @param key	Key which we are looking for
		 *
		 * @return The value of the element associated with the given key
		 */
		V& getValue(Node* node, const K& key) const;

		/**
		 * Empty the entire tree structure
		 */
		void empty(Node*& node);

		void print(Node*& node) ;

	public:
		avltree();
		avltree(const avltree& avl);			
		~avltree();

		void insert(const K& key, const V& value);
		void remove(const K& key);
		void contains(const K& key) const;
		V& getValue(const K& key);
		bool isEmpty() const;
		void print();
};

// === PRIVATE INTERFACE ===

template<class K, class V>
avltree<K, V>::Node::Node(const K& key, const V& value) :
	_key(key), _value(value), _left(nullptr), _right(nullptr) {}

template<class K, class V>
void avltree<K, V>::rotateRight(Node*& rootSubTree)
{
	Node* temp = rootSubTree -> _left;
	rootSubTree -> _left = temp -> _right;
	temp -> _right = rootSubTree;
	rootSubTree = temp;
}

template<class K, class V>
void avltree<K, V>::rotateLeft(Node*& rootSubTree)
{
	Node* temp = rootSubTree -> _right;
	rootSubTree -> _right = temp -> _left;
	temp -> _left = rootSubTree;
	rootSubTree = temp;
}

template <class K, class V>
void avltree<K, V>::rebalance(Node*& node)
{
	// Left side
	if (node -> eqFactor() < -1)	
	{
		// zig-zag imbalancement
		if (node -> _left -> eqFactor() > 0)
			rotateLeft(node -> _left);
		// always rotate right
		rotateRight(node);
	}
	// Right side
	else if (node -> eqFactor()  > 1)
	{
		if (node -> _right -> eqFactor() < 0)
			rotateRight(node -> _right);	
		rotateLeft(node);
	}
}

template<class K, class V>
void avltree<K, V>::insert(Node*& node, const K& key, const V& value)
{
	if (node == nullptr)
	{
		node = new Node(key, value);
	}	
	else
	{
		if (key < node -> _key)
			insert(node -> _left, key, value);
		else if (key > node -> _key)
			insert(node -> _right, key, value);
		rebalance(node);
	}
}

template<class K, class V>
void avltree<K, V>::empty(Node*& node)
{
	if (node -> isLeaf())
		delete node;
	else if (node -> _left != nullptr)
		empty(node -> _left);
	else if (node -> _right != nullptr)
		empty(node -> _right);	
}

template<class K, class V>
void avltree<K, V>::print( Node*& node) 
{
	if (node -> isLeaf())
		cout << node -> _value << endl;
	else if (node -> _left != nullptr)
		print(node -> _left);
	else if (node -> _right != nullptr)
		print(node -> _right);
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
