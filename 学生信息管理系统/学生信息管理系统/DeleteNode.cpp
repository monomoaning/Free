#include"DefineStudent.h"
#include<iostream>
using namespace std;
void DeleteNode(NODE &head) {//链表删除函数
	if (head == NULL) {
		cout << "文件删除成功" << endl;
		return;
	}
	NODE p1, p2;
	p1 = head;
	while (p1 != NULL) {
		p2 = p1->next;
		delete p1;
		p1 = p2;
	}
	p1 = p2 = head = NULL;
	cout << "信息删除成功" << endl;
}