#include"LinkedList.h"
#include"BinarySearchTree.h"
#include"Farey.h"
#include<iostream>
#include<string>
using namespace std;
int main(int argc, char *charv[]) {
	BinaryTree<string>a;
	a.push_back("helloworld");
	a.push_back("sjfsd");
	a.push_back("dfjasdwe");
	a.push_back("cer");
	a.BreadthVisit();
	a.ForwardVisit();
	system("pause");
	return 0;
}