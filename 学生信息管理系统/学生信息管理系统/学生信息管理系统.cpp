#include<iostream>
#include"DefineStudent.h"
using namespace std;
char filename[20]="studentfile.txt";//定义文件名
NODE head;//定义全局头节点
void main() {
	Logon();//学生登陆函数
	int point;//定义目录选择数字
	while (1) {
		selet_menu();//目录系统5
		cout << "请输入目录序号:" << endl;
		cin >> point;
		system("cls");
		switch (point) {
		case 1: {
			GetInfor(); 
			break;
		}
		case 2: {
			ShowInfor(head);
			break; 
		}
		case 3: {
			InfSeek(head);
			break;
		}
		case 4: {
			AddInf(head);
			break;
		}
		case 5: {
			CorreInf(head);
			break;
		}
		case 6: {
			DeleteInf();
			break;
		}
		case 7: {
			SaveInf(head);
				break;
		}
		case 8: {
			SaveInf(head);
			system("cls");
			DeleteNode(head);
			system("cls");
			cout << "谢谢使用！" << endl;
			system("pause");
			exit(0);
		}
		case 9: {
			
			break;
		}
		default: {
			cout << "请输入正确序号" << endl;
			system("pause");
			break;
		}
		}
		}
}


