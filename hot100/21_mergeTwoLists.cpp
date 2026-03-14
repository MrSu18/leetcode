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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *l1 = list1, *l2 = list2;
        ListNode dummy(0);
        ListNode *temp_node = &dummy;
        while (l1!=nullptr && l2!=nullptr)
        {
            if (l1->val<l2->val)
            {
                temp_node->next=l1;
                l1=l1->next;
            }
            else
            {
                temp_node->next=l2;
                l2=l2->next;
            }
            temp_node=temp_node->next;
        }
        if (l1==nullptr && l2==nullptr)
        {
            ;
        }
        else if(l1==nullptr)
        {
            temp_node->next=l2;
        }
        else
        {
            temp_node->next=l1;
        }
        
        return dummy.next;
    }
};

// 简单的main函数用于测试
int main() 
{
    // 创建第一个有序链表: 1 -> 3 -> 5
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    list1->next->next->next = new ListNode(5);

    // 创建第二个有序链表: 2 -> 4 -> 6
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    // 打印合并后的链表
    std::cout << "Merged list: ";
    ListNode* current = merged;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // 释放内存（可选，用于完整性）
    while (merged != nullptr) {
        ListNode* temp = merged;
        merged = merged->next;
        delete temp;
    }

    // 注意：list1和list2的节点在合并后可能已被修改或删除，
    // 为避免重复释放，这里不单独删除list1和list2的剩余节点。
    // 在实际使用中，应根据合并函数的实现妥善管理内存。

    return 0;
}
