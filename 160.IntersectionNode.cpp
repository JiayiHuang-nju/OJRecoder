/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getLenOfLink(ListNode *head) {
        ListNode *p = head;
        int len = 0;
        if (p == NULL) {
            return 0;
        }
        while (p != NULL) {
            p = p->next;
            len++;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLenOfLink(headA);
        int lenB = getLenOfLink(headB);
        ListNode *pa = headA, *pb = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA-lenB; i++) pa = pa->next;
        }
        else if (lenA < lenB) {
            for (int i = 0; i < lenB-lenA; i++) pb = pb->next;
        }

        while (pa != NULL && pb != NULL) {
            if (pa == pb)
                return pa;
            else {
                pa = pa->next, pb = pb->next;
            }
        }
        return NULL;
    }
};