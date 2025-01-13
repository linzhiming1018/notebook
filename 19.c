#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode *fastIndex = dummy;
    for (int i = 0; i < n; i++)
        fastIndex = fastIndex->next;
    struct ListNode *slowIndex = dummy;
    while (fastIndex->next != NULL)
    {
        fastIndex = fastIndex->next;
        slowIndex = slowIndex->next;
    }

    struct ListNode *p = slowIndex->next;
    slowIndex->next = slowIndex->next->next;
    free(p);
    return dummy->next;
}