//T.C : O(n)
//S.C : O(1)
// User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
        Node * slow = head , * fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (slow != fast) return NULL;
        slow = head ;
        while (slow != fast){
            slow = slow -> next;
            fast = fast -> next ;
        }
        return fast;
    }
};
