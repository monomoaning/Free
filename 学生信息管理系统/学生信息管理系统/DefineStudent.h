#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SIZE (sizeof(STUDENT))
typedef struct student{
	char name[8];
	char StuNum[15];
	char StuTeacher[7];
	int ClassNum;
	int score;
	struct student *next;
}STUDENT, *NODE;//ѧ���ṹ������
void selet_menu();//Ŀ¼ѡ����
extern NODE head;//ͷ�ڵ�����
extern char filename[20];//�����ļ�����
void Logon();//��½��������
NODE GetInfor();//��Ϣ¼�뺯��
void ShowInfor(NODE);//������Ϣ�������
void InfSeek(NODE head);//��Ϣ��ѯϵͳ
NODE AddInf(NODE head);//��Ϣ��Ӻ���
NODE CorreInf(NODE head);//��Ϣ�޸ĺ���
void DeleteInf();//��Ϣɾ������
void DeleteNode(NODE &head);//����ɾ������
void SaveInf(NODE head);//�ļ�����
NODE ReadFile();//�ļ���ȡ