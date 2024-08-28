//T.C : O(N)
//S.C : O(1)
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        // Code here
          Node*slow=head;
      Node*fast=head;
      bool flag=false;
      while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            flag=true;
            break;
        }
      }
      
      if(flag==false)
      return 0;
      Node*temp=fast;
      int count=0;
      while(temp->next!=fast){
        count++;
        temp=temp->next;
      }
      return count+1;
    }
};
