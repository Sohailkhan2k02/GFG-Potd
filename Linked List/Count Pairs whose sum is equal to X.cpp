//T.C : O(n)
//S.C : O(n)
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        unordered_set<int> s;
        int cnt=0;
        Node *temp = head1;
        while(temp){
            s.insert(temp->data);
            temp=temp->next;
        }
        Node *temp1 = head2;
        while(temp1){
            if(s.find(x-temp1->data)!=s.end()){
                cnt++;
            }
            temp1=temp1->next;
        }
        return cnt;
    }
};
