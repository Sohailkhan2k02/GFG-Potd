//T.C : O(n)
//S.C : O(1)
// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    bool isPrime(int n){
        if(n<=2) return 2;
        for(int i=2; i*i<=n; i++){
            if((n%i)==0) return 0;
        }
        return 1;
    }
  
    Node *primeList(Node *head) {
        // code here
        Node* node=head;
        while(node){
            if(node->val<=2){
                node->val=2;
                node=node->next;
                continue;
            }
            if(!isPrime(node->val)){
                int data=node->val;
                int newdata=-1;
                int less=data-1;
                int more=data+1;
                bool l=1;
                while(true){
                    if(isPrime(less)){
                        break;
                    }else less-=1;
                    if(isPrime(more)){
                        l=0;
                        break;
                    }else more+=1;
                }
                if(l) node->val=less;
                else node->val=more;
            }
            node=node->next;
        }
        return head;
    }
};
