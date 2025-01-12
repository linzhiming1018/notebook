#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList1(struct ListNode *head)
{
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    while (cur != NULL)
    {
        struct ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

// Equivalent recursive solution
struct ListNode *reverse(struct ListNode *pre, struct ListNode *cur)
{
    if (cur == NULL)
        return pre;
    struct ListNode *tmp = cur->next;
    cur->next = pre;
    return reverse(cur, tmp);
}

struct ListNode *reverseList2(struct ListNode *head)
{
    return reverse(NULL, head);
}