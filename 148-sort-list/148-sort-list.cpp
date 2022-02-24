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
    ListNode *sortListQuickly(ListNode *head, ListNode *tail) {
	if(head == tail) return head;
	else if(head->next == tail) return head;
	//make a sentinel node 
	ListNode *sentinel = new ListNode(-1, head);
	//make the first element a pivot
	ListNode *pivot = head;
	ListNode *ptr = head->next;
	ListNode *preptr = head;
	bool isSorted;
	while(ptr!=tail && preptr->val <= ptr->val) {
		preptr = ptr;
		ptr = ptr->next;
	}
	if(ptr == tail) {
		//sublist is already sorted;
		return pivot;
	}
	ptr = head->next;
	preptr = head;
	while(ptr!=tail) {
		while(ptr!=tail && ptr->val >= pivot->val) {
			preptr = ptr;
			ptr = ptr->next;
		}
		if(ptr == tail) break;
		//swap this node to the front of the list
		ListNode *newptr = ptr->next;
		ptr->next = sentinel->next;
		sentinel->next = ptr;
		preptr->next = newptr;
		ptr = newptr;
	}
	ListNode *top = sentinel->next;
	delete(sentinel);
	top = sortListQuickly(top, pivot);
	pivot->next = sortListQuickly(pivot->next, tail);
	return top;
}
ListNode* sortList(ListNode* head) {
	return sortListQuickly(head, 0);
}
};