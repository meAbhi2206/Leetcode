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
    ListNode* constructLL(vector<int>& arr) {
        if (arr.empty())
            return nullptr;

        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;
        for (int i = 1; i < arr.size(); i++) {
            mover->next = new ListNode(arr[i]);
            mover = mover->next;
        }
        return head;
    }

    ListNode* sortList(ListNode* head) {
         if (head == nullptr) return nullptr; 
        
        vector<int> arr;
        ListNode* temp = head;
        while (temp != nullptr) {
            arr.push_back(temp->val); 
            temp = temp->next;
        }

        sort(arr.begin(), arr.end()); 

        return constructLL(arr); 
    }
};