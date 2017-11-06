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
}STUDENT, *NODE;//学生结构体声明
void selet_menu();//目录选择函数
extern NODE head;//头节点声明
extern char filename[20];//声明文件名称
void Logon();//登陆函数声明
NODE GetInfor();//信息录入函数
void ShowInfor(NODE);//声明信息输出函数
void InfSeek(NODE head);//信息查询系统
NODE AddInf(NODE head);//信息添加函数
NODE CorreInf(NODE head);//信息修改函数
void DeleteInf();//信息删除函数
void DeleteNode(NODE &head);//链表删除函数
void SaveInf(NODE head);//文件保存
NODE ReadFile();//文件读取