#include<iostream>
#include<cstdlib>
#include<fstream>
#include<limits>
#include<iomanip>
#include<stack>
#include<algorithm>
#include"Graph.h"
graph::graph(int dimension) {
	matrix.assign(dimension, {});
	for (auto &t : matrix)
		t.assign(dimension, INT_MAX);
	visited.assign(dimension, 0);
	for (int i = 0; i < dimension; ++i) {
		for (int j = 0; j < dimension; ++j) {
			if (i == j)
				continue;
			if (rand() % 2) {
				matrix[i][j] = rand() % 2039 + 4;
				matrix[j][i] = matrix[i][j];
			}
		}
	}
	vertex.assign(dimension, ' ');
	for (auto &t : vertex)
		t = rand()%100+20;
}

void graph::print() {
	std::fstream out;
	out.open("graph.txt", std::ios::out);
	std::cout << "图的顶点是:" << std::endl;
	out << "图的顶点是:" << std::endl;
	for (auto t : vertex) {
		std::cout << std::setw(4) << std::setiosflags(std::ios::left) << t << std::ends;
		out << std::setw(4) << std::setiosflags(std::ios::left) << t << std::ends;
	}
	std::cout << std::endl;
	out << std::endl;
	std::cout << "图的邻接矩阵是:" << std::endl;
	out << "图的邻接矩阵是:" << std::endl;
	for (auto p : matrix) {
		for (auto t : p) {
			std::cout << std::setw(15) << std::setiosflags(std::ios::left) << t << std::ends;
			out << std::setw(15) << std::setiosflags(std::ios::left) << t << std::ends;
		}
		std::cout << std::endl;
		out << std::endl;
	}
}

void graph::setUnvisited() {
	for (auto &t : visited)
		t = 0;
}

void graph::DFS(int index) {
	if (visited[index] == 0)
		std::cout << vertex[index] << std::ends;
	visited[index] = 1;
	for (int i = 0; i < visited.size(); ++i) {
		if (matrix[index][i] != INT_MAX && visited[i] == 0)
			DFS(i);
	}
}

void graph::DFS() {
	std::stack<int>index;
	index.push(0);
	while (!index.empty()) {
		auto t = index.top();
		index.pop();
		if (visited[t] == 0) {
			std::cout << vertex[t] << std::ends;
			visited[t] = 1;
		}
		for (int i = visited.size()-1; i >=0; --i)
			if (matrix[t][i] != INT_MAX&&visited[i]==0)
				index.push(i);
	}
}

void  graph::BFS(std::queue<std::vector<int>> index) {
	if (index.front().empty())
		return;
	auto p = index.front();
	index.pop();
	std::vector<int>temp;
	for (auto t : p) {
		if (visited[t] == 0) {
			std::cout << vertex[t] << std::ends;
			visited[t] = 1;
		}
		for (int i = 0; i < visited.size(); ++i)
			if (matrix[t][i] != INT_MAX && visited[i] == 0)
				temp.push_back(i);
	}
	index.push(temp);
	BFS(index);
}

void graph::BFS() {
	std::queue<int>index;
	index.push(0);
	while (!index.empty()) {
		auto t = index.front();
		index.pop();
		if (visited[t] == 0) {
			std::cout << vertex[t] << std::ends;
			visited[t] = 1;
		}
		for (int i = 0; i < visited.size(); ++i) {
			if (matrix[t][i] != INT_MAX && visited[i] == 0)
				index.push(i);
		}
	}
}

/*
	由于该图出现的随机性，该算法出现错误
	比如该图无法一次性走完，即没有单一路径
*/
int graph::Dijskra(int index) {
	std::vector<int>v;//保存已访问node
	std::vector<int>u;//保存未访问node
	for (auto i = 0; i < vertex.size(); ++i)
		u.push_back(i);
	v.push_back(index);
	auto p = std::find(u.begin(), u.end(), index);
	u.erase(p);
	int weight = 0;
	/*将开始结点和未访问节点分开存储*/
	while (v.size() != vertex.size()) {
		std::vector<int>temp;  //存储相邻节点
		auto p = *v.rbegin();
		visited[p] = 1;
		for (int i = 0; i < u.size(); ++i) {
			if (matrix[p][u[i]] != INT_MAX&&visited[u[i]]==0)
				temp.push_back(u[i]);
		}
		int a=weight + matrix[p][*temp.begin()];
		decltype(v.begin())q=temp.begin();  //找到最小权的相邻节点
		for (auto j = ++temp.begin(); j != temp.end(); ++j)
			if (weight + matrix[p][*j] <= a) {
				q = j;
				a = weight + matrix[p][*q];
			}
		weight += matrix[p][*q];
		v.push_back(*q);
		auto g = std::find(u.begin(), u.end(), *q);
		u.erase(g);
	}
	std::cout << "路径:" << std::endl;
	for (auto t : v)
		std::cout << t << std::ends;
	std::cout << std::endl;
	return weight;
}
//第q个和第w个顶点
int graph::Floyd(int q,int w) {
	std::vector<std::vector<int>>A;
	std::vector<std::vector<int>>path;
	A.assign(vertex.size(), {});
	path.assign(vertex.size(), {});
	for (auto &t : A)
		t.assign(vertex.size(), 0);
	for (auto &t : path)
		t.assign(vertex.size(), 0);
	int i, j, k, n = vertex.size();
		for (i = 0; i<n; i++)
		for (j = 0; j<n; j++){
			A[i][j] = matrix[i][j];
			path[i][j] = -1;
		}
	for (k = 0; k<n; k++){
		for (i = 0; i<n; i++)
			for (j = 0; j<n; j++)
				if (A[i][j]>(A[i][k] + A[k][j])){
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = k;
				}
	}
	return path[q][w];
}
