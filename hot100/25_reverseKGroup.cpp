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
        while (list_len-=k)
        {
            
        }
           
    }
};
