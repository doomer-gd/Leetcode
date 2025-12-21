struct ListNode
{
	int val;
	struct ListNode *next;
};

#include <stdlib.h>

struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode*	old;
	struct ListNode*	new;

	if (head == NULL)
		return head;
	old = NULL;
	while (head->next != NULL)
	{
		new = head->next;
		head->next = old;
		old = head;
		head = new;
	}
	head->next = old;
	return head;
}