#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __CONTACT_H__ 
#define __CONTACT_H__ 


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


#define MAX 1000 //ͨѶ¼���洢��

#define NAME_MAX 20//������󳤶� 
#define SEX_MAX 5 //�Ա�...
#define ADDR_MAX 30 //��ַ...
#define TELE_MAX 12 //�绰...

typedef struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int  age;
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
}PeoInfo;
//��̬��ͨѶ¼
//typedef struct contact
//{
//	PeoInfo data[MAX];
//	int size;
//}contact;
//��̬��ͨѶ¼
typedef struct contact
{
	PeoInfo* data;
	int size;
	int capacity;
}contact;
void InitContact(contact* pcon);
void AddContact(contact* pcon);
void DelContact(contact* pcon);
void ShowContact(const contact* pcon);
void SearchContact(const contact* pcon);
void ClearContact(contact* pcon);
void DestroyContact(contact* pcon);
int CheckContact(contact* pcon);
void ModifyContact(contact* pcon);
void SortContact(contact* pcon);

#endif