//T.C : O(h1.size()+h2.size())
//S.C : O(1)
/* Link list Node
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
    Node* sortedMerge(Node* h1, Node* h2) {
        // code here
        Node* head = (h1->data<=h2->data)?h1:h2;
        Node* tail=head;
        Node* a=h1;
        Node* b=h2;
        (h1->data<=h2->data)?a=a->next:b=b->next;
        while(a!=NULL && b!= NULL){
            tail->next=(a->data<=b->data)?a:b;
            (a->data<=b->data)?a=a->next:b=b->next;
            tail=tail->next;
        }
        tail->next=(b==NULL)?a:b;
        return head;
    }
};
