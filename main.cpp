#include <iostream>
#include <string>
#include "avl.h"

using namespace std;

int main(int argc, const char* argv[])
{
	avltree<string, int> t;
	t.insert("sunday", 1);
	t.insert("monday", 2);
	t.insert("tuesdays", 3);
	t.insert("wednesday", 4);
	t.insert("thrusday", 5);
	t.insert("friday", 6);
	t.insert("saturday", 7);
	t.print();
}
