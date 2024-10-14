//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        int cnt=0;
        Node* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
};
