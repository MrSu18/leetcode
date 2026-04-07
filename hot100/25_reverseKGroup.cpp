#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        int list_len = 0;
        ListNode* count = head;
        while (count)
        {
            list_len++;
            count=count->next;
        }
        
        ListNode dummy(0,head);
        ListNode* p0 = &dummy;
        ListNode* pre = nullptr;
        ListNode* cur = head;

        //k个一组处理
        for (; list_len >= k; list_len-=k)
        {
            for (size_t i = 0; i < k; i++)
            {
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur; //这个是把pre移到cur的位置，而不是改变指向,或者说是把cur的地址给pre，而之前cur->next的地址变成了之前pre的地址
                cur = nxt;
            }
            
            //把P0指向pre然后把P0的next指向cur
            ListNode* nxt = p0->next;//记录p0的next的地址
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
        }
        return dummy.next;
    }
};



class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 统计节点个数
        int n = 0;
        for (ListNode* cur = head; cur; cur = cur->next) {
            n++;
        }

        ListNode dummy(0, head);
        ListNode* p0 = &dummy;
        ListNode* pre = nullptr;
        ListNode* cur = head;

        // k 个一组处理
        for (; n >= k; n -= k) {
            for (int i = 0; i < k; i++) { // 同 92 题
                ListNode* nxt = cur->next;
                cur->next = pre; // 每次循环只修改一个 next，方便大家理解
                pre = cur;
                cur = nxt;
            }

            // 见视频
            ListNode* nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
        }
        return dummy.next;
    }
};

