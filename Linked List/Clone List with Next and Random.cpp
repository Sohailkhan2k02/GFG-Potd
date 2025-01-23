//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        unordered_map<Node*,Node*>m;
        Node* temp=head;
        while(temp){
            Node* node=new Node(temp->data);
            m[temp]=node;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            m[temp]->next=m[temp->next];
            m[temp]->random=m[temp->random];
            temp=temp->next;
        }
        
        return m[head];
    }
};
