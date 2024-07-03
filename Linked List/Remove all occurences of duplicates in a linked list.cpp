//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        if(head==NULL || head->next==NULL) return head;
        
        struct Node *prev=NULL;
        struct Node *curr=head;
        Node *head1=new Node(-1);
        Node *head2=head1;
        while(curr!=NULL){
            if(prev==NULL && curr->data!=curr->next->data){
                Node *temp=new Node(curr->data);
                head1->next=temp;
                head1=temp;
            }
            else if(curr->next==NULL && curr->data!=prev->data){
                Node *temp=new Node(curr->data);
                head1->next=temp;
                head1=temp;
            }
            else if(prev!=NULL && curr->next!=NULL && curr->data!=prev->data && curr->data!=curr->next->data){
                Node *temp=new Node(curr->data);
                head1->next=temp;
                head1=temp;
            }
            prev=curr;
            curr=curr->next;
        }
        return head2->next;
    }
};
