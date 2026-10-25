
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Merge two sorted lists
ListNode* mergeLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Returns the last node of the first half
ListNode* getMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* sortList(ListNode* head) {
    // Base case: 0 or 1 node is already sorted
    if (!head || !head->next) return head;

    // 1. Split into two halves
    ListNode* mid = getMiddle(head);
    ListNode* right = mid->next;
    mid->next = nullptr;

    // 2. Sort each half
    ListNode* leftSorted = sortList(head);
    ListNode* rightSorted = sortList(right);

    // 3. Merge
    return mergeLists(leftSorted, rightSorted);
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ListNode* node = new ListNode(x);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    head = sortList(head);
    printList(head);

    // Free memory
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
    return 0;
}