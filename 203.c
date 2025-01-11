#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// Function to remove elements without using a dummy head
struct ListNode *removeElements1(struct ListNode *head, int val)
{
    struct ListNode *pre = NULL;
    struct ListNode *cur = head;
    while (cur != NULL)
    {
        if (cur->val == val && pre == NULL)
        {
            struct ListNode *oldHead = head;
            head = head->next;
            cur = head;
            free(oldHead);
        }
        else if (cur->val == val && pre != NULL)
        {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
}

// Function to remove elements using a dummy head
struct ListNode *removeElements2(struct ListNode *head, int val)
{
    struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode *pre = dummyHead;
    struct ListNode *cur = head;
    while (cur != NULL)
    {
        if (cur->val == val)
        {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    head = dummyHead->next;
    free(dummyHead);
    return head;
}

void printAllNodes(struct ListNode *head)
{
    if (head == NULL)
    {
        printf("Empty!\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode *newNode(int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main()
{
    struct ListNode *head = newNode(7);
    head->next = newNode(7);
    head->next->next = newNode(7);
    head->next->next->next = newNode(7);
    printAllNodes(head);
    head = removeElements2(head, 7);
    printAllNodes(head);
    return 0;
}