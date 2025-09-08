/*
class Node {
public:
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
    Node* mergeSort(Node* head) {
        // code here
        Node* temp = head;
    int c = 0;
    while (temp != nullptr) {
        c++;
        temp = temp->next;
    }
    vector<int> arr(c);
    temp = head;
    for (int i = 0; i < c; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    temp = head;
    int j = 0;
    while (temp != nullptr) {
        temp->data = arr[j++];
        temp = temp->next;
    }
    return head;
    }
};
