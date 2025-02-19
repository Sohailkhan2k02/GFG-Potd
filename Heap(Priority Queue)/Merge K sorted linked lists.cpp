//T.C : O(n*logk)
//S.C : O(n)
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        Node *dummy = new Node(-1);
        Node *temp = dummy;
        
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> minHeap;
        for(auto node: arr){
            minHeap.push({node->data, node});
        }

        while(!minHeap.empty()){
            Node* node = minHeap.top().second;
            minHeap.pop();
            temp->next = node;
            temp = temp->next;
            if(node->next != NULL) minHeap.push({node->next->data, node->next});
        }
        return dummy->next;
    }
};
