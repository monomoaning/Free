#include"DefineStudent.h"
#include<iostream>
#include<iomanip>
using namespace std;
void DeleteInf() {//信息删除函数
	if (head == NULL) {
		cout << "你还未输入信息 请先录入信息" << endl;
		system("pause");
		return ;
	}
	cout << "             1.全部删除              2.姓名删除" << endl;
	int a;
	cin >> a;
	if (a == 1) {
		DeleteNode(head);
	}
	else {
		cout << "请先查找你要删除的学生姓名：" << endl;
		NODE p1, p2 = NULL, p3 = NULL;
		p1 = head;
		char name[20];
		cin >> name;
		if (strcmp(name, p1->name) == 0) {//删除头节点
			head = head->next;
			delete p1;
			p1 = NULL;
		}
		else {
			while (p1 != NULL) {
				p2 = p1;
				p2 = p2->next;
				if (strcmp(name, p2->name) == 0) {
					p1->next = p2->next;
					delete p2;
					break;
				}
				p1 = p1->next;
			}
		}
		p3 = head;
	}
	cout << "信息删除成功" << endl;
	system("pause");
}