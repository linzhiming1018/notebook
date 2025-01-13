#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    int lenA = 0, lenB = 0;
    struct ListNode *curA = headA;
    struct ListNode *curB = headB;
    while (curA != NULL)
    {
        lenA++;
        curA = curA->next;
    }
    while (curB != NULL)
    {
        lenB++;
        curB = curB->next;
    }
    int diff = lenA - lenB;
    curA = headA;
    curB = headB;
    while (diff > 0)
    {
        curA = curA->next;
        diff--;
    }
    while (diff < 0)
    {
        curB = curB->next;
        diff++;
    }
    while (curA != NULL && curA != curB)
    {
        curA = curA->next;
        curB = curB->next;
    }
    return curA;
}