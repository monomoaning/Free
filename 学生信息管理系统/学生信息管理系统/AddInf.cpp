#include"DefineStudent.h"
#include<iostream>
using namespace std;
NODE AddInf(NODE head) {//��Ϣ��Ӻ���
	if (head == NULL) {
		cout << "�㻹δ������Ϣ ����¼����Ϣ" << endl;
		system("pause");
		return head;
	}
	NODE p3=NULL,p4=head;
	while (p4 != NULL) {
		p3 = p4;
		p4 = p4->next;
	}
	NODE p1, p2;
	p2 = p3;
	p1 = new STUDENT;
	p2->next = p1;
	p2 = p1;
	p2->next = NULL;
	cout << "�����������ѧ��������     ѧ��       ����Ա       �༶    �ɼ����м��ÿո������" << endl;
	cout << "                ";
	cin >> p2->name >> p2->StuNum >> p2->StuTeacher >> p2->ClassNum >> p2->score;
	p1 = NULL;
	cout << "��Ϣ��ӳɹ�" << endl;
	cout << "�Ƿ񼰼������(Y/N)" << endl;
	char a;
	cin >> a;
	if (a == 'y' || a == 'Y')
	{
		system("cls");
		AddInf(head);
	}
	return head;
}