struct ListNode
{
	int val;
	struct ListNode *next;
};

#include <stdlib.h>
#include <stdbool.h>

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

int pairSum(struct ListNode* head)
{
	struct ListNode*	iter = head;
	struct ListNode*	ptrMiddle = head;
	bool				isEven = true;
	int					currentSum;
	int					bestSum = -1;

	while (iter != NULL)
	{
		iter = iter->next;
		if (isEven)
			ptrMiddle = ptrMiddle->next;
		isEven ^= true;
	}
	ptrMiddle = reverseList(ptrMiddle);
	while (ptrMiddle != NULL)
	{
		currentSum = ptrMiddle->val + head->val;
		if (currentSum > bestSum)
			bestSum = currentSum;
		ptrMiddle = ptrMiddle->next;
		head = head->next;
	}
	return bestSum;
}