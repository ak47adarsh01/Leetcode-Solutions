/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // edge case: empty list
        if (!head) return NULL;
        // support variables
        Node *tmp = head, *newHead, *newTmp;
        // creating all the next nodes
        while (tmp) {
            // creating a new node
            newTmp = new Node(tmp->val);
            // splicing newTmp
            newTmp->next = tmp->next;
            tmp->next = newTmp;
            // advancing tmp
            tmp = newTmp->next;
        }
        // assigning all the random nodes
        tmp = head;
        while (tmp) {
            // connecting random nodes
            tmp->next->random = tmp->random ? tmp->random->next : NULL;
            // advancing tmp
            tmp = tmp->next->next;
        }
        // splitting the lists
        tmp = head;
        newHead = head->next;
        while (tmp) {
            // storing the new node
			newTmp = tmp->next;
            // restoring original list to be only made of original nodes
            tmp->next = tmp->next->next;
            if (newTmp->next) newTmp->next = newTmp->next->next;
            // advancing tmp
            tmp = tmp->next;
        }
        return newHead;
    }
};