#include"DefineStudent.h"
#include<iostream>
using namespace std;
void DeleteNode(NODE &head) {//����ɾ������
	if (head == NULL) {
		cout << "�ļ�ɾ���ɹ�" << endl;
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
	cout << "��Ϣɾ���ɹ�" << endl;
}