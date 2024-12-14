/*****************************************************************************************
234. Palindrome Linked List
Given the head of a singly linked list, return true if it is a 
palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true
Example 2:

Input: head = [1,2]
Output: false
 
Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
  *****************************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        if(head==nullptr) return true;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=nullptr;
        ListNode* cur=slow;
        while(cur)
        {
            ListNode* NN=cur->next;
            cur->next=prev;
            prev=cur;
            cur=NN;
        }
        cur=prev;
        prev=head;
        while(cur)
        {
            if(cur->val!=prev->val){
            return false;
            }
            prev=prev->next;
            cur=cur->next;
        }
        return true;        
    }
};
