#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//反转一个单链表。
//输入: 1->2->3->4->5->NULL
//	输出 : 5->4->3->2->1->NULL
//	进阶 :
//	你可以迭代或递归地反转链表。你能否用两种方法解决这道题？


  /*Definition for singly-linked list.*/
struct ListNode 
{
      int val;
      struct ListNode *next;
};
 
typedef struct ListNode  Node;

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	Node* n1 = head;
	Node* n2 = n1->next;
	Node* n3 = n2->next;
	head->next = NULL;
	while (n2 != NULL)
	{
		n2->next = head;
		n1 = n2;
		n2 = n3;
		if (n3 != NULL)
			n3 = n3->next;
	}
	head = n1;
	return head;
}

int main()
{
	system("psude");
	return 0;
}
