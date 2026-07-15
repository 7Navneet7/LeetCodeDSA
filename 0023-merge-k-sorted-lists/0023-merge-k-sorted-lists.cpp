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
 struct Comparenode{
    bool operator()(const ListNode* a,const ListNode* b){
    return a->val > b->val; //min heap creation
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Comparenode>pq;
        for(auto node:lists){
            if(node!=nullptr)pq.push(node);
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        while(!pq.empty()){
            ListNode* smt=pq.top();
            tail->next=smt;
            tail=tail->next;
            pq.pop();
            if(smt->next!=nullptr){
                pq.push(smt->next);
            }
        }
        ListNode* res=dummy->next;
        delete dummy;
        return res;

    }
};