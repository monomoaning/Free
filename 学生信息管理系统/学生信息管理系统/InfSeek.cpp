#include<iostream>
#include<iomanip>
#include"DefineStudent.h"
using namespace std;
void InfSeek(NODE head) {//��Ϣ��ѯ
	if (head == NULL) {
		cout << "��Ϣ��δ¼�룡��¼����Ϣ��" << endl;
		system("pause");
		return;
	}
	cout << "          1.������ѯ      2.ѧ�Ų�ѯ " << endl;/*��ͬ�Ĳ�ѯ��ʽ*/
	cout << "          3.�༶��ѯ      4.��ʦ��ѯ" << endl;
	cout << "�������ѯ��ʽ:" << endl;
	int seeknum;
	cin >> seeknum;
	switch (seeknum) {
	case 1: {//����������
		system("cls");
		cout << "������Ҫ��ѯѧ����������" << endl;
		char name[20];
		cin >> name;
		NODE p=head;
		bool a = true;
		while (p != NULL) {
			if (strcmp(name, p->name) == 0) {
				cout << "����           ѧ��           ����Ա         �༶          �ɼ�" << endl;
				cout << setiosflags(ios::left) << setw(15) << p->name << setw(15) << p->StuNum << setw(15) << p->StuTeacher << setw(15) << p->ClassNum << setw(10) << p->score << endl;
				a = false;
			}
			p = p->next;
		}
		if (a) {
			cout << "δ�ҵ���ѧ��  ��ȷ����Ϣ�Ƿ���ȷ" << endl;
		}
		break;
	}
	case 2: {//ѧ�Ų�ѯ
		system("cls");
		cout << "��������Ҫ��ѯѧ����ѧ��:" << endl;
		char num[20];
		cin >> num;
		NODE p = head;
		bool a = true;
		while (p != NULL) {
			if (strcmp(num, p->StuNum) == 0) {
				cout << "����           ѧ��           ����Ա         �༶          �ɼ�" << endl;
				cout << setiosflags(ios::left) << setw(15) << p->name << setw(15) << p->StuNum << setw(15) << p->StuTeacher << setw(15) << p->ClassNum << setw(10) << p->score << endl;
				a = false;
			}
			p = p->next;
		}
		if (a) {
			cout << "δ�ҵ���ѧ��  ��ȷ����Ϣ�Ƿ���ȷ" << endl;
		}
		break;
	}
	case 3: {//�༶��ѯ
		system("cls");
		cout << "��������Ҫ��ѯ��ѧ���༶:" << endl;
		int num;
		cin >> num;
		NODE p = head;
		bool a = true;
		while (p != NULL) {
			if (num==p->ClassNum) {
				if (a) {
					cout << "����           ѧ��           ����Ա         �༶          �ɼ�" << endl;
				}
				cout << setiosflags(ios::left) << setw(15) << p->name << setw(15) << p->StuNum << setw(15) << p->StuTeacher << setw(15) << p->ClassNum << setw(10) << p->score << endl;
				a = false;
			}
			p = p->next;
		}
		if (a) {
			cout << "δ�ҵ��ð༶ѧ��  ��ȷ����Ϣ�Ƿ���ȷ" << endl;
		}
		break;
	}
	case 4: {//��ʦ��ѯ
		system("cls");
		cout << "��������ʦ����:" << endl;
		char name[20];
		cin >> name;
		NODE p = head;
		bool a = true;
		while (p != NULL) {
			if (strcmp(name, p->StuTeacher) == 0) {
				if (a) {
					cout << "����           ѧ��           ����Ա         �༶          �ɼ�" << endl;
				}
				cout << setiosflags(ios::left) << setw(15) << p->name << setw(15) << p->StuNum << setw(15) << p->StuTeacher << setw(15) << p->ClassNum << setw(10) << p->score << endl;
				a = false;
			}
			p = p->next;
		}
		if (a) {
			cout << "δ�ҵ�����ʦѧ��" << endl;
		}
		break;
	}
	}
	system("pause");
	system("cls");
	char a;
	cout << "�Ƿ������ѯ(Y/N)" << endl;
	cin >> a;
	if (a=='y'|| a == 'Y') {
		InfSeek(head);
	}
}
