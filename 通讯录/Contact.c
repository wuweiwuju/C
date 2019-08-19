#include"Contact.h"

void InitContact(contact* pcon)
{
	assert(pcon);
	pcon->size = 0;
	memset(pcon->data, 0, sizeof(pcon->data));
}
void AddContact(contact* pcon)
{
	assert(pcon);
	if (pcon->size == MAX)
	{
		printf("内存已满，请删除无用的联系人之后再加\n");
		return;
	}
	printf("请输入姓名:>\n");
	scanf("%s", pcon->data[pcon->size].name);
	printf("请输入年龄:>\n");
	scanf("%d", &(pcon->data[pcon->size].age));
	printf("请输入性别:>\n");
	scanf("%s", pcon->data[pcon->size].sex);
	printf("请输入地址:>\n");
	scanf("%s", pcon->data[pcon->size].addr);
	printf("请输入电话:>\n");
	scanf("%s", pcon->data[pcon->size].tele);
	pcon->size++;
	printf("添加成功\n");
}
int FindContact(contact* pcon,char name[])
{
	int i = 0;
	for (i = 0; i < pcon->size; i++)
	{
		if (strcmp(pcon->data[i].name,name) == 0)
			return i;
	}
	return -1;
}
void DelContact(contact* pcon)
{
	assert(pcon);
	if (pcon->size == 0)
	{
		printf("没有你要删除的联系人！\n");
		return;
	}
	int i = 0;
	int pos = 0;
	char name[NAME_MAX] = {0};
	printf("请输入你要删除人的姓名:>\n");
	scanf("%s", name);
	pos = FindContact(pcon,name);
	if (pos == -1)
	{
		printf("没有找到你要删除的人\n");
		return;
	}
	for (i = pos; i < pcon->size - 1; i++)
	{
		pcon->data[i] = pcon->data[i + 1];
	}
	pcon->size--;
	printf("删除成功！\n");
}
void ShowContact(contact* pcon)
{
	assert(pcon);
	if (pcon->size == 0)
		return;
	int i = 0;
	printf("%10s\t%5s\t%5s\t%15s\t%15s\t\n", "姓名", "年龄", "性别", "地址", "电话");
	for (i = 0; i < pcon->size; i++)
	{
		printf("%10s\t%5d\t%5s\t%15s\t%15s\t\n",
			pcon->data->name,
			pcon->data->age,
			pcon->data->sex,
			pcon->data->addr,
			pcon->data->tele);
	}
}
void SearchContact(contact* pcon)
{
	assert(pcon);
	if (pcon->size == 0)
		return;
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	printf("请输入你要查找的人的姓名:>\n");
	scanf("%s", name);
	pos = FindContact(pcon, name);
	if (pos == -1)
	{
		printf("没有找到你要找的人\n");
		return;
	}
	printf("%10s\t%5s\t%5s\t%15s\t%15s\t\n", "姓名", "年龄", "性别", "地址", "电话");
	printf("%10s\t%5d\t%5s\t%15s\t%15s\t\n",
		pcon->data[pos].name,
		pcon->data[pos].age,
		pcon->data[pos].sex,
		pcon->data[pos].addr,
		pcon->data[pos].tele);
}
void ClearContact(contact* pcon)
{
	assert(pcon);
	pcon->size = 0;
}
void ModifyContact(contact* pcon)
{
	assert(pcon);
	if (pcon->size == 0)
		return;
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	printf("请输入你要查找的人的姓名:>\n");
	scanf("%s", name);
	pos = FindContact(pcon, name);
	if (pos == -1)
	{
		printf("没有找到你要找的人\n");
		return;
	}
	printf("请输入修改后的姓名:>\n");
	scanf("%s", pcon->data[pos].name);
	printf("请输入修改后的年龄:>\n");
	scanf("%d", &(pcon->data[pos].age));
	printf("请输入修改后的性别:>\n");
	scanf("%s", pcon->data[pos].sex);
	printf("请输入修改后的地址:>\n");
	scanf("%s", pcon->data[pos].addr);
	printf("请输入修改后的电话:>\n");
	scanf("%s", pcon->data[pos].tele);
}
void SortContact(contact* pcon)
{
	assert(pcon);
	if (pcon->size == 0)
		return;
}