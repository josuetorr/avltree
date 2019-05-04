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
#define _AVL_H_

template<class K, class V>
class avltree
{
	private:
		struct Node
		{
			Node(const K& key, const V& value);
			K _key;
			V _value;
			Node* _left;
			Node* _right;	

		};


		Node* _root;

		/* This kind of implementation of the height and eqfactor
		 * might not be the best. If the strucutre gets huge, the 
		 * function stack call might run out of space*/
		int height(Node*& node) const;
		int eqFactor(Node*& node) const;

		void rotateRight(Node*& subTreeRoot);
		void rotateLeft(Node*& subTreeRoot);
		void rebalance(Node*& node);
		void insert(Node*& node, const K& key, const V& value);
		void remove(Node*& node, const K& key, const V& value);
		void empty(Node*& node);
		bool contains(Node*& node, const K& key) const;
		void copy(const avltree& a);
		V& getValue(Node*& node, const K& key) const;
		void print(Node*& node) const;

	public:
		avltree();
		avltree(const avltree& a);
		~avltree();
		
		void insert(const K& key, const V& value);
		void remove(const K& key);
		bool isEmpty() const;
		bool contains(const K& key);
		V& getValue(const K& key);
		void print();
};

#include "avl.hpp"

#endif
