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
    ListNode* reverseLinkedList(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = head;
        ListNode* prev=NULL;
        while(newHead!=NULL){
        ListNode* front = newHead->next;
        newHead->next=prev;
        prev=newHead;
        newHead=front;
        }
        
        return prev;
    }
    bool IsPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseLinkedList(slow->next);
        ListNode* P1 = head;
        ListNode* P2 = newHead;
        while (P2 != NULL) {
            if (P1->val != P2->val) {
                reverseLinkedList(newHead);
                return false;
            }
            P1 = P1->next;
            P2 = P2->next;
        }
        reverseLinkedList(newHead);
        return true;
    }
    bool isPalindrome(ListNode* head) {
        bool ans=IsPalindrome(head);
        return ans;
    }
};