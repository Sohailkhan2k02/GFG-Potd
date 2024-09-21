class Solution {
  public:
    Node *copyList(Node *head) {
        if(head == NULL){
            return NULL;
        }
        unordered_map<int,Node*> mp;
        Node* result = new Node(0);
        Node* curr = head;
        Node* newCurr = result;
        while(curr != NULL){
            newCurr->next = new Node(curr->data);
            mp[curr->data] = newCurr->next;
            curr = curr->next;
            newCurr = newCurr->next;
        }
        curr = head;
        while(curr != NULL){
            int data = curr->data;
            if(curr->random != NULL){
                mp[data]->random = mp[curr->random->data];
            }
            curr = curr->next;
        }
        return result->next;
        
    }
};
