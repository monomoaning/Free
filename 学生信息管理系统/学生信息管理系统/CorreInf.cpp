#include"DefineStudent.h"
#include<iostream>
#include<iomanip>
using namespace std;
NODE CorreInf(NODE head) {//信息修改函数
	if (head == NULL) {
		cout << "你还未输入信息 请先录入信息" << endl;
		system("pause");
		return head;
	}

	cout << "请先查找你要修改的学生姓名：" << endl;
	NODE p1, p2=NULL;
	p1 = head;
	char name[20];
	cin >> name;
	while (p1 != NULL) {
		if (strcmp(name, p1->name) == 0) {
			cout << "姓名           学号           辅导员         班级          成绩" << endl;
			cout << setiosflags(ios::left) << setw(15) << p1->name << setw(15) << p1->StuNum << setw(15) << p1->StuTeacher << setw(15) << p1->ClassNum << setw(10) << p1->score << endl;
			p2 = p1;
		}
		p1 = p1->next;
	}
	cout << "请输入修改的信息" << endl;
	cout << "姓名           学号           辅导员         班级          成绩" << endl;
	cin >> p2->name >> p2->StuNum >> p2->StuTeacher >> p2->ClassNum >> p2->score;
	cout << "信息修改成功" << endl;
	system("pause");
	return head;
}