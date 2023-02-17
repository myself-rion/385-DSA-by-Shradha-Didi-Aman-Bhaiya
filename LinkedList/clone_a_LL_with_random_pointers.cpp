class Solution{
private:
   void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        // Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        // insert nodes of Clone List in between originalList
      Node* originalN= head;
      Node* cloneN= cloneHead;
      Node* next= NULL;
      while(originalN!= NULL && cloneN!=NULL){
          next= originalN->next;
          originalN->next= cloneN;
          originalN= next;
          
          next= cloneN->next;
          cloneN->next= originalN;
          cloneN= next;
          
      }
      
      //Copy random pointer
      Node* curr= head;
      while(curr!=NULL)
      {
          if(curr->next!=NULL)
          {
              if(curr->random!=NULL){
          curr->next->random= curr->random->next;
              }
              else{
                  curr->next->random= curr->random;
              }
            }
            curr= curr->next->next;
      }
      //revert changes
      originalN= head;
      cloneN= cloneHead;
      while(originalN!= NULL && cloneN!=NULL){
         originalN-> next = cloneN-> next;
            originalN = originalN -> next;
            
            
            if(originalN != NULL ){
                 cloneN -> next = originalN -> next;
             }
             cloneN= cloneN ->next;
      }
      
        return cloneHead;
    }
};