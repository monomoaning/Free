#include "hashtable.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	hashtable a;
	a.print();
	a.addItemFromFile("hashtable.txt");
	//a.print();
	//a.deleteItem("wrj");
	a.print();
	system("pause");
	return 0;
}