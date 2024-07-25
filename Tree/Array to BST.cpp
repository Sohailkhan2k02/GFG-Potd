//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
   Node* f(vector<int>&nums, int s, int e){
       if(s>e){
           return NULL;
       }
       int mid=(s+e)/2;
       Node* curr=new Node(nums[mid]);
       curr->left=f(nums,s,mid-1);
       curr->right=f(nums,mid+1,e);
       return curr;
   }
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        int s=0,e=nums.size()-1;
        return f(nums,s,e);
        
    }
};
