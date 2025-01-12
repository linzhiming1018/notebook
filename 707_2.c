#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct Node
{
    int val;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct
{
    int size;
    Node *dummyNode;
} MyLinkedList;

MyLinkedList *myLinkedListCreate()
{
    MyLinkedList *myLinkedList = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    myLinkedList->size = 0;
    myLinkedList->dummyNode = (Node *)malloc(sizeof(Node));
    myLinkedList->dummyNode->prev = myLinkedList->dummyNode;
    myLinkedList->dummyNode->next = myLinkedList->dummyNode;
    return myLinkedList;
}

int myLinkedListGet(MyLinkedList *obj, int index)
{
    if (index < 0 || index >= obj->size)
    {
        return -1;
    }
    Node *node = obj->dummyNode;
    if (index < obj->size / 2)
    {
        for (int i = 0; i <= index; i++)
            node = node->next;
    }
    else
    {
        for (int i = 0; i < obj->size - index; i++)
            node = node->prev;
    }
    return node->val;
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->prev = obj->dummyNode;
    node->next = obj->dummyNode->next;
    obj->dummyNode->next->prev = node;
    obj->dummyNode->next = node;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->prev = obj->dummyNode->prev;
    node->next = obj->dummyNode;
    obj->dummyNode->prev->next = node;
    obj->dummyNode->prev = node;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    if (index < 0 || index > obj->size)
        return;
    Node *p = obj->dummyNode;
    if (index < obj->size / 2)
    {
        for (int i = 0; i <= index; i++)
            p = p->next;
    }
    else
    {
        for (int i = 0; i < obj->size - index; i++)
            p = p->prev;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->prev = p->prev;
    node->next = p;
    p->prev->next = node;
    p->prev = node;
    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    if (index < 0 || index >= obj->size)
        return;
    Node *p = obj->dummyNode;
    if (index < obj->size / 2)
    {
        for (int i = 0; i <= index; i++)
            p = p->next;
    }
    else
    {
        for (int i = 0; i < obj->size - index; i++)
            p = p->prev;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    obj->size--;
}

void myLinkedListFree(MyLinkedList *obj)
{
    Node *cur = obj->dummyNode->next;
    while (cur != obj->dummyNode)
    {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    free(obj->dummyNode);
    free(obj);
}

void testMyLinkedList()
{
    MyLinkedList *obj = myLinkedListCreate();

    // Test adding at head
    myLinkedListAddAtHead(obj, 1);
    assert(obj->size == 1);               // Size should be 1
    assert(myLinkedListGet(obj, 0) == 1); // Should return 1

    // Test adding at tail
    myLinkedListAddAtTail(obj, 2);
    assert(obj->size == 2);               // Size should be 2
    assert(myLinkedListGet(obj, 0) == 1); // Should return 1
    assert(myLinkedListGet(obj, 1) == 2); // Should return 2

    // Test adding at index
    myLinkedListAddAtIndex(obj, 1, 3);    // List is now 1 -> 3 -> 2
    assert(obj->size == 3);               // Size should be 3
    assert(myLinkedListGet(obj, 0) == 1); // Should return 1
    assert(myLinkedListGet(obj, 1) == 3); // Should return 3
    assert(myLinkedListGet(obj, 2) == 2); // Should return 2

    // Test getting out of bounds
    assert(myLinkedListGet(obj, -1) == -1); // Should return -1
    assert(myLinkedListGet(obj, 3) == -1);  // Should return -1

    // Test deleting at index
    myLinkedListDeleteAtIndex(obj, 1);    // List is now 1 -> 2
    assert(obj->size == 2);               // Size should be 2
    assert(myLinkedListGet(obj, 0) == 1); // Should return 1
    assert(myLinkedListGet(obj, 1) == 2); // Should return 2

    // Test deleting head
    myLinkedListDeleteAtIndex(obj, 0);    // List is now 2
    assert(obj->size == 1);               // Size should be 1
    assert(myLinkedListGet(obj, 0) == 2); // Should return 2

    // Test deleting last element
    myLinkedListDeleteAtIndex(obj, 0);     // List is now empty
    assert(obj->size == 0);                // Size should be 0
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