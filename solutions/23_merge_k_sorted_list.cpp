//https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        if(lists.size()==0)
            return NULL;
        for(int i=0;i<lists.size();i++){
            ListNode *p=lists[i];
            while(p){
                pq.push(p->val);
                p=p->next;
            }
        }
        if(pq.size()==0)
            return NULL;
       ListNode* tmp=new ListNode(pq.top());
        pq.pop();
        ListNode *p=tmp;
        while(!pq.empty()){
            int tp=pq.top();
            pq.pop();
            ListNode *temp= new ListNode(tp);
            p->next=temp;
            p=p->next;
        }
        return tmp;
    }
};