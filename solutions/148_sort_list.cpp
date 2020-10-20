//https://leetcode.com/problems/sort-list/

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
    void split(ListNode *start,ListNode **a,ListNode **b){
        ListNode *slow=start,*fast=start->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
        *a=start;
        *b=slow->next;
        slow->next=NULL;
    }
    ListNode *sorted_merge(ListNode *a,ListNode *b){
        if(a==NULL)
            return b;
        else if(b==NULL)
            return a;
        ListNode *result;
        if(a->val<=b->val){
            result=a;
            result->next=sorted_merge(a->next,b);
        }
        else{
            result=b;
            result->next=sorted_merge(a,b->next);
        }
        return result;
    }
    void mergesort_list(ListNode ** head){
        ListNode *start=*head;
        if(start==NULL || start->next==NULL)
            return;
        ListNode *a,*b;
        split(start,&a,&b);
        mergesort_list(&a);
        mergesort_list(&b);
        *head=sorted_merge(a,b);
    }
    
    ListNode* sortList(ListNode* head) {
        mergesort_list(&head);
        return head;
    }
};