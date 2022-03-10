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
	ListNode* deleteDuplicates(ListNode* head) {
		 ListNode *dummy=new ListNode(-1);
		 ListNode *t=dummy;
		 ListNode *curr=head;
		 while(curr){
		   //if no duplicates or next is null , add it to answer
			 if((curr->next && curr->val!=curr->next->val) || (!curr->next)){
				 t->next=curr;
				 t=t->next;
				 curr=curr->next;
			 }
			 //if duplicates exist skip that part 
			 else{
				 ListNode *temp=curr;
				 while(temp && temp->val==curr->val){
					 temp=temp->next;
				 }   
				 curr=temp;
				 //if after skipping we reach null just simply put t next as null
				 if(!curr)  
					 t->next=curr;
			 }
		 }
		return dummy->next;
	}
};