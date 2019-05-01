#include <iostream>
#include "avl.h"
#include <string>

using namespace std;

int main(int argc, const char* argv[])
{
	avltree<string, int> t;
	t.insert("Sunday", 1);
	t.insert("Monday", 2);
	t.insert("Tuesday", 3);
	t.insert("Wednesday", 4);
	t.insert("Thursday", 5);
	t.insert("Friday", 6);
	t.insert("Saturday", 7);
	t.print();
	return 0;
}
