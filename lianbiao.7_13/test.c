#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//合并两个有序链表
typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
	{
		return l2;
	}
	else if (l2 == NULL)
	{
		return l1;
	}
	Node* l = NULL;
	if (l1->val > l2->val)
	{
		l = l2;
		l2 = l2->next;
	}
	else
	{
		l = l1;
		l1 = l1->next;
	}
	Node* tail = l;
	while (l1 && l2)
	{
		if (l1->val > l2->val)
		{
			tail->next = l2;
			l2 = l2->next;
		}
		else
		{
			tail->next = l1;
			l1 = l1->next;
		}
		tail = tail->next;
	}
	if (l1 == NULL)
	{
		tail->next = l2;
	}
	else
	{
		tail->next = l1;
	}
	return l;


}
