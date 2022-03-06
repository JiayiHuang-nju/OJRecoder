/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getListLength(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while (p != nullptr) {
            len++;
            p = p->next;
        }
        return len;
    }

    ListNode* getListTail(ListNode *head) {
        ListNode *p = head;
        while (p != nullptr && p->next != nullptr) p = p->next;
        return p;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        int len = getListLength(head);
        k = k % len;
        if (k == 0) return head;
        k = len - k;
        ListNode *p = head;
        for (int i = 1; i < k; i++) p = p->next;
        ListNode *newHead = p->next, *tail = getListTail(p);
        p->next = nullptr;
        tail->next = head;
        return newHead;
    }
};

int main() {
    ListNode *head = nullptr, *tail = head;
    int num, k;
    cin >> num;
    while (num != -1) {
        ListNode *p = new ListNode(num);
        if (head == nullptr) head = p, tail = head;
        else {
            tail->next = p;
            tail = p;
        }
        cin >> num;
    }
    cin >> k;
    Solution s;
    head = s.rotateRight(head, k);
    ListNode *p = head;
    cout << "RESULT : ";
    while (p != nullptr) {
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
    return 0;
}