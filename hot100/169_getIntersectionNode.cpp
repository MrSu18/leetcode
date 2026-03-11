#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//当我们无路可走时，试着走彼此的路. 如果到最后我找不到你，那么你也找不到我，我们没有缘分了

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *p = headA;
        ListNode *q = headB;

        while (p!=q)
        {
            p = p==NULL ? headB : p->next; //三目运算符，判断p是否为空，为空的话换到B上遍历，否则下一个
            q = q==NULL ? headA : q->next;
        }
        return p;
    }
};

int main()
{
    // ListNode *common = new ListNode(8);
    // common->next = new ListNode(4);
    // common->next->next = new ListNode(5);
    // common->next->next->next = NULL;
    ListNode *A = new ListNode(4);
    A->next = new ListNode(1);
    A->next->next = new ListNode(1);
    ListNode *B = new ListNode(5);
    B->next = new ListNode(6);
    B->next->next = new ListNode(1);
    B->next->next->next = new ListNode(1);

    Solution test;
    test.getIntersectionNode(A,B);
}
