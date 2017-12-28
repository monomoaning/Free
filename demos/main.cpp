#include"Graph.h"
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(int argc, char *charv[]) {
	srand((unsigned)time(NULL));
	graph a(rand() % 10 + 4);
	a.print();
	cout << "ͼ�ĵݹ�DFS:" << endl;
	a.DFS(0);
	cout << endl;
	a.setUnvisited();
	cout << "ͼ�ķǵݹ�DFS:" << endl;
	a.DFS();
	cout << endl;
	a.setUnvisited();
	cout << "ͼ�ĵݹ�BFS:" << endl;
	std::queue<std::vector<int>> b;
	std::vector<int>c;
	c.push_back(0);
	b.push(c);
	a.BFS(b);
	cout << endl;
	a.setUnvisited();
	cout << "ͼ�ķǵݹ�BFS:" << endl;
	a.BFS();
	cout << endl;
	cout << "���·��:" << endl;
	a.setUnvisited();
	cout<<a.Dijskra(0);
	cout << endl;
	cout << "floyd:" << endl;
	cout << a.Floyd(1, 3);
	cout << endl;
	system("pause");
	return 0;
}