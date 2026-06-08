/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* rev(Node* head){
        Node* prev=NULL;
        while(head!=NULL){
            Node* temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    Node *compute(Node *head) {
        // code here
        Node* curr=rev(head);
        Node* c=curr;
        head=c;
        curr=curr->next;
        while(curr){
            if(curr->data<c->data){
                curr=curr->next;
            }
            else{
                c->next=curr;
                c=curr;
                curr=curr->next;
            }
        }
        if(c->next && c->next->data<c->data){
            c->next=NULL;
        }
        head=rev(head);
        
        return head;
        
    }
};
