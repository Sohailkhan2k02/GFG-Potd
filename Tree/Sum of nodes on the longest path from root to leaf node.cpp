//T.C : O(n)
//S.C : O(n)
class Solution
{
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        if(root==NULL){
            return 0;
        }
        int sum=INT_MIN;
        int steps=0;
        queue<pair<Node*, pair<int,int>>> q;
        q.push({root,{root->data,1}});
        while(!q.empty()){
            Node* node=q.front().first;
            int val=q.front().second.first;
            int level=q.front().second.second;
            q.pop();
            
            if(node->left==NULL && node->right==NULL){
                if(level>steps || level==steps && val>sum){
                    steps=level;
                    sum=val;
                }
            }
            else{
                if(node->left){
                    q.push({node->left,{val+node->left->data,level+1}});
                }
                if(node->right){
                    q.push({node->right,{val+node->right->data,level+1}});
                }
            }
        }
        return sum;
        
    }
};
