// T.C: O(n)
// S.C: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp=head,*prev=head;
        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next->next;
            prev=prev->next;

            if(temp==prev){
                return true;
            }
        }
        return false;
    }
};
