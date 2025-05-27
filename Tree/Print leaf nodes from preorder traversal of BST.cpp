class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> res;
        stack<int> st;
        st.push(preorder[0]);
        for(int i = 1; i < n; i++){
            // Take the current node
            int currentNode = preorder[i];
            // Check if current node is greater than stack.top()
            // It means we have move to right subtree of some node
            // If we have moved to right of just node above, then it will not be leaf
            // But if we have moved to right of some parent of it, it becomes a leaf node
            if(currentNode > st.top()){
                // So for figuring out, we can check how many nodes are smaller than current node
                // If only 1 node is smaller it means the node on the top of the stack 
                // is parent to current node and current node is right child of its
                // But if smallerNodes are greater than 1, it means top node was the leaf node
                int smallerNodes = 0; 
                int leftMostNode = st.top();
                while(!st.empty() && currentNode > st.top()){
                    smallerNodes++;
                    st.pop();
                }
                // If the count of smaller nodes are greater than 1
                // we push it into res, which will store leaf nodes
                if(smallerNodes > 1){
                    res.push_back(leftMostNode);
                }
            }
            // Whether the node is greater than st.top() or not, we push it in the stack
            st.push(currentNode);
        }
        
        // We push the last node in the array, as that will be definitely the rightmost leaf node in the tree
        if(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
