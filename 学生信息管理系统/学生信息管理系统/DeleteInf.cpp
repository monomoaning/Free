#include"DefineStudent.h"
#include<iostream>
#include<iomanip>
using namespace std;
void DeleteInf() {//��Ϣɾ������
	if (head == NULL) {
		cout << "�㻹δ������Ϣ ����¼����Ϣ" << endl;
		system("pause");
		return ;
	}
	cout << "             1.ȫ��ɾ��              2.����ɾ��" << endl;
	int a;
	cin >> a;
	if (a == 1) {
		DeleteNode(head);
	}
	else {
		cout << "���Ȳ�����Ҫɾ����ѧ��������" << endl;
		NODE p1, p2 = NULL, p3 = NULL;
		p1 = head;
		char name[20];
		cin >> name;
		if (strcmp(name, p1->name) == 0) {//ɾ��ͷ�ڵ�
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
	cout << "��Ϣɾ���ɹ�" << endl;
	system("pause");
}