/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/
*/

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Aproach 1 took more time and gave TLE at InterviewBit
ListNode* Solution::deleteDuplicates(ListNode* A) {

    if (!A || !A->next)
        return A;
    
    ListNode *temp_head = new ListNode(0);
    temp_head->next = A;
    ListNode *prev = temp_head;
    
    while (A) {
       //will take O(N) in case where all elements are duplicates
        while (A->next && A->val == A->next->val)
            A = A->next;
        
        if (prev->next == A)
            prev = prev->next;
        else
            prev->next = A->next;
        
        A = A->next;
    }
    
    return temp_head->next;
}

//Approach 2 slight changes, updating at the same time

ListNode *removeDuplicatesFromSortedList2(ListNode *A)
{
    ListNode *dummy = new ListNode (0);
    dummy->next = A;
    ListNode *prev = dummy;
    int dup;

    while (prev->next && prev->next->next) {
        if (prev->next->val == prev->next->next->val) {
            dup = prev->next->val;

            while (prev->next && prev->next->val == dup)
                prev->next = prev->next->next;
        }
        else
            prev = prev->next;
    }

    return dummy->next;
}
