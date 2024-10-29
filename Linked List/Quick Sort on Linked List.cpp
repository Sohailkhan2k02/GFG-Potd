//T.C : O(n*logn)
//S.C : O(n)
class Solution {
  public:
  Node* partition(Node* head, Node* end){
        Node* pivot=head ;
        Node* curr=head->next ;
        Node* prev=head ;
        while(curr!=end->next){
            if(pivot->data>curr->data){
                swap(prev->next->data, curr->data);
                prev=prev->next ;
            }
            curr=curr->next ;
        }
        swap(prev->data, pivot->data);
        return prev ;
    }
    Node* sort(Node* head,Node* end){
        if(head==NULL || head == end) return head ;
        Node* p=partition(head,end);
        sort(head, p);
        sort(p->next, end);
        
    }
    struct Node* quickSort(struct Node* head) {
        // code here
         if(head==NULL ||head->next == NULL) return head ;
        Node* start=head;
        while(start->next!=NULL){
            start=start->next;
        }
        Node* end=start ;
        sort(head,end);
        return head;
    }
};
