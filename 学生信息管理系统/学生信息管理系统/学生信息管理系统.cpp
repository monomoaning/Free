#include<iostream>
#include"DefineStudent.h"
using namespace std;
char filename[20]="studentfile.txt";//�����ļ���
NODE head;//����ȫ��ͷ�ڵ�
void main() {
	Logon();//ѧ����½����
	int point;//����Ŀ¼ѡ������
	while (1) {
		selet_menu();//Ŀ¼ϵͳ5
		cout << "������Ŀ¼���:" << endl;
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
			cout << "ллʹ�ã�" << endl;
			system("pause");
			exit(0);
		}
		case 9: {
			
			break;
		}
		default: {
			cout << "��������ȷ���" << endl;
			system("pause");
			break;
		}
		}
		}
}


