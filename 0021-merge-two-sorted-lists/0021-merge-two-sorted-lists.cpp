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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode();
        ListNode* tail=ans;
        priority_queue<ListNode*,vector<ListNode*>,
        decltype([](auto &a,auto &b){
            return a->val > b->val;
        })>pq;
        if(list1!=nullptr)pq.push(list1);
        if(list2!=nullptr)pq.push(list2);
        while(!pq.empty()){
            ListNode* curr=pq.top();
            tail->next=curr;
            ListNode* node=curr->next;
            curr->next=nullptr;
            pq.pop();
            if(node!=nullptr)pq.push(node);
            tail=tail->next;
        }
        
        return ans->next;
    }
};