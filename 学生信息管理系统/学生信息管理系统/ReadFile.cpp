#include"DefineStudent.h"
#include<iostream>
using namespace std;
NODE ReadFile() {
	if (head != NULL) {
		cout << "��Ϣ���ᱻ����" << endl;
		system("pause");
	}
	FILE *fp;
	if ((fp = fopen(filename, "rb")) == NULL) {
		cout << "�ļ���ʧ��" << endl;
		return NULL;
	}
	fseek(fp, 0, SEEK_END);
	if (ftell(fp) == 0) {
		cout << "�ļ���û��Ϣ" << endl;
		return NULL;
	}
	else {
		rewind(fp);
		NODE p1, p2 = NULL;
		head = new STUDENT;
		p2 = head;
		while (!feof(fp)) {
			p1 = new STUDENT;
			fread(p1, SIZE, 1, fp);
			p2->next = p1;
			p2 = p1;
			p2->next = NULL;
		}
		p1 = NULL;
		NODE p4 = head, p5;
		head = head->next;
		delete p4;
		p4 = head;
		p5 = p4->next;
		while (p5->next != NULL) {
			p5 = p5->next;
			p4 = p4->next;
		}
		delete p5;
		p4->next = NULL;
		p5 = NULL;
		cout << "�ļ���ȡ�ɹ�" << endl;
		system("pause");
		return head;
	}
}