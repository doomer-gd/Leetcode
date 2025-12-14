#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode*	PluckNextElement(struct ListNode** head)
{
	struct ListNode*	temp = (*head)->next;

	if ((*head)->next->next != NULL)
	{
		(*head)->next = (*head)->next->next;
		(*head) = temp->next;
	}
	else
		(*head)->next = NULL;
	return temp;
}

struct ListNode* oddEvenList(struct ListNode* head)
{
	struct ListNode*	start = head;
	struct ListNode*	evensStart;
	struct ListNode*	evensEnd;

	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	evensStart = PluckNextElement(&head);
	evensEnd = evensStart;
	while (head->next != NULL)
	{
		evensEnd->next = PluckNextElement(&head);
		evensEnd = evensEnd->next;
	}
	head->next = evensStart;
	evensEnd->next = NULL;
	return start;
}

int	main()
{
	struct ListNode	el7;
	struct ListNode	el6;
	struct ListNode	el5;
	struct ListNode	el4;
	struct ListNode	el3;
	struct ListNode	el2;
	struct ListNode	el1;
	

	el1.next = &el2;
	el2.next = &el3;
	el3.next = &el4;
	el4.next = NULL;
	el5.next = &el6;
	el6.next = &el7;
	el7.next = NULL;
	el1.val = 1;
	el2.val = 2;
	el3.val = 3;
	el4.val = 4;
	el5.val = 5;
	el6.val = 6;
	el7.val = 7;
	struct ListNode* iter;

	iter = oddEvenList(&el1);

	while (iter)
	{
		printf("%d ", iter->val);
		iter = iter->next;
	}
	printf("\n");
	return (0);
}