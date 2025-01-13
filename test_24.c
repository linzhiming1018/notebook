// FILE: test_24.c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "24.c"

// Helper function to create a new ListNode
struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to create a linked list from an array
struct ListNode *createList(int *arr, int size)
{
    if (size == 0)
        return NULL;
    struct ListNode *head = createNode(arr[0]);
    struct ListNode *current = head;
    for (int i = 1; i < size; i++)
    {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to convert linked list to array
void listToArray(struct ListNode *head, int *arr, int size)
{
    struct ListNode *current = head;
    for (int i = 0; i < size; i++)
    {
        arr[i] = current->val;
        current = current->next;
    }
}

// Test function to test swapPairs with different test cases
void test_swapPairs()
{
    // Test case 1: Empty list
    struct ListNode *head1 = NULL;
    struct ListNode *result1 = swapPairs(head1);
    assert(result1 == NULL);

    // Test case 2: Single element list
    int arr2[] = {1};
    struct ListNode *head2 = createList(arr2, 1);
    struct ListNode *result2 = swapPairs(head2);
    int expected2[] = {1};
    int resultArr2[1];
    listToArray(result2, resultArr2, 1);
    for (int i = 0; i < 1; i++)
    {
        assert(resultArr2[i] == expected2[i]);
    }

    // Test case 3: Two element list
    int arr3[] = {1, 2};
    struct ListNode *head3 = createList(arr3, 2);
    struct ListNode *result3 = swapPairs(head3);
    int expected3[] = {2, 1};
    int resultArr3[2];
    listToArray(result3, resultArr3, 2);
    for (int i = 0; i < 2; i++)
    {
        assert(resultArr3[i] == expected3[i]);
    }

    // Test case 4: Three element list
    int arr4[] = {1, 2, 3};
    struct ListNode *head4 = createList(arr4, 3);
    struct ListNode *result4 = swapPairs(head4);
    int expected4[] = {2, 1, 3};
    int resultArr4[3];
    listToArray(result4, resultArr4, 3);
    for (int i = 0; i < 3; i++)
    {
        assert(resultArr4[i] == expected4[i]);
    }

    // Test case 5: Four element list
    int arr5[] = {1, 2, 3, 4};
    struct ListNode *head5 = createList(arr5, 4);
    struct ListNode *result5 = swapPairs(head5);
    int expected5[] = {2, 1, 4, 3};
    int resultArr5[4];
    listToArray(result5, resultArr5, 4);
    for (int i = 0; i < 4; i++)
    {
        assert(resultArr5[i] == expected5[i]);
    }

    printf("All test cases passed!\n");
}

int main()
{
    test_swapPairs();
    return 0;
}