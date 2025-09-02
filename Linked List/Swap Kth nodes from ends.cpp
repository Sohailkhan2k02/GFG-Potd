/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        if (!head) return head;

        
        int length = 0;
        Node* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }

       
        if (k > length) return head;

       
        Node* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        
        Node* second = head;
        for (int i = 1; i < length - k + 1; i++) {
            second = second->next;
        }

       
        int tempVal = first->data;
        first->data = second->data;
        second->data = tempVal;

        return head;
    }
};
