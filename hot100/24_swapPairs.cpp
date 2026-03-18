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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode dummy(0,head);
        ListNode* node0 = &dummy;
        ListNode* node1 = head;

        while(node1 && node1->next)
        {
            ListNode* node2 = node1->next;
            ListNode* node3 = node2->next;

            node0->next=node2;
            node2->next=node1;
            node1->next=node3;

            node0=node1;
            node1=node3;
        }
        
        return dummy.next;
    }
};


ListNode* creatList(vector<int> nums)
{
    ListNode dummy;
    ListNode* cur = &dummy;
    for (auto num : nums)
    {
        cur->next=new ListNode(num);
        cur = cur->next;
    }
    return dummy.next;
}

// 辅助函数：打印链表
void printList(ListNode* head) 
{
    cout << "[";
    while (head) 
    {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]" << endl;
}

void deleteList(ListNode* head)
{
    while (head)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }    
}

int main()
{
    vector<int> nums = {1,2,3,4};
    ListNode* list = creatList(nums);
    cout<<"in:"; printList(list);

    Solution test;
    test.swapPairs(list);

    deleteList(list);
    return 0;
}