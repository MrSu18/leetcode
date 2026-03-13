#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)//环中相遇
            {
                while(slow!=head)//同时，slow走a步会到环开始的地方
                {
                    slow=slow->next;
                    head=head->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
