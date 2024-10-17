//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        if(head==NULL) return {};
        Node* odd=head,*even=head->next,*evenhead=even,*oddhead=odd;
        while(even && even->next){
            odd->next=odd->next->next;
            odd=odd->next;
            even->next=even->next->next;
            even=even->next;
        }
        odd->next=NULL;
        return {oddhead,evenhead};
    }
};
