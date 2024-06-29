//T.C : O(n)
//S.C : O(1)
// Function to check whether two linked lists are identical or not.
bool areIdentical(struct Node *h1, struct Node *h2) {
    // Code here
    bool fl=true;
    Node *t1=h1,*t2=h2;
    while(t1!=NULL || t2!=NULL){
        if((t1!=NULL && t2==NULL) || (t1==NULL && t2!=NULL)){
            fl=false;
            break;
        }
        if(t1->data!=t2->data){
            fl=false;
            break;
        }
        t1=t1->next,t2=t2->next;
    }
    return fl;
}
