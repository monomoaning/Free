#ifndef BINARYSEARCHTREE_H
#define BINARYSEARcHTREE_H
#include<queue>
#include<stack>
#include<iostream>
template<typename T>
class Stack :public std::stack<T> {
public:
	T pop() {
		try {
			if (empty())
				throw std::out_of_range("the stack is empty");
			else {
				auto temp = top();
				std::stack<T>::pop();
				return temp;
			}
		}
		catch (std::out_of_range &_error) {
			std::cout << _error.what() << std::endl;
			return T();
		}
	}
};

template<typename T>
class Qeque:public std::queue<T> {    //the queue for the breadth visit of binary tree
public:
	T pop() {
		try {
			if (empty())
				throw std::out_of_range("the deque adapter is empty");
			else {
				auto temp = front();
				std::queue<T>::pop();
				return temp;
			}
		}
		catch (std::out_of_range &_error) {
			std::cout << _error.what() << std::endl;
			return T();
		}
	}
};

template<typename T> 
class BinaryTree {
	template<typename T>
	class BinaryTreeNode {
	public:
		friend class BinaryTree<T>;
		BinaryTreeNode(const T &_data, BinaryTreeNode<T>*_left = nullptr, BinaryTreeNode<T>*_right = nullptr) :data(_data), left(_left), right(_right) {}

	private:
		T data;
		BinaryTreeNode<T> *left;
		BinaryTreeNode<T> *right;
	};
public:
	BinaryTree() = default;		//default construction
	explicit BinaryTree(const T &_data) :root(new BinaryTreeNode<T>(_data)), size(1) {}    //construction with parameter

	void push_back(const T &_data) {   //push the value to the back
		if (root == nullptr) {
			root = new BinaryTreeNode<T>(_data);
			size = 1;
			return;
		}
		BinaryTreeNode<T>* p = root, *temp{ nullptr };
		while (p != nullptr) {
			temp = p;
			if (_data < temp->data)
				p = p->left;
			if (_data > temp->data)
				p = p->right;
		}
		if (_data < temp->data)
			temp->left = new BinaryTreeNode<T>(_data);
		else
			temp->right = new BinaryTreeNode<T>(_data);
		temp=p = nullptr;
	}

	void BreadthVisit() {   //breadth first visit
		Qeque<BinaryTreeNode<T>*>_qeque;
		auto p = root;
		if (root == nullptr)
			return;
		_qeque.push(p);
		while (!_qeque.empty()) {
			p = _qeque.pop();
			visit(p);
			if (p->left != nullptr)
				_qeque.push(p->left);
			if (p->right != nullptr)
				_qeque.push(p->right);
		}
		std::cout << std::endl;
	}

	void ForwardVisit() {   //the preorder visit of binary tree without recursion
		Stack<BinaryTreeNode<T>*>_stack;
		auto p = root;
		if (p == nullptr)
			return;
		_stack.push(p);
		while (!_stack.empty()) {
			p = _stack.pop();
			visit(p);
			if (p->right != nullptr)
				_stack.push(p->right);
			if (p->left != nullptr)
				_stack.push(p->left);
		}
		std::cout << std::endl;
	}

	void ForwardVisit(BinaryTreeNode<T>* _arg) {
		if (_arg != nullptr) {
			visit(_arg);
			ForwardVisit(_arg->left);
			ForwardVisit(_arg->right);
		}
	}

private:


	BinaryTreeNode<T>* root=nullptr;
	std::size_t size=0;

	void visit(BinaryTreeNode<T> *_data) {    //the visit function
		std::cout << _data->data << std::ends;
	}
};
#endif//!BINARYSEARcHTREE_H