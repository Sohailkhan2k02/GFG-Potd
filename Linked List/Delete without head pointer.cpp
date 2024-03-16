//T.C : O(1)
//S.C : O(1)

class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *node)
    {
       // Your code here
       node->data=node->next->data;
       node->next=node->next->next;
    }

};
