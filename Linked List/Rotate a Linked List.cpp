//APPROACH -1 
// BRUTE FORCE O(n)
//S.C : O(n)
class Solution {
  public:
    Node* rotate(Node* head, int k) {
            //Your code here
        if(head==NULL) return head;
            vector<int>v;
            Node* temp=head;
            int n=0;
            while(temp!=NULL){
                v.push_back(temp->data);
                n++;
                temp=temp->next;
            }
            if(k==0) return head;
            k=k%n;
            reverse(v.begin(),v.begin()+k);
            reverse(v.begin()+k,v.end());
            reverse(v.begin(),v.end());
            
            Node* res=new Node(v[0]);
            Node* t=res;
            for(int i=1; i<v.size(); i++){
                t->next=new Node(v[i]);
                t=t->next;
            }
            return res;
    }  
};

//APPROACH -2
//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    Node* rotate(Node* head, int k) {
      Node* prev=head,*next=head->next;
        for(int i=1;i<=k-1;i++)
        {
            prev=next;
            next=next->next;
        }
        prev->next=NULL;         
        if (next==NULL) return head;
        Node* newHead=next;
        while(next->next!=NULL)
        {
            next=next->next;
        }
        next->next=head;
        return newHead;
    }
};
