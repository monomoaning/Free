#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
template<typename T>
class LinkedList {
public:

	template<typename U>
	friend std::ostream& operator<<(std::ostream&os, LinkedList<U>);

	LinkedList() = default;
	explicit LinkedList(T data) :head(new ListNode<T>(data)), tail(head), size(1) {};
	bool empty()const {
		return size == 0;
	}
	bool search(T data) {
		auto p = head;
		while (p&&p->data != data)
			p = p->next;
		return p != nullptr;
	}
	void order() {			//冒泡链表排序
		for (auto p = head; p!=tail; p = p->next) {
			auto t = p->next;
			while (t != tail->next) {
				if (t->data < p->data) {
					auto c = p->data;
					p->data = t->data;
					t->data = c;
				}
				t = t->next;
			}
		}
	}
	void push_back(T data);
	void push_front(T data);
	void pop_back();
	void pop_front();
	void insert(T arg = T());
	void insert(T data, T arg=T());
private:

	template<typename T>
	class ListNode {
	public:
		template<typename U>
		friend std::ostream &operator<<(std::ostream &os, LinkedList<U>);
		friend class LinkedList<T>;
		explicit ListNode(T _data) :data(_data), next(nullptr) {};
	private:
		T data;
		ListNode *next;
	};

	ListNode<T> *head=nullptr;
	ListNode<T> *tail=nullptr;
	std::size_t size=0;
};

template<typename T>
void LinkedList<T>::push_back(T data) {
	if (empty()) {
		head = new ListNode<T>(data);
		tail = head;
		size++;
	}
	else {
		tail->next = new ListNode<T>(data);
		tail = tail->next;
		size++;
	}
}

template<typename T>
void LinkedList<T>::push_front(T data) {
	if (empty()) {
		head = new ListNode<T>(data);
		tail = head;
		size++;
	}
	else {
		auto p = new ListNode<T>(data);
		p->next = head;
		head = p;
		p = nullptr;
		size++;
	}
}

template<typename T>
void LinkedList<T>::pop_back() {
	if (empty())
		return;
	auto p = head;
	while (p->next != tail)
		p = p->next;
	delete tail;
	tail = p;
	tail->next = nullptr;
	size--;
	p = nullptr;
}

template<typename T>
void LinkedList<T>::pop_front() {
	if (empty())
		return;
	auto p = head;
	head = head->next;
	delete p;
	p = nullptr;
	size--;
}

template<typename T>
void LinkedList<T>::insert(T arg) {
	push_back(arg);
	size++;
}

template<typename T>
void LinkedList<T>::insert(T arg, T data) {
	if (!search(arg)) {
		push_back(data);
		size++;
	}
	else {
		auto p = head;
		while (p->data != arg)
			p = p->next;
		auto temp = p->next;
		p->next = new ListNode<T>(data);
		p->next->next = temp;
		p = nullptr;
		size++;
	}
}
template<typename T>
inline std::ostream &operator<<(std::ostream &os, LinkedList<T> arg) {
	if (arg.empty())
		return os;
	auto p = arg.head;
	while (p) {
		os << p->data << ends;
		p = p->next;
	}
	return os;
}
#endif //!LINKEDLIST_H