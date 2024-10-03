//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if (head == NULL || head->next == head) return head;
        Node* prev = NULL, *curr = head, *next = NULL, *tail = head;
        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);
        tail->next = prev;
        return prev;
    }

Node* deleteNode(Node* head, int key) {
    if (head == NULL || (head->next == head && head->data == key)) return NULL;
    if (head->data == key) {
        head->data = head->next->data;
        head->next = head->next->next;
        return head;
    }
    Node* temp = head->next, *prev = head;
    while (temp != head) {
        if (temp->data == key) {
            prev->next = temp->next;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

};
