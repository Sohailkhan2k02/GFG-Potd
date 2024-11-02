//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
   bool f(Node* head){
       int cnt=0; Node* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        
        return (cnt&1)==0;
   }
    bool isLengthEven(struct Node **head) {
        // Code here
        return f(*head);
    }
};
