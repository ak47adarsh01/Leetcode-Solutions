/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       if(!head) return false;
        int count = 0;
        while( head ){
            count++;
            if(count > 10000) break;
            head = head -> next;
        }
        return count > 10000 ? true : false;  
    }
};