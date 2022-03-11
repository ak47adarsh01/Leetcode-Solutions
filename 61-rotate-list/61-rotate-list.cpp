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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)   //if list has one or no nodes
            return head;
        ListNode *end=head;
        int count=1,n;
        while(end->next!=NULL)  //loop for finding the length and end of list 
        {
            count++;
            end=end->next;
        }
        end->next=head;       //since k is greater than zero 1 rotation will surely be there thus connecting end to head
        int rotate=(k%count);      //number of rotations required
        n=(count-rotate)-1;        //n is the number of nexts from head which will be the new end after rotation
        while(n>0)                       
        {
            head=head->next;
            n--;
        }
        end=head;                    
        head=head->next;      
        end->next=NULL;
        
        return head;
    }
};