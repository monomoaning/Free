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
	cout << "Í¼µÄµÝ¹éDFS:" << endl;
	a.DFS(0);
	cout << endl;
	a.setUnvisited();
	cout << "Í¼µÄ·ÇµÝ¹éDFS:" << endl;
	a.DFS();
	cout << endl;
	a.setUnvisited();
	cout << "Í¼µÄµÝ¹éBFS:" << endl;
	std::queue<std::vector<int>> b;
	std::vector<int>c;
	c.push_back(0);
	b.push(c);
	a.BFS(b);
	cout << endl;
	a.setUnvisited();
	cout << "Í¼µÄ·ÇµÝ¹éBFS:" << endl;
	a.BFS();
	cout << endl;
	cout << "×î¶ÌÂ·¾¶:" << endl;
	a.setUnvisited();
	cout<<a.Dijskra(0);
	cout << endl;
	cout << "floyd:" << endl;
	cout << a.Floyd(1, 3);
	cout << endl;
	system("pause");
	return 0;
}