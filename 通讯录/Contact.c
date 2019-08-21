#include"Contact.h"

//void InitContact(contact* pcon)
//{
//	assert(pcon);
//	pcon->size = 0;
//	memset(pcon->data, 0, sizeof(pcon->data));
//}
void InitContact(contact* pcon)
{
	assert(pcon);
	pcon->data = (PeoInfo*)malloc(1* sizeof(PeoInfo));
	if (pcon->data == NULL)
	{
		perror("InitContact::malloc");
		exit(1);
	}
	pcon->size = 0;
	pcon->capacity = 1;
}
int CheckContact(contact* pcon)
{
	assert(pcon);
	if (pcon->size == pcon->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pcon->data, (pcon->capacity + 2) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			return 0;
		}
		else
		{
			pcon->data = ptr;
			pcon->capacity += 2;
			printf("增容成功\n");
			return 1;
		}
	}
	return 1;
}
void AddContact(contact* pcon)
{
	assert(pcon);
	if (CheckContact(pcon) == 0)
	{
		printf("增容失败！");
		exit(1);
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
void DestroyContact(contact* pcon)
{
	assert(pcon);
	pcon->size = 0;
	pcon->capacity = 0;
	free(pcon->data);
	pcon->data = NULL;
}
//void AddContact(contact* pcon)
//{
//	assert(pcon);
//	if (pcon->size == MAX)
//	{
//		printf("内存已满，请删除无用的联系人之后再加\n");
//		return;
//	}
//	else
//	{
//		printf("请输入姓名:>\n");
//		scanf("%s", pcon->data[pcon->size].name);
//		printf("请输入年龄:>\n");
//		scanf("%d", &(pcon->data[pcon->size].age));
//		printf("请输入性别:>\n");
//		scanf("%s", pcon->data[pcon->size].sex);
//		printf("请输入地址:>\n");
//		scanf("%s", pcon->data[pcon->size].addr);
//		printf("请输入电话:>\n");
//		scanf("%s", pcon->data[pcon->size].tele);
//		pcon->size++;
//		printf("添加成功\n");
//	}
//}
static int FindContact(const contact* pcon,char name[])//只有内部可以看到
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
void ShowContact(const contact* pcon)
{
	assert(pcon);
	if (pcon->size == 0)
		return;
	int i = 0;
	printf("%10s\t%5s\t%5s\t%15s\t%15s\t\n", "姓名", "年龄", "性别", "地址", "电话");
	for (i = 0; i < pcon->size; i++)
	{
		printf("%10s\t%5d\t%5s\t%15s\t%15s\t\n",
			pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex,
			pcon->data[i].addr,
			pcon->data[i].tele);
	}
}
void SearchContact(const contact* pcon)
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
	int i = 0;
	int j = 0;
	PeoInfo tmp;
	for (i = 0; i < pcon->size-1; i++)
	{
		for (j = 0; j < pcon->size - i - 1; j++)
		{
			if (strcmp(pcon->data[j].name, pcon->data[j + 1].name) > 0)
			{
				tmp = pcon->data[j];
				pcon->data[j] = pcon->data[j + 1];
				pcon->data[j+1] = tmp;
			}
		}
	}
	printf("排序成功\n");
}

