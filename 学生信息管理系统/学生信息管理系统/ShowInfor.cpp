#include"DefineStudent.h"
#include<iomanip>
#include<iostream>
using namespace std;
void ShowInfor(NODE head) {
	if (head == NULL) {
		cout << "�㻹δ������Ϣ ����¼����Ϣ" << endl;
		system("pause");
		return;
	}
 		NODE p = head;
	cout << "����           ѧ��           ����Ա         �༶          �ɼ�" << endl;
	while (p != NULL) {
		cout << setiosflags(ios::left) << setw(15) << p->name << setw(15) << p->StuNum << setw(15) << p->StuTeacher << setw(15) << p->ClassNum << setw(10) << p->score << endl;
		p = p->next;
	}
	system("pause");
}