#include"DefineStudent.h"
#include<iostream>
using namespace std;
NODE GetInfor() {
	cout << "                   1.�ļ���ȡ               2.�ֶ�¼��" << endl;
	int a;
	cin >> a;
	if (a == 1) {
		system("cls");
		ReadFile();
	}
	else {
		if (head != NULL) {
			cout << "��Ϣ�Ѵ��ڣ���ѡ���������ܣ�" << endl;
			system("pause");
			return head;
		}
		system("cls");
		char stop = 'Y';
		NODE p1, p2;
		p1 = new STUDENT;
		head = p2 = p1;
		cout << "������ѧ��������     ѧ��       ����Ա       �༶    �ɼ����м��ÿո������" << endl;
		cout << "                ";
		cin >> p2->name >> p2->StuNum >> p2->StuTeacher >> p2->ClassNum >> p2->score;
		system("cls");
		for (; stop == 'y' || stop == 'Y';) {
			p1 = new STUDENT;
			p2->next = p1;
			p2 = p1;
			cout << "������ѧ��������      ѧ��      ����Ա      �༶     �ɼ����м��ÿո������" << endl;
			cout << "                ";
			cin >> p2->name >> p2->StuNum >> p2->StuTeacher >> p2->ClassNum >> p2->score;
			cout << "�Ƿ����������Ϣ(Y/N)" << endl;
			cin >> stop;
			system("cls");
		}
		p2->next = NULL;
		p1 = NULL;
	}
	cout << "��Ϣ¼��ɹ���" << endl;
	system("pause");
	return head;
}