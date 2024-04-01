//T.C : O(nlogn)
//S.C : O(n)
class Solution {
  public:

    void inorder(Node *root, vector<int> &in) {
        if(root) {
            inorder(root->left, in);
            in.push_back(root->data);
            inorder(root->right, in);
        }
    }
    
    int merge(int low, int mid, int high, vector<int> &v) {
        int i = low, j = mid + 1, k = 0, n = high - low + 1, count = 0;
        vector<int> temp(n);
        
        while(i <= mid and j <= high) {
            if(v[i] <= v[j]) {
                temp[k++] = v[i++];
            } else {
                count += mid - i + 1;
                temp[k++] = v[j++];
            }
        }
        
        while(i <= mid)
            temp[k++] = v[i++];
            
        while(j <= high)
            temp[k++] = v[j++];
            
        for(i = low, k = 0; k < n; k++, i++)
            v[i] = temp[k];
            
        return count;
    }
    
    int mergeSort(int low, int high, vector<int> &in) {
        int count = 0;
        
        if(low < high) {
            int mid = low + (high - low) / 2;
            count += mergeSort(low, mid, in);
            count += mergeSort(mid + 1, high, in);
            count += merge(low, mid, high, in);
        }
        
        return count;
    }

    int pairsViolatingBST(int n, Node *root) {
        vector<int> in;
        inorder(root, in);
        return mergeSort(0, in.size() - 1, in);
    }
};
