/**
 * This is a simple implementation of an avltree.
 * Each node has a key and a value. You can think of it as
 * an associative array.
 *
 * @author: Josue Torres
 * @email: josue.dtorres@gmail.com
 *
 * @version: 0.1
 */

#ifndef _AVL_H_
#define _AVL_H

template<class K, class V>
class avltree
{
	private:
		struct Node
		{
			Node(const K& key, const V& value);
			K _key;
			V _value;
			Node*& _left;
			Node*& _right;	

			int height() const;
			int eqFactor() const;
		};


		Node* _root;

		void rotateRight(Node*& subTreeRoot);
		void rotateLeft(Node*& subTreeRoot);
		void rebalance(Node*& node);
		void insert(Node*& node, const K& key, const V& value);
		void remove(Node*& node, const K& key, const V& value);
		void empty(Node*& node);
		bool contains(Node*& node, const K& key) const;
		void copy(const avltree& a);
		void print(Node*& node) const;

	public:
		avltree();
		avltree(const avltree& a);
		~avltree();
		
		void insert(const K& key, const V& value);
		void remove(const K& key);
		bool isEmpty() const;
		bool contains(const K& key) const;
		V& getValue(const K& key) const;
		void print() const;
};

#include "avl.hpp"

#endif
