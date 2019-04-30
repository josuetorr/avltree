/**
 *  Simple implementation of an AVL tree.
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

template<class K, class V>
class avltree
{
	private:
		struct node
		{
			node(const K&, const V&);

			/**
			 * Get the height of this node.
			 * The height is calculate recursively with the formula:
			 * 	height = max( left.height, right.height ) + 1
			 *
			 * The height of a leaf (nullptr) is 0
			 *
			 * @return height of this node
			 */
			int height() const;

			/**
			 * Get the equilibrium factor for this node
			 * The eqFact is calculated as such:
			 *
			 * EQ = right.height - left.height
			 *
			 * If the absolute value of EQ, |EQ|, is greater than one.
			 * We rebalance the tree.
			 */
			int eqFactor() const;

			K _key;
			V _value;
			node* _left;
			node* _right;
		};

		node* _root;

		/**
		 * Insert the k, v pair in the node. This function is used
		 * recursively. When ever we find a nullptr node, that's where
		 * we insert the k, v pair
		 *
		 * @param node	Where the pair will be inserted
		 * @param key	Key of the node
		 * @param value	Value of the node
		 */
		void insert(node*& node, const K& key, const V& value);

		/**
		 * Remove the node with the corresponding key.
		 * Does nothing if the key does not exist
		 *
		 * @param node	to remove
		 * @param key	node's key
		 */
		void remove(node*& node, const K& key);

		/**
		 * Rotate the tree about this node to the left
		 *
		 * @param node	Which the left rotation will be performed around
		 */
		void rotateLeft(node*& node);

			/* Rotate the tree about this node to the right
			*
			* @param node	Which the right rotation will be performed around
			*/
		void rotateRight(node*& node);

		/**
		 * Check if the tree contains key
		 *
		 * @param node	To check
		 * @param key	To verify is tree contains
		 *
		 * @return TRUE if tree contains an element associated with key, FALSE otherwise
		 */
		bool contains(node*& node, const K& value) const;

		/**
		 * Get the element associated with the given key
		 *
		 * @param node	Current node
		 * @param key	Key which we are looking for
		 *
		 * @return The value of the element associated with the given key
		 */
		T& getValue(node* node, const K& key) const;

	public:
		avltree();
		avltree(const avltree& avl);			
		~avltree();

		void insert(const K& key, const V& value);
		void remove(const K& key);
		void contains(const K& key) const;
		T& getValue(const K& key);
};

#endif
