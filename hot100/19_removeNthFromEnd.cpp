#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        /* 使用dummy节点的几个好处
        * 手动增长了链表，因为n是<=size的，如果当n=size的时候，不用考虑right==NULL，否则的话执行right->next的时候会出错
        * 总的来说，涉及到需要删除头节点的题目，添加哨兵节点可以简化代码逻辑
        * 主要是为了统一操作：找到待删除节点的前驱节点 prev，然后执行 prev->next = prev->next->next。
        * 若无 dummy，你需要额外的 if分支来判断删除的是否是头节点，并分别处理指针修改和新的头节点返回。
        */
        ListNode dummy(0,head); 
        ListNode* left=&dummy;
        ListNode* right=&dummy;
        while (n--) //题目中说明了1<=n<=size
        {
            right=right->next;
        }
        while(right->next)
        {
            left=left->next;
            right=right->next;
        }
        //当right的下一个是空的时候，说明left.next走到了要删除的节点的地方
        ListNode* nxt = left->next;//保留要删除节点的地址
        left->next = left->next->next;//修改链表结构
        delete nxt;//内存上删除节点
        return dummy.next;
    }
};