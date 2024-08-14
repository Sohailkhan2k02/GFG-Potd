//T.C : O(N)
//S.C : O(1)
class Solution {
  public:
    Node* reverse(Node* head){
        Node* prev=NULL,*curr=head;
        while(curr){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node* rev=reverse(head);
        Node* temp=rev;
        int carry=1;
        while(temp){
            int sum=temp->data+carry;
            temp->data=sum%10;
            carry=sum/10;
            
            if(temp->next==NULL && carry>0){
                temp->next=new Node(carry);
                carry=0;
            }
            
            temp=temp->next;
        }
        
        return reverse(rev);
    }
};
