//T.C : O(n/2)
//S.C : O(1)
// User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        Node* fast=head,*slow=head;
       while(fast!=NULL && fast->next!=NULL){
           fast=fast->next->next;
           slow=slow->next;
           if(fast==slow){
               return true;
           }
       }
       return false;
    }
};
