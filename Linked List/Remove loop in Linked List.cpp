//T.C : O(n)
//S.C : O(n)
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        Node *temp=head;
        unordered_map<Node*,int>mp;
        Node *curr=NULL;
        while(temp!=NULL){
            if(mp[temp]==true){
                curr->next=NULL;
                return;
            }
            mp[temp]=true;
            curr=temp;
            temp=temp->next;
        }
    }
};
