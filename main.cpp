#include <iostream>
#include <string>
#include "avl.h"

using namespace std;

int main(int argc, const char* argv[])
{
	avltree<string, int> t;

	if (t.isEmpty())
		cout << "tree is empty" << endl << endl;

	t.insert("sunday", 1);
	t.insert("monday", 2);
	t.insert("tuesdays", 3);
	t.insert("wednesday", 4);
	t.insert("thrusday", 5);
	t.insert("friday", 6);
	t.insert("saturday", 7);
	t.print();

	if (!t.isEmpty())
		cout << endl << "tree is not empty" << endl;

	if (t.contains("monday"))
		cout << endl << "the tree contains the key: monday" << endl;
	else
		cout << "the tree does no contain the key: monday" << endl;

	cout << "The value of the \"monday\" is: " << t.getValue("monday") << endl;
}
