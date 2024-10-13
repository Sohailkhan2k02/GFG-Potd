//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    void deleteAlt(struct Node *head) {
        // Code here
        if(head==NULL || head->next==NULL) return;
        Node* temp=head;
        while(temp && temp->next){
            Node* t=temp->next;
            temp->next=temp->next->next;
            t->next=NULL;
            delete(t);
            temp=temp->next;
        }
    }
};
