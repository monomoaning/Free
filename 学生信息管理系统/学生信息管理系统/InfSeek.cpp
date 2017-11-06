#include<iostream>
#include<iomanip>
#include"DefineStudent.h"
using namespace std;
void InfSeek(NODE head) {//信息查询
	if (head == NULL) {
		cout << "信息还未录入！请录入信息！" << endl;
		system("pause");
		return;
	}
	cout << "          1.姓名查询      2.学号查询 " << endl;/*不同的查询方式*/
	cout << "          3.班级查询      4.老师查询" << endl;
	cout << "请输入查询方式:" << endl;
	int seeknum;
	cin >> seeknum;
	switch (seeknum) {
	case 1: {//按姓名查找
		system("cls");
		cout << "请输入要查询学生的姓名：" << endl;
		char name[20];
		cin >> name;
		NODE p=head;
		bool a = true;
		while (p != NULL) {
			if (strcmp(name, p->name) == 0) {
				cout << "姓名           学号           辅导员         班级          成绩" << endl;
				cout << setiosflags(ios::left) << setw(15) << p->name << setw(15) << p->StuNum << setw(15) << p->StuTeacher << setw(15) << p->ClassNum << setw(10) << p->score << endl;
				a = false;
			}
			p = p->next;
		}
		if (a) {
			cout << "未找到该学生  请确认信息是否正确" << endl;
		}
		break;
	}
	case 2: {//学号查询
		system("cls");
		cout << "请输入你要查询学生的学号:" << endl;
		char num[20];
		cin >> num;
		NODE p = head;
		bool a = true;
		while (p != NULL) {
			if (strcmp(num, p->StuNum) == 0) {
				cout << "姓名           学号           辅导员         班级          成绩" << endl;
				cout << setiosflags(ios::left) << setw(15) << p->name << setw(15) << p->StuNum << setw(15) << p->StuTeacher << setw(15) << p->ClassNum << setw(10) << p->score << endl;
				a = false;
			}
			p = p->next;
		}
		if (a) {
			cout << "未找到该学生  请确认信息是否正确" << endl;
		}
		break;
	}
	case 3: {//班级查询
		system("cls");
		cout << "请输入你要查询的学生班级:" << endl;
		int num;
		cin >> num;
		NODE p = head;
		bool a = true;
		while (p != NULL) {
			if (num==p->ClassNum) {
				if (a) {
					cout << "姓名           学号           辅导员         班级          成绩" << endl;
				}
				cout << setiosflags(ios::left) << setw(15) << p->name << setw(15) << p->StuNum << setw(15) << p->StuTeacher << setw(15) << p->ClassNum << setw(10) << p->score << endl;
				a = false;
			}
			p = p->next;
		}
		if (a) {
			cout << "未找到该班级学生  请确认信息是否正确" << endl;
		}
		break;
	}
	case 4: {//老师查询
		system("cls");
		cout << "请输入老师名字:" << endl;
		char name[20];
		cin >> name;
		NODE p = head;
		bool a = true;
		while (p != NULL) {
			if (strcmp(name, p->StuTeacher) == 0) {
				if (a) {
					cout << "姓名           学号           辅导员         班级          成绩" << endl;
				}
				cout << setiosflags(ios::left) << setw(15) << p->name << setw(15) << p->StuNum << setw(15) << p->StuTeacher << setw(15) << p->ClassNum << setw(10) << p->score << endl;
				a = false;
			}
			p = p->next;
		}
		if (a) {
			cout << "未找到该老师学生" << endl;
		}
		break;
	}
	}
	system("pause");
	system("cls");
	char a;
	cout << "是否继续查询(Y/N)" << endl;
	cin >> a;
	if (a=='y'|| a == 'Y') {
		InfSeek(head);
	}
}
