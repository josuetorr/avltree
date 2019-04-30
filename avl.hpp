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
class Avltree
{
	private:
			struct Node
			{
				Node(const K&, const V&);

				K _key;
				V _value;
				Node* _left;
				Node* _right;
			};

			Node* _root;

	public:
			Avltree();
			Avltree(const Avltree& avl);			
			~Avltree();
};

#endif
