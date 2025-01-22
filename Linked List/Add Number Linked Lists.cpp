//T.C : O(n)
//S.C : O(1)
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node* reverse(Node* head)
    {
         Node* current = head;
         Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        if(num1 == NULL)
            return num2;
        if(num2 == NULL)
            return num1;
        
         Node *ans = new Node(-1);
         Node *curr = ans;
        int carry = 0;
        
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        while((num1 != NULL || num2 != NULL) || carry){
            int sum = carry;
            
            if(num1 != NULL){
                sum += num1->data;
                num1 = num1->next;
            }
            if(num2 != NULL){
                sum += num2->data;
                num2 = num2->next;
            }
            
            curr->next = new Node(sum%10);
            curr = curr->next;
            
            carry = sum / 10;
        }
        
        ans = reverse(ans->next);
        while(ans->data == 0 && ans->next != NULL)
            ans = ans->next;
        
        return ans;
    }
};
