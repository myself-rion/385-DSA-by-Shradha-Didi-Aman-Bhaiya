//Detecting loop in a LinkedList using FLoyd's Cycle detection Algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* slow= head;
        ListNode* fast= head;
        while(slow!= NULL && fast!=NULL && fast->next!=NULL){
           fast= fast->next->next;
           slow= slow->next;
           if (slow==fast){
               return true;
           }
        }
        return false;
    }
};