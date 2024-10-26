//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int count(struct Node* head, int key) {
        // add your code here
        map<int,int>mpp;
        while(head){
            mpp[head->data]++;
            head=head->next;
        }
        return mpp[key];
    }
};
