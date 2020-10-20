//https://leetcode.com/problems/rotate-list/

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
    
    int find_len(ListNode *head){
        if(head==NULL)
            return 0;
        int c=0;
        while(head!=NULL){
            c+=1;
            head=head->next;
        }
        return c;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0 || head->next==NULL){
            return head;
        }
        int n=find_len(head);
        int r=k%n;
        if(r==0){
            return head;
        }
        ListNode *p=head;
        int cnt=0;
        while(cnt<n-r-1 && p!=NULL){
            p=p->next;
            cnt+=1;
        }
        ListNode *new_head=p->next;
        p->next=NULL;
        ListNode *trav=new_head;
        while(trav->next){
            trav=trav->next;
            
        }
        trav->next=head;
        return new_head;
    }
};