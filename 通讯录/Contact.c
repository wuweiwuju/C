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
		printf("�ڴ���������ɾ�����õ���ϵ��֮���ټ�\n");
		return;
	}
	printf("����������:>\n");
	scanf("%s", pcon->data[pcon->size].name);
	printf("����������:>\n");
	scanf("%d", &(pcon->data[pcon->size].age));
	printf("�������Ա�:>\n");
	scanf("%s", pcon->data[pcon->size].sex);
	printf("�������ַ:>\n");
	scanf("%s", pcon->data[pcon->size].addr);
	printf("������绰:>\n");
	scanf("%s", pcon->data[pcon->size].tele);
	pcon->size++;
	printf("��ӳɹ�\n");
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
		printf("û����Ҫɾ������ϵ�ˣ�\n");
		return;
	}
	int i = 0;
	int pos = 0;
	char name[NAME_MAX] = {0};
	printf("��������Ҫɾ���˵�����:>\n");
	scanf("%s", name);
	pos = FindContact(pcon,name);
	if (pos == -1)
	{
		printf("û���ҵ���Ҫɾ������\n");
		return;
	}
	for (i = pos; i < pcon->size - 1; i++)
	{
		pcon->data[i] = pcon->data[i + 1];
	}
	pcon->size--;
	printf("ɾ���ɹ���\n");
}
void ShowContact(contact* pcon)
{
	assert(pcon);
	if (pcon->size == 0)
		return;
	int i = 0;
	printf("%10s\t%5s\t%5s\t%15s\t%15s\t\n", "����", "����", "�Ա�", "��ַ", "�绰");
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
	printf("��������Ҫ���ҵ��˵�����:>\n");
	scanf("%s", name);
	pos = FindContact(pcon, name);
	if (pos == -1)
	{
		printf("û���ҵ���Ҫ�ҵ���\n");
		return;
	}
	printf("%10s\t%5s\t%5s\t%15s\t%15s\t\n", "����", "����", "�Ա�", "��ַ", "�绰");
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
	printf("��������Ҫ���ҵ��˵�����:>\n");
	scanf("%s", name);
	pos = FindContact(pcon, name);
	if (pos == -1)
	{
		printf("û���ҵ���Ҫ�ҵ���\n");
		return;
	}
	printf("�������޸ĺ������:>\n");
	scanf("%s", pcon->data[pos].name);
	printf("�������޸ĺ������:>\n");
	scanf("%d", &(pcon->data[pos].age));
	printf("�������޸ĺ���Ա�:>\n");
	scanf("%s", pcon->data[pos].sex);
	printf("�������޸ĺ�ĵ�ַ:>\n");
	scanf("%s", pcon->data[pos].addr);
	printf("�������޸ĺ�ĵ绰:>\n");
	scanf("%s", pcon->data[pos].tele);
}
void SortContact(contact* pcon)
{
	assert(pcon);
	if (pcon->size == 0)
		return;
}