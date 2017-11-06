#include"DefineStudent.h"
#include<iostream>
using namespace std;
NODE GetInfor() {
	cout << "                   1.文件读取               2.手动录入" << endl;
	int a;
	cin >> a;
	if (a == 1) {
		system("cls");
		ReadFile();
	}
	else {
		if (head != NULL) {
			cout << "信息已存在！请选择其他功能！" << endl;
			system("pause");
			return head;
		}
		system("cls");
		char stop = 'Y';
		NODE p1, p2;
		p1 = new STUDENT;
		head = p2 = p1;
		cout << "请输入学生的姓名     学号       辅导员       班级    成绩（中间用空格隔开）" << endl;
		cout << "                ";
		cin >> p2->name >> p2->StuNum >> p2->StuTeacher >> p2->ClassNum >> p2->score;
		system("cls");
		for (; stop == 'y' || stop == 'Y';) {
			p1 = new STUDENT;
			p2->next = p1;
			p2 = p1;
			cout << "请输入学生的姓名      学号      辅导员      班级     成绩（中间用空格隔开）" << endl;
			cout << "                ";
			cin >> p2->name >> p2->StuNum >> p2->StuTeacher >> p2->ClassNum >> p2->score;
			cout << "是否继续输入信息(Y/N)" << endl;
			cin >> stop;
			system("cls");
		}
		p2->next = NULL;
		p1 = NULL;
	}
	cout << "信息录入成功！" << endl;
	system("pause");
	return head;
}