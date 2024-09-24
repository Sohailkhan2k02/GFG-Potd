//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    // Function to check whether the list is palindrome.
    Node* reverse(Node* head){
        Node* curr=head,*prev=NULL;
        while(curr){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(Node *head) {
        // Your code here
        Node* t=reverse(head);
        Node* u=head;
        while(u!=NULL && t!=NULL){
            if(u->data!=t->data) return false;
            u=u->next;
            t=t->next;
        }
        return true;
    }
};
