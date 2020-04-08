/*
*   Middle of the Linked List
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
      auto fast = head;
      auto slow = head;
      while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      return slow;
    }
};