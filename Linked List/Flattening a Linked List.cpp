/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        // code here
        while(root->next)
        {
            Node *root1 = root, *root2=root->next;
            root1->next = root2->next;
            root2->next = NULL;
            while(root1 && root2)
            {
                if(root1->bottom) {
                    if(root1->bottom->data > root2->data) {
                        Node *t=root2;
                        root2 = root2->bottom;
                        t->bottom=root1->bottom;
                        root1->bottom = t;
                        
                    } else {
                        root1 = root1->bottom;
                    }
                } else {
                    root1->bottom=root2;
                    root2 = NULL;
                }
            }
        }
        return root;
    }
};
