#include "hashtable.h"
#include <fstream>
#include <sstream>
#include <iostream>

hashtable::hashtable() {
	table = new item*[size] {};
}

/*the hash function for geneting the hashcode*/
int hashtable::hash(const std::string & arg) {
	unsigned t = 0,remander=0;
	for (int i = 0; i < arg.size(); i += 4) {
		if (i + 4 < arg.size()) {
			t = (static_cast<unsigned>(arg[i]) << 8) + (static_cast<unsigned>(arg[i + 1])<<4)
				+(static_cast<unsigned>(arg[i+2])<<2)+static_cast<unsigned>(arg[i+3]);
			remander ^= t;
		}
		else {
			for (auto j = i; j < arg.size(); ++j)
				t = (static_cast<unsigned>(arg[j] << 2));
			remander ^= t;
		}
	}
	return remander % size;
}

/*check  existence*/
bool hashtable::exist(const std::string & arg) {
	int index = hash(arg);
	auto p = table[index];
	while (p&&p->name != arg) {
		if (p != nullptr)
			p = p->next;
	}
	return !(p == nullptr);
}

/*the add item function*/
void hashtable::addItem(const std::string & arg) {
	if (exist(arg))
		return;
	auto index = hash(arg);
	if (table[index] == nullptr) {
		table[index] = new item;
		table[index]->name = arg;
	}
	else {
		auto p = table[index];
		while (p->next != nullptr)
			p = p->next;
		p->next = new item;
		p->next->name = arg;
	}
}

/*read the file and add the items into the table*/
void hashtable::addItemFromFile(const std::string &filename) {
	std::fstream in;
	in.open(filename.c_str(), std::ios::in);
	if (in.fail()) 
		return;
	std::string temp;
	while (getline(in, temp)) {
		std::istringstream is(temp);
		while (is >> temp)
			addItem(temp);
	}
	in.close();
}

/*print all the items in the table*/
void hashtable::print() {
	for (int i = 0; i < size; ++i) {
		if (table[i] != nullptr) {
			std::cout << "µÚ" << i + 1 << "Ë÷Òý:" << std::ends;
			auto p = table[i];
			while (p != nullptr) {		
				std::cout <<"["<< p->name <<"]"<< std::ends;
				p = p->next;
			}
			std::cout << std::endl;
		}
	}
}

/*delete item from hashtable*/
void hashtable::deleteItem(const std::string &arg) {
	if (!exist(arg))
		return;
	auto index = hash(arg);
	auto ptr = table[index];
	if (ptr->name == arg) {
		auto t = ptr;
		table[index] = ptr->next;
		delete t;
		t = nullptr;
		ptr = nullptr;
	}
	else {
		auto t = ptr->next;
		while (t != nullptr) {
			if (t->name == arg) {
				ptr->next = t->next;
				delete t;
				t = nullptr;
			}
			t = t->next;
			ptr = t;
		}
	}
}
