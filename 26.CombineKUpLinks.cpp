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
#include<vector>
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
    vector<ListNode*> cutList(vector<ListNode*>& lists, int begin, int end) {
        vector<ListNode*> result;
        result.assign(lists.begin() + begin, lists.begin() + end);
        return result;
    }

    void printList(ListNode *head) {
        ListNode *p = head;
        while (p != nullptr){
            cout << p->val <<' ';
            p = p->next;
        }
        return;
    }

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        cout << "In mergeTwoLists: a = ";
        printList(a);
        cout << ", b = ";
        printList(b);
        cout << endl;
        if (a == nullptr) return b;
        else if (b == nullptr) return a;
        ListNode head, *tail = &head, *pa = a, *pb = b;
        while (pa != nullptr && pb != nullptr) {
            if (pa->val < pb ->val) {
                cout << "pa = " << pa->val << ' ';
                tail->next = pa;
                tail = tail->next;
                pa = pa->next;
            }
            else {
                cout << "pb = " << pb->val << ' ';
                tail->next = pb;
                tail = tail->next;
                pb = pb->next;
            }
        }
        // while (pa != nullptr) {
        //     tail->next = pa;
        //     pa = pa->next;
        // }
        // while (pb != nullptr) {
        //     tail->next = pb;
        //     pb = pb->next;
        // }
        tail->next = pa ? pa : pb;
        cout << "merge result : ";
        printList(head.next);
        cout << endl;
        return head.next;
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        cout << "l = " << l << ", r = " << r << endl; 
        if (l == r) return lists[l];
        else if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        cout << "mid = " << mid << endl;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }
};

int main() {
    vector<ListNode*> lists;
    int num = 0;
    ListNode *head = nullptr, *tail = head;
    while (num != -1) {
        cin >> num;
        if (num == -2) {
            lists.push_back(head);
            head = nullptr, tail = head;
            continue;
        }
        ListNode *p = new ListNode(num, nullptr);
        if (head == nullptr) {
            head = p;
            tail = p;
        }
        else {
            tail->next = p;
            tail = p;
        }
    }
    Solution s;
    head = s.mergeKLists(lists);
    cout << "RESULT : ";
    while (head != nullptr) {
        ListNode *p = head;
        head = head->next;
        cout << p->val << ' ';
        delete(p);
    }
    cout << endl;
    return 0;
}