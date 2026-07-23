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
        priority_queue<ListNode*,vector<ListNode*>,
        decltype([](auto &a,auto &b ){
            return a->val > b->val;
        })>pq;
        for(auto &it:lists){
            if(it!=nullptr)pq.push(it);
        }    
        ListNode* ans=new ListNode();
        ListNode* tail=ans;
        //ans->next=tail;
        while(!pq.empty()){
            ListNode *node=new ListNode(pq.top()->val);
            tail->next=node;
            tail=tail->next;
            ListNode* curr=pq.top()->next;
            pq.pop();
            if(curr!=nullptr)pq.push(curr);
        }
        if(ans->next==nullptr)return nullptr;
        else return ans->next;
    }
};