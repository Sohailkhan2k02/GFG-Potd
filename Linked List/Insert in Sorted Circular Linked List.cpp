/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* p=head,*t=NULL;
       Node*temp=new Node(data);
       if(head==NULL){
           temp->next=temp;
           head=temp;
           return head;
       }
        while(p->data < data){
            t = p;
            p = p->next;
            if(p==head) break;
            
        }
        int f = 0;
        if(t==NULL){
            f = 1;
            t = head;
            while(t->data<=t->next->data){
                if(t->next==head) break;
                t = t->next;
            }
        }
        temp->next = t->next;
        t->next = temp;
        if(f == 1) head = temp;
        return head;
    }
};
