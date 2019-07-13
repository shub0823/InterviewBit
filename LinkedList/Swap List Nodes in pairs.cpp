/*
Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *k_reverse(A, k)
{
    ListNode *p, *n, *c;
    p = NULL;
    n = NULL;
    c = A;
    int cnt=0;
    
    while (c && cnt<k) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
        
        cnt++;
    }
    
    if (n)
        A->next = reverseList(n, k);
        
    return p;
}

ListNode* Solution::swapPairs(ListNode* A) {
    
    int k=2;
    return k_reverse(A, k); 
}
