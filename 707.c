#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

typedef struct
{
    int size;
    Node *dummyHead;
} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *myLinkedList = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    myLinkedList->size = 0;
    myLinkedList->dummyHead = (Node *)malloc(sizeof(Node));
    myLinkedList->dummyHead->next = NULL;
    return myLinkedList;
}

int myLinkedListGet(MyLinkedList *obj, int index)
{
    if (index < 0 || index >= obj->size)
        return -1;
    Node *p = obj->dummyHead->next;
    for (int i = 0; i < index; i++)
        p = p->next;
    return p->val;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->next = obj->dummyHead->next;
    obj->dummyHead->next = node;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    Node *p = obj->dummyHead;
    for (int i = 0; i < obj->size; i++)
        p = p->next;
    p->next = node;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    if (index < 0 || index > obj->size)
        return;
    Node *p = obj->dummyHead;
    for (int i = 0; i < index; i++)
        p = p->next;
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->next = p->next;
    p->next = node;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    if (index < 0 || index >= obj->size)
        return;
    Node *p = obj->dummyHead;
    for (int i = 0; i < index; i++)
        p = p->next;
    Node *tmp = p->next;
    p->next = p->next->next;
    free(tmp);
    obj->size--;
}

void myLinkedListFree(MyLinkedList *obj)
{
    Node *cur = obj->dummyHead;
    while (cur != NULL)
    {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    free(obj);
}

void testMyLinkedList()
{
    MyLinkedList *obj = myLinkedListCreate();

    // Test adding at head
    myLinkedListAddAtHead(obj, 1);
    assert(myLinkedListGet(obj, 0) == 1); // Should return 1

    // Test adding at tail
    myLinkedListAddAtTail(obj, 2);
    assert(myLinkedListGet(obj, 1) == 2); // Should return 2

    // Test adding at index
    myLinkedListAddAtIndex(obj, 1, 3);    // List is now 1 -> 3 -> 2
    assert(myLinkedListGet(obj, 1) == 3); // Should return 3
    assert(myLinkedListGet(obj, 2) == 2); // Should return 2

    // Test getting out of bounds
    assert(myLinkedListGet(obj, 3) == -1); // Should return -1

    // Test deleting at index
    myLinkedListDeleteAtIndex(obj, 1);    // List is now 1 -> 2
    assert(myLinkedListGet(obj, 1) == 2); // Should return 2

    // Test deleting head
    myLinkedListDeleteAtIndex(obj, 0);    // List is now 2
    assert(myLinkedListGet(obj, 0) == 2); // Should return 2

    // Test deleting last element
    myLinkedListDeleteAtIndex(obj, 0);     // List is now empty
    assert(myLinkedListGet(obj, 0) == -1); // Should return -1

    // Free the linked list
    myLinkedListFree(obj);
}

int main()
{
    testMyLinkedList();
    printf("All tests passed!\n");
    return 0;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/