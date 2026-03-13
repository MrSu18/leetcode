#include <iostream>
#include <vector>

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
    bool isPalindrome(ListNode* head) 
    {
        // 1. 快慢指针找中点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // fast != nullptr 说明链表长度为奇数，中点跳过
        if (fast) slow = slow->next;

        // 2. 反转后半段
        ListNode* prev = nullptr;
        ListNode* cur = slow;
        while (cur) 
        {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        // 3. 双指针逐一比较
        ListNode* left = head;
        ListNode* right = prev;   // 后半段反转后的头节点
        while (right) 
        {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};