/**
 * Definition for singly-linked list.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = nullptr;
        ListNode *padd = l1, *qadd = l2, *p = res;
        int carryFlag = 0;
        while (padd != nullptr && qadd != nullptr) {
            int curRes = padd->val + qadd->val + carryFlag;
            carryFlag = curRes / 10;
            curRes = curRes % 10;
            if (p == nullptr) {
                p = new ListNode();
                p->val = curRes;
                res = p;
            }
            else {
                p->next = new ListNode(curRes);
                p = p->next;
            }
            padd = padd->next, qadd = qadd->next;
        }
        while (padd != nullptr) {
            int curRes = padd->val + carryFlag;
            carryFlag = curRes / 10;
            curRes = curRes % 10;
            p->next = new ListNode(curRes);
            padd = padd->next, p = p->next;
        }
        while (qadd != nullptr) {
            int curRes = qadd->val + carryFlag;
            carryFlag = curRes / 10;
            curRes = curRes % 10;
            p->next = new ListNode(curRes);
            qadd = qadd->next, p = p->next;
        }
        if (carryFlag != 0) {
            p->next = new ListNode(carryFlag);
        }
        return res;
    }

    void printResOfAddTwoNumbers(ListNode* l) {
        ListNode *p = l;
        int res = 0;
        while (p != nullptr) {
            res = res*10 + p->val;
            p = p->next;
        }
        cout << res << endl;
        return;
    }

    ListNode* buildNumber(int x) {
        ListNode* num = new ListNode(x % 10);
        ListNode *p = num;
        x /= 10;
        while (x != 0) {
            p->next = new ListNode(x % 10);
            p = p->next;
            x /= 10;
        }
        return num;
    }
};

int main() {
    int a, b;
    cin >> a >> b;
    Solution s;
    ListNode *aadd = s.buildNumber(a);
    ListNode *badd = s.buildNumber(b);
    cout << "first number is : ";
    s.printResOfAddTwoNumbers(aadd);
    cout << "second number is : ";
    s.printResOfAddTwoNumbers(badd);
    cout << "res is : ";
    s.printResOfAddTwoNumbers(s.addTwoNumbers(aadd, badd));
    
    return 0;
}