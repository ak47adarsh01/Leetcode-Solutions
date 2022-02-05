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
        vector<int> v;
        if(lists.size()==0)
            return NULL;
        for(int i=0;i<lists.size();i++)
        {
            ListNode* temp=lists[i];
            while(temp!=NULL)
            {
                v.push_back(temp->val);
                temp=temp->next;
            }
        }
        if(v.size()==0)    //if there exist no node within the lists then return null.//
            return NULL;
        sort(v.begin(),v.end());
        ListNode* start=new ListNode(v[0]);
        ListNode* temp1=start;
        for(int i=1;i<v.size();i++)
        {
            temp1->next=new ListNode(v[i]);
            temp1=temp1->next;
        }
        return start;
    }
};