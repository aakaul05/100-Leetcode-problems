#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* insertEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* mergeLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    Node* head = NULL;
    if (l1->data < l2->data) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    Node* tail = head;
    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1) tail->next = l1;
    else tail->next = l2;
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n1, n2, val;
    Node* l1 = NULL;
    Node* l2 = NULL;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        cin >> val;
        l1 = insertEnd(l1, val);
    }
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        cin >> val;
        l2 = insertEnd(l2, val);
    }
    Node* merged = mergeLists(l1, l2);
    printList(merged);
    return 0;
}
