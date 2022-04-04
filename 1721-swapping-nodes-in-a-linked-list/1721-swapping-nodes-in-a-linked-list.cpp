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
    int length(ListNode* head) { // to find the length of linked list
        int count = 0;
        while (head){
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        
        int val1, val2, i=0, sz = length(head);
        
        if (sz == 1)
            return head;
        
        k--; // for making it 1 based indexing to 0 based indexing (for easy understanding)
        
        if (k==(sz/2) and sz%2) // if its exactly middle element in the list, then return head coz no need of swapping
            return head;
         
        ListNode* curr = head;
        ListNode *cur1, *cur2;
        
        while(curr){
            if (i==k) {  // 1st node to swap
                val1 = curr->val;
                cur1 = curr;
            }
            else if (i==(sz-k-1)){ // 2nd node to swap
                val2 = curr->val;
                cur2 = curr;
            }
            
            curr = curr->next;
            i++;
        }
        
        cur1->val = val2; // exchanging the values with each other 
        cur2->val = val1;
        
        return head;
    }
};