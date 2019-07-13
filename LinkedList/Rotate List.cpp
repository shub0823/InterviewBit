/*
Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
https://www.interviewbit.com/problems/rotate-list/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 int length(ListNode *A)
{
    int len=0;
    while (A) {
        A = A->next;
        ++len;
    }
    
    return len;
}

ListNode* Solution::rotateRight(ListNode* A, int B) {

    int l = length(A);
    // this variable is used to reach to the node from start around which rotation is to be made
    int stop = 0;//from start(left) of the list
    
    if (B%l == 0)
        return A;
    else if (l > B)
        stop = l - B;
    else
        stop = l - B%l;
    
    ListNode *head = A;
    
    while (--stop)
        A = A->next;
    
    ListNode *temp, *newHead;
    temp = newHead = A->next;
    //important point to make the next of stopping node as NULL as it will be the last node in the rotated list
    A->next = NULL;
    
    while (temp->next)
        temp = temp->next;
    
    temp->next = head;
    A = newHead;
    
    return A;
    
}
