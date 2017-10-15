#ifndef FAREY_H
#define FAREY_H
#include"LinkedList.h"
#include<iostream>
class farey {
public:
	farey() :head(new node(0, 1)), tail(new node(1,1)) {
		head->next = tail;
		size += 2;
	}
	void add(int n) {
		try {
			if (n < size)
				throw std::out_of_range("the size");
			for (int i = 2; i < n; ++i) {
				auto p = head;
				while (p != tail) {
					if (p->second + p->next->second <= i) {
						auto temp = new node(p->first + p->next->first, p->second + p->next->second);
						temp->next = p->next;
						p->next = temp;
						p = temp->next;
					}
					else
						p = p->next;
				}
			}
		}
		catch (...) {
			std::cout << "the range is overflow" << std::endl;
		}
	}
	void print() {
		auto p = head;
		while (p != tail) {
			std::cout << p->first << "/" << p->second << std::ends;
			p = p->next;
		}
		std::cout << p->first << "/" << p->second << std::endl;
	}
private:
	class node {
	public:
		int first, second;
		node*next;
		node() :next(nullptr) {}
		node(int _arg1, int _arg2) :first(_arg1), second(_arg2), next(nullptr) {}
	};
	node *head;
	node *tail;
	std::size_t size;
};
#endif//!FAREY_h