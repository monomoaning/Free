#include"DefineStudent.h"
#include<iostream>
using namespace std;
void SaveInf(NODE head) {
	if (head == NULL) {
		cout << "����Ϣ" << endl;
		system("pause");
		return;
	}
	FILE *fp;
	if ((fp = fopen(filename, "wb")) == NULL) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	while (head != NULL) {
		fwrite(head, SIZE, 1, fp);
		head = head->next;
	}
	fflush(fp);
	fclose(fp);
	cout << "�ļ�����ɹ�" << endl;
	system("pause");
}