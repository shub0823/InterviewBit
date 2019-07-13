/*
https://www.interviewbit.com/problems/list-cycle/
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Try solving it using constant additional space.
Example :
Input : 
                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4
Return the node corresponding to node 3. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (!A || !A->next)
        return NULL;
        
    ListNode *slow, *fast;
    slow = fast = A;
    int flag = 0;
    
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            flag = 1;
            break;
        }
        
    }
    
    if (!flag)
        return NULL;
    
    slow = A;
    
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}
