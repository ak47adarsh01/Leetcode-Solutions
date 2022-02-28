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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode *temp=head;
        while(temp)
        {
            int element=temp->val;
            while(temp->next && element==temp->next->val) //checks if node after temp is its duplicate
			//since nodes are deleted U don't need to move temp (temp=temp->next) 
            {
                ListNode* m=temp->next;
                temp->next=m->next;
                delete m;
            }
            temp=temp->next;
        }
        return head;
    }
}; 