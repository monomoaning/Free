#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__
#include <string>

class hashtable {
public:
	hashtable();
	int hash(const std::string &);
	static const unsigned size = 5000;
	struct item {
		item()=default;
		std::string name;
		struct item *next=nullptr;
	};
	void addItem(const std::string &);
	void addItemFromFile(const std::string &);
	void print();
	void deleteItem(const std::string &);
private:
	bool exist(const std::string &);
	item * *table=nullptr;
};
#endif // !__HASHTABLE_H__