#include"DefineStudent.h"
#include<iostream>
using namespace std;
NODE AddInf(NODE head) {//信息添加函数
	if (head == NULL) {
		cout << "你还未输入信息 请先录入信息" << endl;
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
	cout << "请输入需添加学生的姓名     学号       辅导员       班级    成绩（中间用空格隔开）" << endl;
	cout << "                ";
	cin >> p2->name >> p2->StuNum >> p2->StuTeacher >> p2->ClassNum >> p2->score;
	p1 = NULL;
	cout << "信息添加成功" << endl;
	cout << "是否及继续添加(Y/N)" << endl;
	char a;
	cin >> a;
	if (a == 'y' || a == 'Y')
	{
		system("cls");
		AddInf(head);
	}
	return head;
}