//T.C : O(n)
//S.C : O(1)

struct Node *insert(struct Node *head, int data) {
    // Code hered
    Node* newNode = new Node(data);
    newNode->npx = XOR(NULL, head);
    if(head != NULL){
        head->npx = XOR(newNode, XOR(NULL, head->npx));
    }
    return newNode;
}

vector<int>getList(struct Node *head) {
    // Code here
    vector<int>result;
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
    while(curr != NULL){
        result.push_back(curr->data);
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    return result;
}
