/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    void traverse(Node * node , int curr , deque<int>&dq){
      if(curr == node->data){
         dq.push_back(0);
         return;
      }
      if(node->left){
      dq.push_back(1);
        traverse(node->left , curr , dq);
        if(dq.back() == 0)return;
          dq.pop_back();
      }
      if(node->right){
      dq.push_back(2);
        traverse(node->right , curr , dq);
        if(dq.back() == 0)return;
          dq.pop_back();
      }
      return;
  }
    int numberOfTurns(Node* root, int p, int q) {
        // code here
        deque<int>d1 , d2;
        traverse(root , p , d1);
        traverse(root , q , d2);
        d1.pop_back() , d2.pop_back();
        while(!d1.empty() && !d2.empty() && d1.front() == d2.front()){
            d1.pop_front() , d2.pop_front();
        }
        // if(d1.empty() || d2.empty())return -1;
        int dist1  =0 , dist2 = 0;
        int curr = 0;
        for(auto i: d1){
            if(i != curr){
                dist1++;
                curr = i;
            }
        }
        curr = 0;
        for(auto i: d2){
            if(i != curr){
                dist2++;
                curr = i;
            }
        }
return dist1 + dist2-1 ==0? -1 : dist1 + dist2 -1;
        
    }
};
