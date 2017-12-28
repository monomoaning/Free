#pragma once
#include<string>
#include<vector>
#include<queue>
class graph {
public:
	graph(int);
	void print();
	void setUnvisited();
	void DFS(int);
	void DFS();
	void BFS(std::queue<std::vector<int>>);
	void BFS();
	int Dijskra(int);
	int Floyd(int i,int j);
private:
	std::vector<std::vector<int>>matrix;
	std::vector<int>vertex;
	std::vector<int>visited;
};