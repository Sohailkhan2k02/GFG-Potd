/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        unordered_map<Node*,bool>mpp;
        Node* curr1=head1;
        while(curr1){
            mpp[curr1]=true;
            curr1=curr1->next;
        }
        Node* curr2=head2;
        while(curr2){
            if(mpp.find(curr2)!=mpp.end()){
                return curr2->data;
            }
            curr2=curr2->next;
        }
        return -1;
    }
};
