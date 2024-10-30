//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        Node* temp=new Node();
        temp->data=x;
        temp->next=NULL,temp->prev=NULL;
        if(head==NULL || head->data>=x){
            temp->next=head;
            if(head!=NULL){
                head->prev=temp;
            }
            return temp;
        }
        Node* curr=head;
        while(curr->next!=NULL && curr->next->data<x){
            curr=curr->next;
        }
        temp->next=curr->next;
        if(curr->next!=NULL){
            curr->next->prev=temp;
        }
        curr->next=temp;
        temp->prev=curr;
        return head;
    }
};
