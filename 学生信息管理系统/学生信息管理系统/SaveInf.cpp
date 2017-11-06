#include"DefineStudent.h"
#include<iostream>
using namespace std;
void SaveInf(NODE head) {
	if (head == NULL) {
		cout << "无信息" << endl;
		system("pause");
		return;
	}
	FILE *fp;
	if ((fp = fopen(filename, "wb")) == NULL) {
		cout << "文件打开失败" << endl;
		return;
	}
	while (head != NULL) {
		fwrite(head, SIZE, 1, fp);
		head = head->next;
	}
	fflush(fp);
	fclose(fp);
	cout << "文件保存成功" << endl;
	system("pause");
}