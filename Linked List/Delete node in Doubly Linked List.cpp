//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
         Node* curr = head;
        if(x == 1){
            // FIRST NODE
            curr = head->next;
            head->next = NULL;
            curr->prev = NULL;
            delete head;
            head = curr;
            return head;
        }
        
        for(int i = 1; curr != NULL && i < x; i++){
            curr = curr->next;
        }
        
        if(curr->next == NULL){
            // LAST NODE DELETE KARNI HAI 
            curr->prev->next = NULL;
            curr->prev = NULL;
            delete curr;
            return head;
        }
        else{
            // MIDDLE NODE 
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
            return head;
        }
    }
};
