/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;   // will become the new head
        ListNode* curr = head;      // current node we're looking at

        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // save the next node before we lose it
            curr->next = prev;               // reverse the pointer
            prev = curr;                     // move prev forward
            curr = nextNode;                 // move curr forward
        }

        return prev; // prev is now the new head of the reversed list
    }
};