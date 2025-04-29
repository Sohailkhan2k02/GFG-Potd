//T.C : O(n)
//S.C : O(1)
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        // Add code here
        Node* zero=new Node(-1),*zerotail=zero,*one=new Node(-1),*two=new Node(-1),*onetail=one,*twotail=two;
        Node* temp=head;
        while(temp){
            if(temp->data==0){
                zerotail->next=temp;
                zerotail=zerotail->next;
            }
            if(temp->data==1){
                onetail->next=temp;
                onetail=onetail->next;
            }
            if(temp->data==2){
                twotail->next=temp;
                twotail=twotail->next;
            }
            temp=temp->next;
        }
        zerotail->next=one->next?one->next:two->next;
        onetail->next=two->next;
        twotail->next=NULL;
        Node* res=zero->next;
        delete zero;
        delete one;
        delete two;
        return res;    
        
    }
};


