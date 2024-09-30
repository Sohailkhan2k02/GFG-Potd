//T.C : O(max(first,second));
//S.C : O(1)
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        using ll=long long;
        const int mod=1e9+7;
        ll v1=0,v2=0;
        while(first){
            v1=(v1*10+(ll)first->data)%mod;
            first=first->next;
        }
        while(second){
            v2=(v2*10+(ll)second->data)%mod;
            second=second->next;
        }
        return (v1*v2)%mod;
    }
};
