//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    bool compute(Node* head) {
        // Your code goes here
        string s="";
        Node* temp=head;
        while(temp!=NULL){
            s+=temp->data;
            temp=temp->next;
        }
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
};
