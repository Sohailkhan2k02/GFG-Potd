//T.C: O(n)
//S.C: O(h)
class Solution {
  public:
    int f(Node*ptr,int &tar,int &a){
        if(ptr==NULL) return 0;
        int aa=f(ptr->left,tar,a);
        int bb=f(ptr->right,tar,a);
        if(ptr->data==tar)
        {
            a=max({a,aa,bb});
            return -1;
        }
        else
        {
            if(aa>=0&&bb>=0) return max(aa,bb)+1;
            if(aa>bb) swap(aa,bb);
            a=max(a,bb-aa);
            return aa-1;
        }
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int a=0;
        f(root,target,a);
        return a;
    }
};
