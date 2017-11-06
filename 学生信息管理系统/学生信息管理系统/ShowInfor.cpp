#include"DefineStudent.h"
#include<iomanip>
#include<iostream>
using namespace std;
void ShowInfor(NODE head) {
	if (head == NULL) {
		cout << "你还未输入信息 请先录入信息" << endl;
		system("pause");
		return;
	}
 		NODE p = head;
	cout << "姓名           学号           辅导员         班级          成绩" << endl;
	while (p != NULL) {
		cout << setiosflags(ios::left) << setw(15) << p->name << setw(15) << p->StuNum << setw(15) << p->StuTeacher << setw(15) << p->ClassNum << setw(10) << p->score << endl;
		p = p->next;
	}
	system("pause");
}