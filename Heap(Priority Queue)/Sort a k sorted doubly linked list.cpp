//T.C : O(n*log(k))
//S.C : O(log(k))
class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        DLLNode* dummy=new DLLNode(-1);
        DLLNode* temp=dummy;
        DLLNode* u=head;
        k=k+1;
        while(k-->0 && u!=NULL){
            pq.push(u->data);
            u=u->next;
        }
        
        while(!pq.empty()){
            int val=pq.top(); pq.pop();
            temp->next=new DLLNode(val);
            temp->next->prev=temp;
            temp=temp->next;
            
            if(u!=NULL){
                pq.push(u->data);
                u=u->next;
            }
        }
        dummy->next->prev=NULL;
        return dummy->next;
    }
};
