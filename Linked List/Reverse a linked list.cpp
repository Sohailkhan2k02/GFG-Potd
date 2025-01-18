//T.C : O(n)
//S.C : O(1)
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node* prev=NULL;
        Node* cur=head;
        Node* nex=head;
        
        while(nex){
            nex=nex->next;
            cur->next=prev;
            
            prev=cur;
            cur=nex;
        }
        
        return prev;
    }
};
