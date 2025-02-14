//T.C : O(n)
//S.C : O(n)
/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root,vector<int> &actual_inor){
        if(!root)   
            return;
        inorder(root->left,actual_inor);
        actual_inor.push_back(root->data);
        inorder(root->right,actual_inor);
        return;
        
    }
    void expect(vector<int> &expected_inor,vector<int> &actual_inor){
        int n=actual_inor.size();
        for(int i=0;i<n;i++){
            expected_inor.push_back(actual_inor[i]);
        }
        sort(expected_inor.begin(),expected_inor.end());
        return;
        
    }
    
    void correctBST(Node* &root,int &num1,int &num2){
        if(!root)
            return;
        correctBST(root->left,num1,num2);
        if(root->data == num1){
            root->data = num2;
        }
        else if(root->data == num2){
            root->data = num1;
        }
        correctBST(root->right,num1,num2);
        return;    
    }
  
    void correctBST(Node* root) {
        // add code here.
        vector<int> actual_inor;
        inorder(root,actual_inor);
        
        vector<int> expected_inor;
        expect(expected_inor,actual_inor);
        
        int num1=-1;
        int num2=-1;
        
        int n=expected_inor.size();
        for(int i=0;i<n;i++){
            if(expected_inor[i]!=actual_inor[i]){
                    num1=expected_inor[i];
                    num2=actual_inor[i];
                    break;
            }
            
        }
        
        correctBST(root,num1,num2);
        return;
    
    }
};
