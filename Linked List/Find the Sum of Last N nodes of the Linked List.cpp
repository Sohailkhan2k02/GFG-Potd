//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    Node* rev(Node* head){
        Node* curr=head,*prev=NULL;
        while(curr){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    int sumOfLastN_Nodes(struct Node* head, int n) {
        // Code here
        head=rev(head);
        using ll=long long;
        ll sum=0;
        Node* temp=head;
        while(n--){
            sum+=temp->data;
            temp=temp->next;
        }
        return sum;
    }
};
