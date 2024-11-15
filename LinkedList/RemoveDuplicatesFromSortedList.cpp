/********************
Given the head of a sorted linked list, 
delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Example 1:
Input: head = [1,1,2]
Output: [1,2]
  
Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]

****************************/
#include<iostream>
using namespace std;

//structure of the linked list
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:

//actual logic implemented here
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp;
        if(head==nullptr) return head;
        temp=head;
        while(temp->next!=nullptr)
        {
            if(temp->val == temp->next->val)
            {
                temp->next=temp->next->next;
            }
            else
            temp=temp->next;
        }
        return head;
    }
};
// Helper functions for testing
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution solution;
    ListNode* result = solution.deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(result);

    return 0;
}
