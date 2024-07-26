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

    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }

        return slow;
    }

    ListNode* Reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* front=NULL;
        while(temp!=NULL){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return ;
        }

        ListNode* mid=middle(head);
        ListNode* revHead=Reverse(mid->next);
        mid->next=NULL;

        ListNode* h1=head;
        ListNode* h2=revHead;
        ListNode* f1=NULL;
        ListNode* f2=NULL;

        while(h1!=NULL && h2!=NULL){
           f1=h1->next;
           f2=h2->next;

            h1->next=h2;
            if(f1==NULL) break;
            h2->next=f1;
            h1=f1;
            h2=f2;
        }
    }
};