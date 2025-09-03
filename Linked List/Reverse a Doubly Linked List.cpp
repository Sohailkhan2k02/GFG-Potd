/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node*temp=NULL, *curr=head;
        while(curr!=NULL){
            curr->prev=curr->next;
            curr->next=temp;
            temp=curr;
            curr=curr->prev;
        }
        return temp;
    }
};
