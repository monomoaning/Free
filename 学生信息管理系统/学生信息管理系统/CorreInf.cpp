#include"DefineStudent.h"
#include<iostream>
#include<iomanip>
using namespace std;
NODE CorreInf(NODE head) {//��Ϣ�޸ĺ���
	if (head == NULL) {
		cout << "�㻹δ������Ϣ ����¼����Ϣ" << endl;
		system("pause");
		return head;
	}

	cout << "���Ȳ�����Ҫ�޸ĵ�ѧ��������" << endl;
	NODE p1, p2=NULL;
	p1 = head;
	char name[20];
	cin >> name;
	while (p1 != NULL) {
		if (strcmp(name, p1->name) == 0) {
			cout << "����           ѧ��           ����Ա         �༶          �ɼ�" << endl;
			cout << setiosflags(ios::left) << setw(15) << p1->name << setw(15) << p1->StuNum << setw(15) << p1->StuTeacher << setw(15) << p1->ClassNum << setw(10) << p1->score << endl;
			p2 = p1;
		}
		p1 = p1->next;
	}
	cout << "�������޸ĵ���Ϣ" << endl;
	cout << "����           ѧ��           ����Ա         �༶          �ɼ�" << endl;
	cin >> p2->name >> p2->StuNum >> p2->StuTeacher >> p2->ClassNum >> p2->score;
	cout << "��Ϣ�޸ĳɹ�" << endl;
	system("pause");
	return head;
}